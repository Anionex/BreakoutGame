// src/Ball.cpp
#include "Ball.hpp"

Ball::Ball() 
: mShape(10.0f)
, mVelocity(400.0f, 400.0f) 
{
    mShape.setFillColor(sf::Color::Black);
    mShape.setPosition(200.0f, 200.0f);
}

void Ball::update(sf::Time deltaTime) {
    mShape.move(mVelocity * deltaTime.asSeconds());

    if (mShape.getPosition().x < 0 || mShape.getPosition().x > 790) {
        mVelocity.x = -mVelocity.x;
    }

    if (mShape.getPosition().y < 0) {
        mVelocity.y = -mVelocity.y;
    }

    if (mShape.getPosition().y > 600) {
        isalive = 0;
    }
}

void Ball::reboundPaddle() {
    mVelocity.y = -mVelocity.y;
}

void Ball::reboundBrick() {
    mVelocity.y = -mVelocity.y;
}

sf::CircleShape Ball::getShape() {
    return mShape;
}
