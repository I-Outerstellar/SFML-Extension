#include "GameRectangle.hpp"
#include "GameWindow.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"

using namespace GameObjects;

bool GameRectangle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameRectangle::draw() {
	window.draw(*this);
}