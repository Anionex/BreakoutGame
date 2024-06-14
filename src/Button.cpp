#include "Button.hpp"
#include "Button.hpp"
#include <iostream>


Button::Button()
{
}

Button::Button(v2f pos, const std::string& content, int size, const Font& font, const Color& textColor)
{
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(size);
	text.setFillColor(textColor);
	FloatRect bounds = text.getLocalBounds();
	text.setPosition(v2f(pos.x - bounds.width / 2, pos.y - bounds.height / 2));

	backRect.setSize(v2f(bounds.width + 20, bounds.height + 10));
	backRect.setPosition(v2f(pos.x - bounds.width / 2, pos.y - bounds.height / 4));
	backRect.setFillColor(Menu::buttonBackgoundColor);

	shadowRect.setSize(v2f(bounds.width + 20, bounds.height + 10));
	shadowRect.setPosition(v2f(pos.x - bounds.width / 2 - 3, pos.y - bounds.height / 4 - 5));
	shadowRect.setFillColor(Color(0, 0, 0, 255));

}



void Button::draw(RenderWindow& window)
{
	window.draw(shadowRect);
	window.draw(backRect);
	window.draw(text);
	
}

bool Button::isMouseOn(RenderWindow& window)
{
	if (backRect.getGlobalBounds().contains(v2f(Mouse::getPosition(window)))) {
		return true;
	}

	return false;
}

bool Button::isClicked(RenderWindow& window){
	if (isMouseOn(window) && Mouse::isButtonPressed(Mouse::Left)) {
		return true;
	}

	return false;
}

void Button::update(RenderWindow& window)
{

	if (isClicked(window)) {
		text.setFillColor(Color::Red);
		//执行回调函数
		if (callback != nullptr) {
			std::cout << "invoke callback\n" << std::endl;
			callback();
		}
	}
	else if (isMouseOn(window)) {
		text.setFillColor(Color::Blue);
		shadowRect.setFillColor(Menu::shadowColor);
	}
	else {
		text.setFillColor(Color::Black);
		shadowRect.setFillColor(Color(0, 0, 0, 0));
	}
}

