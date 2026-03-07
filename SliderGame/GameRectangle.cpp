#include "GameRectangle.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

bool GameRectangle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameRectangle::draw() {
	window.draw(*this);
}