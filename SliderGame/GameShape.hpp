#pragma once
#include "SFML/Graphics.hpp"
#include "GameDrawable.hpp"

/// <summary>
/// Interface for creating a game shape.
/// </summary>
class GameShape : public GameDrawable {
private:

public:
	/// <summary>
	/// Returns if this shape and the given shape intersects or not.
	/// This method is the same among all shapes, I just can't define it here. 
	/// </summary>
	/// <param name="shape"></param>
	/// <returns></returns>
	virtual bool intersects(sf::Shape& shape) = 0;

	virtual ~GameShape() = default;
};