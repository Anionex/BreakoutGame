#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "utils.hpp"
using namespace sf;
#define v2f Vector2f

// 每个sfml物体继承一个基类，共有常见属性位置速度声明等
class GameObject {
public:
	GameObject();
	GameObject(Vector2f pos, Vector2f velocity);
	GameObject(Vector2f pos,  Vector2f velocity,  int hp);
	Vector2f pos, velocity;
	Sprite sprite;
	int hp;
	//此方法目前用于更新对象位置
	virtual void update(float deltaTime) = 0; 
	virtual void draw(RenderWindow& window) = 0;

	virtual bool collidWith(const GameObject& B);
};