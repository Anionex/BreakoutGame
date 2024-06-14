// src/Paddle.cpp
#include "Paddle.hpp"
#include "GameState.hpp"
using namespace sf;

//Paddle::Paddle() 
//: mShape(Vector2f(100.0f, 20.0f))
//, mSpeed(400.0f) 
//{
//    mShape.setFillColor(Color(0xDF,0x61,0x40)); // c
//    mShape.setPosition(350.0f, 550.0f);
//}
//
//void Paddle::update(Time deltaTime) {
//    if (Keyboard::isKeyPressed(Keyboard::A)) {
//        mShape.move(-mSpeed * deltaTime.asSeconds(), 0.0f);
//    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
//        mShape.move(mSpeed * deltaTime.asSeconds(), 0.0f);
//    }
//}


Paddle::Paddle()
{
}

Paddle::Paddle(Vector2f pos, Vector2f velocity): Paddle(pos, velocity, 0)
{
	return;
}

Paddle::Paddle(Vector2f pos, Vector2f velocity, int hp): GameObject(pos, velocity, hp)
{


}

void Paddle::update(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A)) velocity = v2f(-GameState::initPaddleV.x, -GameState::initPaddleV.y);
	else
	if (Keyboard::isKeyPressed(Keyboard::D))velocity = GameState::initPaddleV;
	else velocity = v2f(0, 0);
	
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) {
		pos.x += velocity.x * deltaTime;
		pos.y += velocity.y * deltaTime;
	}
	sprite.setPosition(pos);
}

void Paddle::draw(RenderWindow& window)
{
	window.draw(sprite);
}
