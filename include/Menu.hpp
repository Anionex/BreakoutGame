// 主菜单，两个按钮让用户选择游戏模式1还是2，对应运行game的mode1和mode2
#pragma once
#include "ResourceManager.hpp"
#define  RM ResourceManager
#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include <string>
#include "ResourceManager.hpp"

class Menu {
public:
	enum Selection { None, mode1, mode2, settings };
	Menu();
	Menu(ResourceManager& resourceManager);
	Selection show(RenderWindow& Window);

private:
	void draw(RenderWindow& window);
	void processEvent(Event event, RenderWindow& window);

	Text titleText;
	std::vector<Text> menuItems;
	std::vector<RectangleShape> itemBackgrounds;
	Selection currentSelection;;
	static const Color buttonBackgoundColor;
	static const Color shadowColor;

};