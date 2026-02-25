#include "GamePolygon.hpp"
#include "ObjStorageControl.hpp"
#include "GameWindow.hpp"

std::shared_ptr<GamePolygon> GamePolygon::create(unsigned int zIndex) {
	struct GamePolygonAccess : GamePolygon {
		GamePolygonAccess(unsigned int zIndex) : GamePolygon(zIndex) {}
	};

	std::shared_ptr<GameShape> polygon = std::make_shared<GamePolygonAccess>(zIndex);
	ObjectStorageControl::addShape(polygon);
	return std::static_pointer_cast<GamePolygon>(polygon);
}

void GamePolygon::remove(std::shared_ptr<GamePolygon>& polygon) {
	std::shared_ptr<GameShape> shapePtr = std::static_pointer_cast<GameShape>(polygon);
	ObjectStorageControl::removeShape(shapePtr);
	polygon.reset();
}

bool GamePolygon::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GamePolygon::draw() {
	window.draw(*this);
}