// src/Paddle.cpp
#include "Paddle.hpp"
using namespace sf;

Paddle::Paddle() 
: mShape(Vector2f(100.0f, 20.0f))
, mSpeed(400.0f) 
{
    mShape.setFillColor(Color(0xDF,0x61,0x40)); // c
    mShape.setPosition(350.0f, 550.0f);
}

void Paddle::update(Time deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        mShape.move(-mSpeed * deltaTime.asSeconds(), 0.0f);
    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        mShape.move(mSpeed * deltaTime.asSeconds(), 0.0f);
    }
}

RectangleShape Paddle::getShape() {
    return mShape;
}
