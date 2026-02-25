#pragma once
#include <SFML/Graphics.hpp>
#include "GameShape.hpp"

class GamePolygon : public GameShape, public sf::ConvexShape {
protected:
	GamePolygon(unsigned int zIndex) { this->zIndex = zIndex; };
public:
	static std::shared_ptr<GamePolygon> create(unsigned int zIndex = 0);

	static void remove(std::shared_ptr<GamePolygon>& polygon);

	virtual bool intersects(sf::Shape& shape) override;
	virtual void draw() override;

	virtual ~GamePolygon() = default;
};