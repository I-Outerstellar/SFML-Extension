#include "RectangleButton.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

void RectangleButton::clickEvent(sf::Mouse::Button mouseButton) {
	if (this->pressed || !this->active) return;
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (!this->getGlobalBounds().contains(mousePos))
		return;
	this->pressed = true;
	if (onClick != nullptr)
		onClick(mouseButton);
}

void RectangleButton::clickReleaseEvent(sf::Mouse::Button mouseButton) {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != nullptr)
		onClickRelease(mouseButton);
}

void RectangleButton::draw() {
	window.draw(*this);
}