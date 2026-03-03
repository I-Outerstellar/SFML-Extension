#include "StateControl.hpp"
#include "StateData.hpp"
#include <thread>
#include <chrono>
#include <atomic>

/* HELPERS */

static bool& accessKey(sf::Keyboard::Scancode key) {
	return keysActivated[StateControl::scancodeToInt(key)];
}

/* ACCESSORS */

int StateControl::scancodeToInt(sf::Keyboard::Scancode key) {
	return static_cast<int>(key) + 1;
}

bool StateControl::Accessors::getKeyPressed(sf::Keyboard::Scancode key) {
	return accessKey(key);
}

bool StateControl::Accessors::canAcceptInput() {
	return acceptingInput.load();
}

/* MODIFIERS */

void StateControl::Modifiers::setKeyPressed(sf::Keyboard::Scancode key, bool state) {
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