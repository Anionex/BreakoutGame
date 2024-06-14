#include "Menu.hpp"
# include<iostream>
#include<utils.hpp>
#include<SFML/Graphics.hpp>
#include "GameState.hpp"
using namespace sf;
const Color Menu::buttonBackgoundColor=Color(0xD6, 0x98, 0x39);
const Color Menu::shadowColor=Color(0, 0, 0, 150);
#define v2f Vector2f
Menu::Menu():currentSelection(None) {}

Menu::Menu(ResourceManager& resourceManager) :
	currentSelection(None), 
	titleText("Breakout Game", resourceManager.getFont("main"), 64)
{
	titleText.setFillColor(Color::Black);
	titleText.setPosition(200.f, 100.f);

	std::vector<std::string> items = { "Single Player", "Demo", "Settings" };
	float yPos = 230.f;

	for (const auto& item : items) {
		sf::Text text(item, resourceManager.getFont("main"), 48);
		text.setFillColor(Color::Black);
		text.setPosition(250.f, yPos);
		
		// 添加按钮
		Button button(v2f(GameState::windowSize.x / 2, yPos), item, 64, resourceManager.getFont("main"), Color::Black);
		menuItems.push_back(button);
		

		yPos += 100.f;
	}

}

Menu::Selection Menu::show(RenderWindow& window) {
	
	while (window.isOpen()) {
		
		window.draw(titleText);
			
		// 处理事件
		Event event;
		while (window.pollEvent(event)) {
			// 处理一般事件
			if (event.type == Event::Closed) {
				window.close();
				return None;
			}

			// 处理悬停和点击事件
			processEvent(event, window);
			//如果currentSelection不是None了，退出
			if (currentSelection != None) 
				return currentSelection;
			
		}
		window.clear(Color::White);
		window.draw(GameState::background);
		draw(window);
		window.display();
	}


	return None;
}

void Menu::setDefult()
{
	currentSelection = None;
	return;
}

void Menu::draw(RenderWindow& window) {
	window.draw(titleText);

	for (auto& item: menuItems) {
		item.draw(window);
	}
}

void Menu::processEvent(Event event, RenderWindow& window) {
	
	int i = 0;
	for (auto& item: menuItems) {
		++i;
		if (event.type == Event::MouseMoved){
			item.update(window);
		}
		if (item.isClicked(window)) {
			//std::cout << "click" << std::endl;
			currentSelection = static_cast<Selection>(i);
			return;
		}
	}
	

}