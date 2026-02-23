#include "TextBox.hpp"
#include "ObjStorageControl.hpp"
#include "GameWindow.hpp"

std::shared_ptr<TextBox> TextBox::create(sf::Text text, unsigned int characterSize, unsigned int zIndex) {
	struct TextBoxAccess : public TextBox {
		TextBoxAccess(sf::Text text, unsigned int zIndex, unsigned int characterSize = 30) : TextBox(text, characterSize, zIndex) {} //Reference to local variable of enclosing function is not allowed
	};

	std::shared_ptr<GameShape> textBox = std::make_shared<TextBoxAccess>(text, zIndex, characterSize);
	ObjectStorageControl::addShape(textBox);
	return std::static_pointer_cast<TextBox>(textBox);
}

void TextBox::changeText(std::string text) {
	this->text.setString(text);
	this->draw();
}

void TextBox::draw() {
	window.draw(*this);
	unsigned int shiftX = text.getLocalBounds().size.x / 2;
	unsigned int shiftY = text.getLocalBounds().size.y / 2;
	text.setPosition(this->getGeometricCenter() - sf::Vector2f(shiftX, shiftY));
	window.draw(text);
}