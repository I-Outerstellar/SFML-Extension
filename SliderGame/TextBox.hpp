#pragma once
#include "GameRectangle.hpp"

class TextBox : public GameRectangle {
protected:
	TextBox(sf::Text text, unsigned int characterSize, unsigned int zIndex) :
		text(text), GameRectangle(zIndex)
	{
		text.setCharacterSize(characterSize);
	};
public:
	sf::Text text;

	static std::shared_ptr<TextBox> create(sf::Text text, unsigned int characterSize = 30, unsigned int zIndex = 0);

	void changeText(std::string text);

	virtual void draw() override;

	virtual ~TextBox() = default;
};