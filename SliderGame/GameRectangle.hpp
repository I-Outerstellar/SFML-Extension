#pragma once
#include "GameShape.hpp"
#include <memory>

class GameRectangle : public GameShape, public sf::RectangleShape {
protected:
	GameRectangle(unsigned int zIndex) { this->zIndex = zIndex; }
public:
	static std::shared_ptr<GameRectangle> create(unsigned int zIndex = 0);

	static void remove(std::shared_ptr<GameRectangle>& rect);

	virtual bool intersects(sf::Shape& shape) override;
	virtual void draw() override;

	virtual ~GameRectangle() = default;
};