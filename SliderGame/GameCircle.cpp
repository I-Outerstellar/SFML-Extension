#include "GameCircle.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

std::shared_ptr<GameCircle> GameCircle::create(unsigned int zIndex) {
	struct GameCircleAccess : public GameCircle {
		GameCircleAccess(unsigned int zIndex) : GameCircle(zIndex) {}
	};

	std::shared_ptr<GameShape> circle = std::make_shared<GameCircleAccess>(zIndex);
	SceneStorage::currentScene.add(circle);
	return std::static_pointer_cast<GameCircle>(circle);
}

void GameCircle::remove(std::shared_ptr<GameCircle>& circle) {
	std::shared_ptr<GameShape> shapePtr = std::static_pointer_cast<GameShape>(circle);
	SceneStorage::currentScene.remove(shapePtr);
	circle.reset();
}

bool GameCircle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameCircle::draw() {
	window.draw(*this);
}