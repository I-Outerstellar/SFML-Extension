#include "GameRectangle.hpp"
#include "GameWindow.hpp"
#include "ObjStorageControl.hpp"

std::shared_ptr<GameRectangle> GameRectangle::create(unsigned int zIndex) {
	struct GameRectangleAccess : GameRectangle {
		GameRectangleAccess(unsigned int zIndex) : GameRectangle(zIndex) {}
	};

	std::shared_ptr<GameShape> rect = std::make_shared<GameRectangleAccess>(zIndex);
	ObjectStorageControl::addShape(rect);
	return std::static_pointer_cast<GameRectangle>(rect);
}

bool GameRectangle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameRectangle::draw() {
	window.draw(*this);
}