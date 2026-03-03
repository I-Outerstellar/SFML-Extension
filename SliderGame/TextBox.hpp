#pragma once
#include "GameRectangle.hpp"

namespace GameObjects {

	/// <summary>
	/// Class that represents a rectangular text box in the game.
	/// </summary>
	class TextBox : public GameRectangle {
	protected:
		TextBox(sf::Text text, unsigned int characterSize, unsigned int zIndex) :
			text(text), GameRectangle(zIndex)
		{
			text.setCharacterSize(characterSize);
		};
	public:
		sf::Text text;

		/// <summary>
		/// Static factory method that creates a text box shared pointer and adds it to the current scene.
		/// </summary>
		/// <param name="text"></param>
		/// <param name="characterSize"></param>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		static std::shared_ptr<TextBox> create(sf::Text text, unsigned int characterSize = 30, unsigned int zIndex = 0);

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