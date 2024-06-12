#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "utils.hpp"
using namespace sf;

// ÿ��sfml����̳�һ�����࣬���г�������λ���ٶ�������
class GameObject {
public:
	GameObject(Vector2f pos, Vector2f velocity);
	GameObject(Vector2f pos, Vector2f velocity, int hp);
	Vector2f pos, velocity;
	Sprite sprite;
	int hp;
	//�˷���Ŀǰ���ڸ��¶���λ��
	virtual void update(float deltaTime) = 0; 
	virtual void draw(RenderWindow& window) = 0;

	bool collidWith(const GameObject& B);
};