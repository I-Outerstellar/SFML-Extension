#include "GameCircle.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

std::shared_ptr<GameCircle> GameCircle::create(unsigned int zIndex) {
	struct GameCircleAccess : public GameCircle {
		GameCircleAccess(unsigned int zIndex) : GameCircle(zIndex) {}
	};

	std::shared_ptr<GameShape> circle = std::make_shared<GameCircleAccess>(zIndex);
	return std::static_pointer_cast<GameCircle>(circle);
}

bool GameCircle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameCircle::draw() {
	window.draw(*this);
}