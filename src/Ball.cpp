// src/Ball.cpp
#include "Ball.hpp"
#include "Game.hpp"
using namespace sf;

//Ball::Ball() 
//: mShape(10.0f)
//, mVelocity(400.0f, 400.0f) 
//{
//    mShape.setFillColor(Color::Black);
//    mShape.setPosition(200.0f, 200.0f);
//}
//
//void Ball::update(Time deltaTime) {
//    mShape.move(mVelocity * deltaTime.asSeconds());
//
//    if (mShape.getPosition().x < 0 || mShape.getPosition().x > 790) {
//        mVelocity.x = -mVelocity.x;
//    }
//
//    if (mShape.getPosition().y < 0) {
//        mVelocity.y = -mVelocity.y;
//    }
//
//    if (mShape.getPosition().y > 600) {
//        isalive = 0;
//    }
//}
//
//void Ball::reboundPaddle() {
//    mVelocity.y = -mVelocity.y;
//}
//
//void Ball::reboundBrick() {
//    mVelocity.y = -mVelocity.y;
//}
//
//CircleShape Ball::getShape() {
//    return mShape;
//}

Ball::Ball(Vector2f pos, Vector2f velocity): Ball(pos, velocity, 0)
{
}

Ball::Ball(Vector2f pos, Vector2f velocity, int hp): GameObject(pos, velocity, hp)
{

}

Ball::Ball(Vector2f pos, Vector2f velocity, int hp, const Texture& texture) : GameObject(pos, velocity, hp)
{
	sprite.setTexture(texture);
}

void Ball::update(float deltaTime)
{
	//std::cout << velocity.x * deltaTime << velocity.y * deltaTime << std::endl;
	pos.x += velocity.x * deltaTime;
	pos.y += velocity.y * deltaTime;
	sprite.setPosition(pos);
}

void Ball::draw(RenderWindow& window)
{
	window.draw(sprite);
	std::cout << pos.x << " " << pos.y << std::endl;
}

void Ball::verticalRebound()
{
	velocity.x *= -1;
}

void Ball::horizentalRebound()
{
	velocity.y *= -1;
}

