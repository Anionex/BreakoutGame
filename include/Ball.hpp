// include/Ball.hpp
#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball {
public:
    Ball();
    void update(Time deltaTime);
    void reboundPaddle();
    void reboundBrick();
    CircleShape getShape();
    bool isalive;

private:
    CircleShape mShape;
    Vector2f mVelocity;
    
};

#endif // BALL_HPP
