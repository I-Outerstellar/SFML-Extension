#include "StateControl.hpp"
#include "StateData.hpp"
#include <thread>
#include <chrono>
#include <atomic>

using namespace StateData::Enums;

/* HELPERS */

static bool& accessKey(Keys key) {
	return keysActivated[static_cast<unsigned short>(key)];
}

/* ACCESSORS */

bool StateControl::Accessors::getKeyPressed(Keys key) {
	return accessKey(key);
}

bool StateControl::Accessors::canAcceptInput() {
	return acceptingInput.load();
}

/* MODIFIERS */

void StateControl::Modifiers::setKeyPressed(Keys key, bool state) {
	accessKey(key) = state;
}

void StateControl::Modifiers::disableInputAccepting(unsigned int milliseconds) {
	if (!acceptingInput) return;
	std::thread t([milliseconds]() {
		acceptingInput = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
		acceptingInput = true;
	});
	t.detach();
}