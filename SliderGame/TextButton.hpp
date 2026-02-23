#pragma once
#include "GameButton.hpp"

class TextButton : public GameButton {
private:
	TextButton(sf::Text text, unsigned int zIndex, unsigned int characterSize) :
		text(text), GameButton(zIndex)
	{
		text.setCharacterSize(characterSize);
	}
public:
	sf::Text text;

	static std::shared_ptr<TextButton> create(sf::Text text, unsigned int characterSize = 30, unsigned int zIndex = 0);

	void changeText(std::string text);

	virtual void draw() override;

	virtual ~TextButton() = default;
};