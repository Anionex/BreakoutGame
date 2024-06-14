#include "GameObject.hpp"



GameObject::GameObject(Vector2f pos, Vector2f velocity, int hp)
{
	this->pos = pos; // 
	this->velocity = velocity;
	this->hp = hp;
}

bool GameObject::collidWith(const GameObject& B)
{
	//矩形覆盖检测 
	if (!sprite.getGlobalBounds().intersects(B.sprite.getGlobalBounds()))return 0; 
	else {
		// TODO更精确的像素检测
		return 1;
	}
	return false;
}

