#pragma once
#include "SFML/Graphics.hpp"
#include "GameDrawable.hpp"

class GameShape : public GameDrawable {
private:

public:
	bool visible = true;
	virtual bool intersects(sf::Shape& shape) = 0;

	virtual ~GameShape() = default;
};