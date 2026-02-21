#pragma once

namespace GameState {
	namespace Enums {
		enum class Keys : int {
			UP, DOWN, LEFT, RIGHT,
			W, A, S, D,
			ENTER, ESC
		};

		enum class Scenes {
			STARTMENU, GAME, LEADERBOARD
		};
	}

	namespace Accessors {
		using namespace Enums;
		Scenes getGameScene();
		bool getKeyPressed(Keys key);
		bool canAcceptInput();
	}
	
	namespace Modifiers {
		using namespace Enums;
		void setGameScene(Scenes scene);
		void setKeyPressed(Keys key, bool state);
		void disableInputAccepting(unsigned int milliseconds);
	}
}
