#pragma once
#include <atomic>

/*
	May be due for change
*/

namespace StateData {
	namespace Enums {
		enum class Keys : int {
			UP, DOWN, LEFT, RIGHT,
			W, A, S, D,
			ENTER, ESC
		};
	}
}
using namespace StateData::Enums;

extern bool keysActivated[];
extern std::atomic<bool> acceptingInput;