#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameWindow.hpp"
#include "GameDrawable.hpp"

/// <summary>
/// A class that represents a rectangular button in the game.
/// </summary>
class GameButton : public sf::RectangleShape, public GameDrawable {
protected:
	bool pressed = false;

	GameButton(unsigned int zIndex);
public:
	bool active = true;

	/// <summary>
	/// Static factory method to create a button shared pointer and add it to the current scene.
	/// </summary>
	/// <param name="zIndex"></param>
	/// <returns></returns>
	static std::shared_ptr<GameButton> create(unsigned int zIndex = 0);

	/// <summary>
	/// Static method to remove a button shared pointer and add it to the current scene.
	/// </summary>
	/// <param name="zIndex"></param>
	/// <returns></returns>
	static void remove(std::shared_ptr<GameButton>& button);

	/// <summary>
	/// Definable method for on click and on click release
	/// </summary>
	std::function<void()> onClick, onClickRelease;

	/// <summary>
	/// Returns if the button is pressed.
	/// </summary>
	/// <returns></returns>
	bool isPressed() { return this->pressed; };

	/// <summary>
	/// The method required to listen for a click
	/// </summary>
	virtual void clickEvent();

	/// <summary>
	/// The method required to listen to a click release
	/// </summary>
	virtual void clickReleaseEvent();
	
	/// <summary>
	/// Draws the button.
	/// </summary>
	virtual void draw() override;

	virtual ~GameButton() = default;
};