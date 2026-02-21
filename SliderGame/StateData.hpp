#pragma once
#include <atomic>

namespace StateData {
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
}
using namespace StateData::Enums;

extern bool keysActivated[];
extern std::atomic<bool> acceptingInput;
extern Scenes gameScene;