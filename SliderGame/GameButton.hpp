#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <utility>
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
		/// Creates a game button of the type specified, limited to buttons inheriting GameButton.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args"></param>
		/// <returns>A shared pointer to the button created.</returns>
		template<std::derived_from<GameButton> T, typename... Args>
		static std::shared_ptr<T> create(Args&&... args) {
			struct GameButtonAccess : public T {
				GameButtonAccess(Args&&... args) : T(std::forward<Args>(args)...) {}
			};

			std::shared_ptr<GameButton> button = std::make_shared<GameButtonAccess>(std::forward<Args>(args)...);
			return std::static_pointer_cast<T>(button);
		}

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