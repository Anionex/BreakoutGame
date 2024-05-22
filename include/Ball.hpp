// include/Ball.hpp
#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball();
    void update(sf::Time deltaTime);
    void reboundPaddle();
    void reboundBrick();
    sf::CircleShape getShape();
    bool isalive;

private:
    sf::CircleShape mShape;
    sf::Vector2f mVelocity;
    
};

#endif // BALL_HPP
