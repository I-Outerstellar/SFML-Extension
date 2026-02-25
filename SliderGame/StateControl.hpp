#pragma once
#include "StateData.hpp"

namespace StateControl {

	/// <summary>
	/// Getters/Accessor methods for the current game states
	/// </summary>
	namespace Accessors {
		using namespace StateData::Enums;
		Scenes getGameScene();
		bool getKeyPressed(Keys key);
		bool canAcceptInput();
	}
	
	/// <summary>
	/// Setters/Modifiers for the current game states
	/// </summary>
	namespace Modifiers {
		using namespace StateData::Enums;
		void setGameScene(Scenes scene);
		void setKeyPressed(Keys key, bool state);
		void disableInputAccepting(unsigned int milliseconds);
	}

}
