#pragma once
#include "GameButton.hpp"

/// <summary>
/// A class that represents a textbox button in the game.
/// </summary>
class TextButton : public GameButton {
private:
	TextButton(sf::Text text, unsigned int zIndex, unsigned int characterSize) :
		text(text), GameButton(zIndex)
	{
		text.setCharacterSize(characterSize);
	}
public:
	sf::Text text;

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
	/// Change the text of the button.
	/// </summary>
	/// <param name="text"></param>
	void changeText(std::string text);

	/// <summary>
	/// Draws the button.
	/// </summary>
	virtual void draw() override;

	virtual ~TextButton() = default;
};