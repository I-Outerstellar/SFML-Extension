#include "GameImage.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

bool GameImage::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameImage::draw() {
	window.draw(*this);
}