#pragma once
#include "GameShape.hpp"
#include <memory>

class GameCircle : public GameShape, public sf::CircleShape {
protected:
	GameCircle(unsigned int zIndex) { this->zIndex = zIndex; };
public:
	static std::shared_ptr<GameCircle> create(unsigned int zIndex = 0);

	static void remove(std::shared_ptr<GameCircle>& circle);

	virtual bool intersects(sf::Shape& shape) override;
	virtual void draw() override;

	virtual ~GameCircle() = default;
};