#include "TextBox.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

void TextBox::changeText(std::string text) {
	this->text.setString(text);
	this->draw();
}

void TextBox::draw() {
	window.draw(*this);
	auto shiftX = text.getLocalBounds().size.x / 2;
	auto shiftY = text.getLocalBounds().size.y / 2;
	text.setPosition(this->getGeometricCenter() - sf::Vector2f(shiftX, shiftY));
	window.draw(text);
}