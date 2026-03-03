#include "GamePolygon.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

using namespace GameObjects;

std::shared_ptr<GamePolygon> GamePolygon::create(unsigned int zIndex) {
	struct GamePolygonAccess : GamePolygon {
		GamePolygonAccess(unsigned int zIndex) : GamePolygon(zIndex) {}
	};

	std::shared_ptr<GameShape> polygon = std::make_shared<GamePolygonAccess>(zIndex);
	SceneStorage::currentScene.add(polygon);
	return std::static_pointer_cast<GamePolygon>(polygon);
}

void GamePolygon::remove(std::shared_ptr<GamePolygon>& polygon) {
	std::shared_ptr<GameShape> shapePtr = std::static_pointer_cast<GameShape>(polygon);
	SceneStorage::currentScene.remove(shapePtr);
	polygon.reset();
}

bool GamePolygon::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GamePolygon::draw() {
	window.draw(*this);
}