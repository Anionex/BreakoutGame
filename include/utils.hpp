// ʵ��һЩ���õĹ��ߺ���
#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<iostream>
#include<string>
#include"ResourceManager.hpp"
using namespace sf;
void switchToEnglishInputMethod();
#define v2f Vector2f
void showTextDefult(RenderWindow& window, ResourceManager& rm, const std::string content, int size, v2f pos);

