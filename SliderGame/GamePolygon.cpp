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
	return std::static_pointer_cast<GamePolygon>(polygon);
}

bool GamePolygon::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GamePolygon::draw() {
	window.draw(*this);
}