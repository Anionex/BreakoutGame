// src/Brick.cpp
#include "Brick.hpp"

Brick::Brick(sf::Vector2f position) 
: mShape(sf::Vector2f(50.0f, 20.0f))
, mIsAlive(true) 
{
    mShape.setFillColor(sf::Color(143, 48, 10));
    mShape.setPosition(position);
}

void Brick::hit() {
    mIsAlive = false;
}

bool Brick::isAlive() const {
    return mIsAlive;
}

sf::RectangleShape Brick::getShape()const {
    return mShape;
}
