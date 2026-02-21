#pragma once
#include "StateData.hpp"

namespace StateControl {

	namespace Accessors {
		using namespace StateData::Enums;
		Scenes getGameScene();
		bool getKeyPressed(Keys key);
		bool canAcceptInput();
	}
	
	namespace Modifiers {
		using namespace StateData::Enums;
		void setGameScene(Scenes scene);
		void setKeyPressed(Keys key, bool state);
		void disableInputAccepting(unsigned int milliseconds);
	}

}
