// include/Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
using namespace sf;
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include <vector>
#include <iostream>
#include<Windows.h>
#include <string>
#include "utils.hpp"

class Game {
    public:
        Game();
        void run();
        int score, life;
        const int totalBrick;

    private:
        void processEvents();
        void update(Time deltaTime);
        void render();

        void handlePlayerInput(Keyboard::Key key, bool isPressed);

        RenderWindow mWindow;
        Paddle mPaddle;
        Ball mBall;
        std::vector<Brick> mBricks;

        bool mIsMovingLeft;
        bool mIsMovingRight;
        Font font1;
};

#endif // GAME_HPP
