#pragma once
#include <SFML/Graphics.hpp>
#include "GameShape.hpp"

namespace GameObjects {

	/// <summary>
	/// Class that represents a customized polygon in the game.
	/// </summary>
	class GamePolygon : public GameShape, public sf::ConvexShape {
	protected:
		GamePolygon(unsigned int zIndex) { this->zIndex = zIndex; };
	public:
		/// <summary>
		/// Static factory method that creates a polygon shared pointer and adds it to the current scene.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static std::shared_ptr<GamePolygon> create(unsigned int zIndex = 0);

		/// <summary>
		/// Checks if this shape is intersecting another shape.
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) override;

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~GamePolygon() = default;
	};

}