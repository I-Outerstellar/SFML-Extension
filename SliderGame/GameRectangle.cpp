#include "GameRectangle.hpp"
#include "GameWindow.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"

using namespace GameObjects;

std::shared_ptr<GameRectangle> GameRectangle::create(unsigned int zIndex) {
	struct GameRectangleAccess : GameRectangle {
		GameRectangleAccess(unsigned int zIndex) : GameRectangle(zIndex) {}
	};

	std::shared_ptr<GameShape> rect = std::make_shared<GameRectangleAccess>(zIndex);
	SceneStorage::currentScene.add(rect);
	return std::static_pointer_cast<GameRectangle>(rect);
}

void GameRectangle::remove(std::shared_ptr<GameRectangle>& rect) {
	std::shared_ptr<GameShape> shapePtr = std::static_pointer_cast<GameShape>(rect);
	SceneStorage::currentScene.remove(shapePtr);
	rect.reset();
}

bool GameRectangle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameRectangle::draw() {
	window.draw(*this);
}