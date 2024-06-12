// src/Brick.cpp
#include "Brick.hpp"
using namespace sf;

Brick::Brick(Vector2f pos, Vector2f velocity): Brick(pos, velocity, 0)
{
	return;
}

Brick::Brick(Vector2f pos, Vector2f velocity, int hp) : GameObject(pos, velocity, hp)
{
	
}

Brick::Brick(Vector2f pos, Vector2f velocity, int hp, const Texture& texture): GameObject(pos, velocity, hp)
{
	std::cout << "texture brick" << std::endl;
	sprite.setTexture(texture);
}

void Brick::update(float deltaTime)
{
	sprite.setPosition(pos);
	// nothing to do
	return;
}

void Brick::draw(RenderWindow& window)
{
	std::cout << "draw brick" << std::endl;
	std::cout << pos.x << " " << pos.y << std::endl;
	window.draw(sprite);
}

void Brick::hit()
{
	std::cout << "be hit" << std::endl;
	if(hp > 0) hp -= 1;
}
