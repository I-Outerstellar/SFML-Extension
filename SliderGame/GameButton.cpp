#include "GameButton.hpp"
#include "GameScene.hpp"
#include "SceneControl.hpp"

GameObjects::GameButton& GameObjects::GameButton::setZIndex(unsigned int zIndex) {
	this->zIndex = zIndex;
	SceneControl::currentScene().setProperty<void*>("ResortElements", nullptr);
	return *this;
}