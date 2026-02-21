#include "TextButton.hpp"
#include "ObjStorageControl.hpp"

std::shared_ptr<TextButton> TextButton::create(sf::Text text, unsigned int characterSize) {
	struct TextButtonAccess : public TextButton {
		TextButtonAccess(sf::Text text, unsigned int characterSize = 30) : TextButton(text, characterSize) {} //Reference to local variable of enclosing function is not allowed
	};

	std::shared_ptr<GameButton> button = std::make_shared<TextButtonAccess>(text, characterSize);
	ObjectStorageControl::addButton(button);
	return std::static_pointer_cast<TextButton>(button);
}

void TextButton::changeText(std::string text) {
	this->text.setString(text);
	this->draw();
}

void TextButton::draw() {
	window.draw(*this);
	unsigned int shiftX = text.getLocalBounds().size.x / 2;
	unsigned int shiftY = text.getLocalBounds().size.y / 2;
	text.setPosition(this->getGeometricCenter() - sf::Vector2f(shiftX, shiftY));
	window.draw(text);
}