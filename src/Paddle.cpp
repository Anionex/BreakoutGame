// src/Paddle.cpp
#include "Paddle.hpp"

Paddle::Paddle() 
: mShape(sf::Vector2f(100.0f, 20.0f))
, mSpeed(400.0f) 
{
    mShape.setFillColor(sf::Color(15, 32, 186));
    mShape.setPosition(350.0f, 550.0f);
}

void Paddle::update(sf::Time deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mShape.move(-mSpeed * deltaTime.asSeconds(), 0.0f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mShape.move(mSpeed * deltaTime.asSeconds(), 0.0f);
    }
}

sf::RectangleShape Paddle::getShape() {
    return mShape;
}
