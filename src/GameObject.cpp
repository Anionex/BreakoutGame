#include "GameObject.hpp"



GameObject::GameObject(Vector2f pos, Vector2f velocity, int hp)
{
	this->pos = pos; // 
	this->velocity = velocity;
	this->hp = hp;
}

bool GameObject::collidWith(const GameObject& B)
{
	//���θ��Ǽ�� 
	if (!sprite.getGlobalBounds().intersects(B.sprite.getGlobalBounds()))return 0; 
	else {
		// TODO����ȷ�����ؼ��
		return 1;
	}
	return false;
}

