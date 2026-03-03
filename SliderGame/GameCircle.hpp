#pragma once
#include "GameShape.hpp"
#include <memory>

namespace GameObjects {

	/// <summary>
	/// Class that represents a circle in the game.
	/// </summary>
	class GameCircle : public GameShape, public sf::CircleShape {
	protected:
		GameCircle(unsigned int zIndex) { this->zIndex = zIndex; };
	public:
		/// <summary>
		/// Static factory method that creates a circle shared pointer and adds it to the current scene.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static std::shared_ptr<GameCircle> create(unsigned int zIndex = 0);

		/// <summary>
		/// Static method that removes a circle from the current scene.
		/// </summary>
		/// <param name="circle"></param>
		static void remove(std::shared_ptr<GameCircle>& circle);

		/// <summary>
		/// Returns if this shape and the given shape intersects or not.
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) override;

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~GameCircle() = default;
	};

}