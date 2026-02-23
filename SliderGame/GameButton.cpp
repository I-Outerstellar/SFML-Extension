#include "GameButton.hpp"
#include "ObjStorageControl.hpp"

GameButton::GameButton(unsigned int zIndex) : RectangleShape() { this->zIndex = 0; }

std::shared_ptr<GameButton> GameButton::create(unsigned int zIndex) {
	struct GameButtonAccess : public GameButton {
		GameButtonAccess(unsigned int zIndex) : GameButton(zIndex) {}
	};

	std::shared_ptr<GameButton> button = std::make_shared<GameButtonAccess>(zIndex);
	ObjectStorageControl::addButton(button);
	return button;
}

void GameButton::clickEvent() {
	if (this->pressed || !this->active) return;
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (!this->getGlobalBounds().contains(mousePos))
		return;
	this->pressed = true;
	if (onClick != NULL)
		onClick();
}

void GameButton::clickReleaseEvent() {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != NULL)
		onClickRelease();
}

void GameButton::draw() {
	window.draw(*this);
}