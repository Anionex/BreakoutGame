// 实现一些常用的工具函数
#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<iostream>
#include<string>
#include"ResourceManager.hpp"
using namespace sf;
void switchToEnglishInputMethod();
#define v2f Vector2f
void drawTextDefult(RenderWindow& window, ResourceManager& rm, const std::string& content, int size, v2f pos);

int checkCollidType(FloatRect A, FloatRect B);