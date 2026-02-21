#include "StateHandler.hpp"
#include <thread>
#include <chrono>
#include <atomic>

using namespace GameState::Enums;

/* VARIABLES */

static bool keysActivated[] = { //Refer to the enum class for thee associated values
		false, false, false, false,
		false, false, false, false,
		false, false
};
static std::atomic<bool> acceptingInput = true;
Scenes gameScene = Scenes::STARTMENU;

/* HELPERS */

static bool& accessKey(Keys key) {
	return keysActivated[static_cast<unsigned short>(key)];
}

/* ACCESSORS */

Scenes GameState::Accessors::getGameScene() {
	return gameScene;
}

bool GameState::Accessors::getKeyPressed(Keys key) {
	return accessKey(key);
}

bool GameState::Accessors::canAcceptInput() {
	return acceptingInput.load();
}

/* MODIFIERS */

void GameState::Modifiers::setGameScene(Scenes scene) {
	gameScene = scene;
}

void GameState::Modifiers::setKeyPressed(Keys key, bool state) {
	accessKey(key) = state;
}

void GameState::Modifiers::disableInputAccepting(unsigned int milliseconds) {
	if (!acceptingInput) return;
	std::thread t([milliseconds]() {
		acceptingInput = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
		acceptingInput = true;
	});
	t.detach();
}