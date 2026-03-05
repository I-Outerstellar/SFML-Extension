#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameWindow.hpp"
#include "GameDrawable.hpp"

namespace GameObjects {

	/// <summary>
	/// A class that represents a rectangular button in the game.
	/// </summary>
	class GameButton : public GameDrawable {
	protected:
		/// <summary>
		/// Determines if the button is pressed down or not.
		/// </summary>
		bool pressed = false;

	public:
		/*Variables*/

		/// <summary>
		/// Determines if the button can be used or not.
		/// </summary>
		bool active = true;

		/// <summary>
		/// Definable method for on click and on click release
		/// </summary>
		std::function<void(sf::Mouse::Button)> onClick, onClickRelease;


		/*Methods*/

		/// <summary>
		/// Returns if the button is pressed.
		/// </summary>
		/// <returns></returns>
		virtual bool isPressed() { return this->pressed; };

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent(sf::Mouse::Button mouseButton) = 0;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent(sf::Mouse::Button mouseButton) = 0;

		virtual ~GameButton() = default;
	};

}