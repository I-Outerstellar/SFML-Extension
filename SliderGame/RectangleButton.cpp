#include "RectangleButton.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"

using namespace GameObjects;


RectangleButton::RectangleButton(unsigned int zIndex) : RectangleShape() { this->zIndex = zIndex; }

std::shared_ptr<RectangleButton> RectangleButton::create(unsigned int zIndex) {
	struct RectangleButtonAccess : public RectangleButton {
		RectangleButtonAccess(unsigned int zIndex) : RectangleButton(zIndex) {}
	};

	std::shared_ptr<GameButton> button = std::make_shared<RectangleButtonAccess>(zIndex);
	return std::static_pointer_cast<RectangleButton>(button);
}

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