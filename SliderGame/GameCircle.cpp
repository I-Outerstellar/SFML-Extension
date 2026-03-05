#include "GameCircle.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

bool GameCircle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameCircle::draw() {
	window.draw(*this);
}