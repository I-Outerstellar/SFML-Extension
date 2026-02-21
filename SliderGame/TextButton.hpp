#pragma once
#include "GameButton.hpp"
#include <string>

class TextButton : public GameButton {
public:
	sf::Text text;

	TextButton(sf::Text text, unsigned int characterSize = 30) :
		text(text), GameButton() {
		text.setCharacterSize(characterSize);
	}

	void changeText(std::string text) {
		this->text.setString(text);
		draw();
	}

	virtual void draw() override {
		window.draw(*this);
		unsigned int shiftX = text.getLocalBounds().size.x / 2;
		unsigned int shiftY = text.getLocalBounds().size.y / 2;
		text.setPosition(this->getGeometricCenter() - sf::Vector2f(shiftX, shiftY));
		window.draw(text);
	}
};