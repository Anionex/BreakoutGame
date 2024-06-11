#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "utils.hpp"
using namespace sf;

// ��ÿ��sfml����ά��һ�����࣬���ڷ���������ǵ����꣬ԭ�㣬Bounds������
class Base {
	int x, y;
	int width, height;
	Vector2f origin;
	FloatRect bounds;
public:
	Base(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
		origin = Vector2f(x + width / 2, y + height / 2);
		bounds = FloatRect(x, y, width, height);
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	int getWidth() const {
		return width;
	}

	int getHeight() const {
		return height;
	}

	Vector2f getOrigin() const {
		return origin;
	}

	FloatRect getBounds() const {
		return bounds;
	}
};