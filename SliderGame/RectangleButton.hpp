#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameWindow.hpp"
#include "GameButton.hpp"

namespace GameObjects {

	/// <summary>
	/// A class that represents a rectangular button in the game.
	/// </summary>
	class RectangleButton : public sf::RectangleShape, public GameButton {
	protected:

		/// <summary>
		/// Required constructor for the factory method.
		/// </summary>
		/// <param name="zIndex"></param>
		RectangleButton(unsigned int zIndex = 0) { this->zIndex = zIndex; }
	public:

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent(sf::Mouse::Button mouseButton) override;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent(sf::Mouse::Button mouseButton) override;

		/// <summary>
		/// Draws the button.
		/// </summary>
		virtual void draw() override;

		virtual ~RectangleButton() = default;
	};

}