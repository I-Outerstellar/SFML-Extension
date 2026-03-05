#pragma once
#include "GameRectangle.hpp"

namespace GameObjects {

	/// <summary>
	/// Class that represents a rectangular text box in the game.
	/// </summary>
	class TextBox : public GameRectangle {
	protected:
		TextBox(sf::Text text, unsigned int characterSize = 30, unsigned int zIndex = 0) :
			text(text), GameRectangle(zIndex)
		{
			text.setCharacterSize(characterSize);
		};
	public:
		sf::Text text;

		/// <summary>
		/// Changes the text of the text box.
		/// </summary>
		/// <param name="text"></param>
		void changeText(std::string text);

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~TextBox() = default;
	};

}