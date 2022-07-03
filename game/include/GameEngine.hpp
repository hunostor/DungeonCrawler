#pragma once
#include <chrono>

namespace game {
    class GameEngine
    {
        public:
            int run();
        private:
            void init();

            void gameLoop();
            void handleInput();
            void update();
            void render();

            int finish();
        private:
            int x = 3;
            int y = 3;
            bool quit = false;
            bool isStateChange = true;
            std::chrono::time_point<std::chrono::system_clock> currentTime;
    };
}