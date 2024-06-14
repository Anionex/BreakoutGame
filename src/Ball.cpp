// src/Ball.cpp
#include "Ball.hpp"
#include "Game.hpp"
using namespace sf;
const Time Ball::reboundCoolDown = milliseconds(25);


Ball::Ball(Vector2f pos, Vector2f velocity): Ball(pos, velocity, 0)
{
}

Ball::Ball(Vector2f pos, Vector2f velocity, int hp): GameObject(pos, velocity, hp)
{

}

Ball::Ball(Vector2f pos, Vector2f velocity, int hp, const Texture& texture) : GameObject(pos, velocity, hp)
{
	ballClock.restart();
	sprite.setTexture(texture);
}

void Ball::update(float deltaTime)
{
	//std::cout << velocity.x * deltaTime << velocity.y * deltaTime << std::endl;
	
	
	velocity += accelarate * deltaTime;
	pos.x += velocity.x * deltaTime;
	pos.y += velocity.y * deltaTime;
	sprite.setPosition(pos);
}

void Ball::draw(RenderWindow& window)
{
	window.draw(sprite);
	//std::cout << pos.x << " " << pos.y << std::endl;
}

void Ball::verticalRebound()
{
	velocity.x *= -1;
}

void Ball::horizentalRebound()

{
	velocity.y *= -1;
}

bool Ball::collidWith(const GameObject& B) 
{
	if (ballClock.getElapsedTime() < reboundCoolDown) return 0;
	
	//¾ØÐÎ¸²¸Ç¼ì²â 
	if (!sprite.getGlobalBounds().intersects(B.sprite.getGlobalBounds()))return 0;
	else {
		// TODO¸ü¾«È·µÄÏñËØ¼ì²â
		std::cout << "hit" << std::endl;
		ballClock.restart();
		return 1;
	}
	return false;
}
