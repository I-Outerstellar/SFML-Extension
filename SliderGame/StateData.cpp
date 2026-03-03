#include "StateData.hpp"

using namespace StateData::Enums;

/* VARIABLES */

bool keysActivated[] = { //Refer to the enum class for thee associated values
		false, false, false, false,
		false, false, false, false,
		false, false
};
std::atomic<bool> acceptingInput = true;