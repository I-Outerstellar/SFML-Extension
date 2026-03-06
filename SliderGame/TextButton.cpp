#include "TextButton.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

void TextButton::changeText(std::string text) {
	this->text.setString(text);
	this->draw();
}

void TextButton::clickEvent(sf::Mouse::Button mouseButton) {
	if (this->pressed || !this->active) return;
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (!this->getGlobalBounds().contains(mousePos))
		return;
	this->pressed = true;
	if (onClick != nullptr)
		onClick(mouseButton);
}

void TextButton::clickReleaseEvent(sf::Mouse::Button mouseButton) {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != nullptr)
		onClickRelease(mouseButton);
}

void TextButton::draw() {
	window.draw(*this);
	auto shiftX = text.getLocalBounds().size.x / 2;
	auto shiftY = text.getLocalBounds().size.y / 2;
	text.setPosition(this->getGeometricCenter() - sf::Vector2f(shiftX, shiftY));
	window.draw(this->text);
}