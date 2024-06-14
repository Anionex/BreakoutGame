// ���˵���������ť���û�ѡ����Ϸģʽ1����2����Ӧ����game��mode1��mode2
#pragma once
#include "ResourceManager.hpp"
#define  RM ResourceManager
#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include <string>
#include"Button.hpp"

class Button;
class Menu {
public:
	enum Selection { None, mode1, mode2, settings };
	Menu();
	Menu(ResourceManager& resourceManager);
	Selection show(RenderWindow& Window);
	static const Color buttonBackgoundColor;
	static const Color shadowColor;
	void setDefult();

private:
	void draw(RenderWindow& window);
	void processEvent(Event event, RenderWindow& window);

	Text titleText;
	std::vector<Button> menuItems;
	Selection currentSelection;;
	

};