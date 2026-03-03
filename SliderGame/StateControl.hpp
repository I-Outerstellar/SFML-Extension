#pragma once
#include <SFML/Window/Keyboard.hpp>

namespace StateControl {

	int scancodeToInt(sf::Keyboard::Scancode key);

	/// <summary>
	/// Getters/Accessor methods for the current game states
	/// </summary>
	namespace Accessors {
		bool getKeyPressed(sf::Keyboard::Scancode key);
		bool canAcceptInput();
	}
	
	/// <summary>
	/// Setters/Modifiers for the current game states
	/// </summary>
	namespace Modifiers {
		void setKeyPressed(sf::Keyboard::Scancode key, bool state);
		void disableInputAccepting(unsigned int milliseconds);
	}

}
