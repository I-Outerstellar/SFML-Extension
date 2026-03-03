#pragma once
#include "GameShape.hpp"
#include <memory>

namespace GameObjects {

	/// <summary>
	/// Class that represents a rectangle in the game.
	/// </summary>
	class GameRectangle : public GameShape, public sf::RectangleShape {
	protected:
		GameRectangle(unsigned int zIndex) { this->zIndex = zIndex; }
	public:
		/// <summary>
		/// Static factory method that creates a rectangle shared pointer and adds it to the current scene.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static std::shared_ptr<GameRectangle> create(unsigned int zIndex = 0);

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