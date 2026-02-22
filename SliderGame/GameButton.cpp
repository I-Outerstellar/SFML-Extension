#include "GameButton.hpp"
#include "ObjStorageControl.hpp"

GameButton::GameButton() : RectangleShape() {}

std::shared_ptr<GameButton> GameButton::create() {
	struct GameButtonAccess : public GameButton {
		GameButtonAccess() : GameButton() {}
	};

	std::shared_ptr<GameButton> button = std::make_shared<GameButtonAccess>();
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