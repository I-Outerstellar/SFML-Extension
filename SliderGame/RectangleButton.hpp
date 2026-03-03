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

		RectangleButton(unsigned int zIndex);
	public:

		/// <summary>
		/// Static factory method to create a button shared pointer and add it to the current scene.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static std::shared_ptr<RectangleButton> create(unsigned int zIndex = 0);

		/// <summary>
		/// Static method to remove a button shared pointer and add it to the current scene.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static void remove(std::shared_ptr<RectangleButton>& button);

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent() override;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent() override;

		/// <summary>
		/// Draws the button.
		/// </summary>
		virtual void draw() override;

		virtual ~RectangleButton() = default;
	};

}