// src/Brick.cpp
#include "Brick.hpp"
using namespace sf;

Brick::Brick(Vector2f position) 
: mShape(Vector2f(50.0f, 20.0f))
, mIsAlive(true) 
{
    mShape.setFillColor(Color(143, 48, 10));
    mShape.setPosition(position);
}

void Brick::hit() {
    mIsAlive = false;
}

bool Brick::isAlive() const {
    return mIsAlive;
}

RectangleShape Brick::getShape()const {
    return mShape;
}
