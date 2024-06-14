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
	// ���ð�ť��λ�ã��������ݣ����ִ�С�����壬������ɫ��������ɫ
	Button(v2f pos, const std::string& content, int size, const Font& font, const Color& textColor);
	void draw(RenderWindow& window);
	bool isMouseOn(RenderWindow& window);
	bool isClicked(RenderWindow& window);
	void update(RenderWindow& window);
	Clock buttonClock;
	//���°�ť���callback������һ��ָ��void������ָ��
	void (*callback)() = nullptr;



};