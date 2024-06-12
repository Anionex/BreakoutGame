#include "Menu.hpp"
#define v2f Vector2f
# include<iostream>


const Color Menu::buttonBackgoundColor=Color(10, 10, 10, 0);
const Color Menu::shadowColor=Color(0, 0, 0, 150);

Menu::Menu(){}

Menu::Menu(ResourceManager& resourceManager) :
	currentSelection(None), 
	titleText("Breakout Game", resourceManager.getFont("main"), 48)
{
	titleText.setFillColor(Color::White);
	titleText.setPosition(200.f, 100.f);

	std::vector<std::string> items = { "Single Player", "Demo", "Settings" };
	float yPos = 200.f;

	for (const auto& item : items) {
		sf::Text text(item, resourceManager.getFont("main"), 24);
		text.setFillColor(Color::Black);
		text.setPosition(250.f, yPos);

		FloatRect bounds = text.getGlobalBounds();
		RectangleShape background(v2f(bounds.width + 20, bounds.height + 10));
		background.setPosition(v2f(text.getPosition().x - 10.f, text.getPosition().y - 5));
		background.setFillColor(sf::Color::White);

		menuItems.push_back(text);
		itemBackgrounds.push_back(background);

		yPos += 50.f;
	}

}

Menu::Selection Menu::show(RenderWindow& window) {
	
	
	while (window.isOpen()) {
		
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
		draw(window);
		window.display();
	}


	return None;
}

void Menu::draw(RenderWindow& window) {
	window.clear(Color::White);
	window.draw(titleText);

	for (int i = 0; i < menuItems.size(); i++) {
		window.draw(itemBackgrounds[i]);
		if (itemBackgrounds[i].getFillColor() == Color::Black) {
			std::cout << "blakc" << std::endl;
		}
		window.draw(menuItems[i]);
	}
}

void Menu::processEvent(Event event, RenderWindow& window) {
	 
	v2f mousePos = v2f(Mouse::getPosition(window));
	for (int i = 0; i < menuItems.size(); i++) {
		if (event.type == Event::MouseMoved){
			if (menuItems[i].getGlobalBounds().contains(mousePos)) {
				itemBackgrounds[i].setFillColor(shadowColor);
				std::cout << "within rect" << std::endl;
			} else 
				itemBackgrounds[i].setFillColor(sf::Color::White);
			
		}

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			std::cout << "click" << std::endl;
			currentSelection = static_cast<Selection>(i + 1);
			return;
		}
	}
	

}