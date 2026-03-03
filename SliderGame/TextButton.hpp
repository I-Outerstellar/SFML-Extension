#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "TextImplement.hpp"
#include "GameButton.hpp"

namespace GameObjects {

	/// <summary>
	/// A class that represents a textbox button in the game.
	/// </summary>
	class TextButton : public sf::RectangleShape, public TextImplement, public GameButton {
	private:
		TextButton(sf::Text text, unsigned int zIndex, unsigned int characterSize) :
			TextImplement(text), sf::RectangleShape()
		{
			this->zIndex = zIndex;
			text.setCharacterSize(characterSize);
		}
	public:

		/// <summary>
		/// Static factory method to create a button shared pointer and add it to the current scene.
		/// </summary>
		/// <param name="text"></param>
		/// <param name="characterSize"></param>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static std::shared_ptr<TextButton> create(sf::Text text, unsigned int characterSize = 30, unsigned int zIndex = 0);

		/// <summary>
		/// Static method to remove a button from the current scene.
		/// </summary>
		/// <param name="button"></param>
		static void remove(std::shared_ptr<TextButton>& button);

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent() override;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent() override;

		/// <summary>
		/// Change the text of the button.
		/// </summary>
		/// <param name="text"></param>
		virtual void changeText(std::string text) override;

		/// <summary>
		/// Draws the button.
		/// </summary>
		virtual void draw() override;

		virtual ~TextButton() = default;
	};

}