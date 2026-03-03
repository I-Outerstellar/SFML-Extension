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
	SceneStorage::currentScene.add(button);
	return std::static_pointer_cast<RectangleButton>(button);
}

void RectangleButton::remove(std::shared_ptr<RectangleButton>& button) {
	std::shared_ptr<GameButton> buttonPtr = std::static_pointer_cast<GameButton>(button);
	SceneStorage::currentScene.remove(buttonPtr);
	button.reset();
}

void RectangleButton::clickEvent() {
	if (this->pressed || !this->active) return;
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (!this->getGlobalBounds().contains(mousePos))
		return;
	this->pressed = true;
	if (onClick != NULL)
		onClick();
}

void RectangleButton::clickReleaseEvent() {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != NULL)
		onClickRelease();
}

void RectangleButton::draw() {
	window.draw(*this);
}