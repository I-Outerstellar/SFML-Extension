#pragma once
#include "GameButton.hpp"

class TextButton : public GameButton {
private:
	TextButton(sf::Text text, unsigned int characterSize = 30) :
		text(text), GameButton()
	{
		text.setCharacterSize(characterSize);
	}
public:
	sf::Text text;

	static std::shared_ptr<TextButton> create(sf::Text text, unsigned int characterSize = 30);

	void changeText(std::string text);

	virtual void draw() override;
};