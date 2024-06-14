#pragma once

#include <SFML/Graphics.hpp>
#include<Menu.hpp>
#define v2f Vector2f
using namespace sf;

class Button {
public:
	Text text;
	RectangleShape backRect, shadowRect;
	Button();
	// 设置按钮的位置，文字内容，文字大小，字体，文字颜色，背景颜色
	Button(v2f pos, const std::string& content, int size, const Font& font, const Color& textColor);
	void draw(RenderWindow& window);
	bool isMouseOn(RenderWindow& window);
	bool isClicked(RenderWindow& window);
	void update(RenderWindow& window);
	Clock buttonClock;
	//按下按钮后的callback函数，一个指向void函数的指针
	void (*callback)() = nullptr;



};