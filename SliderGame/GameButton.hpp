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
		bool pressed = false;

	public:
		bool active = true;

		/// <summary>
		/// Definable method for on click and on click release
		/// </summary>
		std::function<void()> onClick, onClickRelease;

		/// <summary>
		/// Returns if the button is pressed.
		/// </summary>
		/// <returns></returns>
		virtual bool isPressed() { return this->pressed; };

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent() = 0;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent() = 0;

		virtual ~GameButton() = default;
	};

}