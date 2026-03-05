#pragma once
#include "GameShape.hpp"
#include <memory>

namespace GameObjects {

	/// <summary>
	/// Class that represents a rectangle in the game.
	/// </summary>
	class GameRectangle : public GameShape, public sf::RectangleShape {
	protected:
		GameRectangle(unsigned int zIndex = 0) { this->zIndex = zIndex; }
	public:

		/// <summary>
		/// Checks if this shape intersects another shape.
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) override;

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~GameRectangle() = default;
	};

}