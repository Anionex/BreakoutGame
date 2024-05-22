// include/Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mWindow;
    Paddle mPaddle;
    Ball mBall;
    std::vector<Brick> mBricks;

    bool mIsMovingLeft;
    bool mIsMovingRight;
};

#endif // GAME_HPP
