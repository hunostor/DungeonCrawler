#include "GameEngine.hpp"
#include <iostream>
#include <windows.h>
#include <chrono>


namespace game
{
    #define IS_PRESSED 0x8000
    using namespace std::chrono_literals;
    constexpr std::chrono::nanoseconds timeStep(500ms);

    int GameEngine::run()
    {        
        init();
        gameLoop();
        return finish();
    }

    void GameEngine::init()
    {
        currentTime = std::chrono::high_resolution_clock::now();
    }
            
    void GameEngine::gameLoop()
    {
        std::chrono::nanoseconds lag(0ns);
        while(!quit)
        {
            auto deltaTime = std::chrono::high_resolution_clock::now() - currentTime;
            currentTime = std::chrono::high_resolution_clock::now();
            lag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);

            while(lag >= timeStep)
            {
                lag -= timeStep;
                handleInput();
                update();
                render();
            }
            
        }
    }

    void GameEngine::handleInput()
    {
        if(GetKeyState('W') & IS_PRESSED)
        {
            --y;
            isStateChange = true;
        }
        else if(GetKeyState('S') & IS_PRESSED)
        {
            ++y;
            isStateChange = true;
        }
        else if(GetKeyState('A') & IS_PRESSED)
        {
            --x;
            isStateChange = true;
        }
        else if(GetKeyState('D') & IS_PRESSED)
        {
            ++x;
            isStateChange = true;
        }
        else if(GetKeyState('Q') & IS_PRESSED)
        {
            quit = true;
        }

        // char input;
        // std::cin >> input;
        // switch (input)
        // {
        //     case 'w':
        //         --y;
        //         break;
        //     case 's':
        //         ++y;
        //         break;
        //     case 'a':
        //         --x;
        //         break;
        //     case 'd':
        //         ++x;
        //         break;
        //     case 'q':
        //         quit = true;
        //         break;        
        
        // default:
        //     break;
        // }
    }

    void GameEngine::update()
    {

    }

    void GameEngine::render()
    {
        if(!isStateChange)
        {
            return;
        }

        // Simple drawing
        system("cls");
        for(int heigth = 0; heigth < y -1; ++heigth) 
        {
            std::cout << std::endl;
        }
        for(int width = 0; width < x -1; ++width)
        {
            std::cout << " ";
        }
        std::cout << "@";
        std::cout << std::endl;
        isStateChange = false;
    }

    int GameEngine::finish()
    {
        return 0;
    }
}

