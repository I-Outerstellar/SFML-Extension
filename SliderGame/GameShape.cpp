#include "GameShape.hpp"
#include "GameScene.hpp"
#include "SceneControl.hpp"

GameObjects::GameShape& GameObjects::GameShape::setZIndex(unsigned int zIndex) {
	this->zIndex = zIndex;
	SceneControl::currentScene().setProperty<void*>("ResortElements", nullptr);
	return *this;
}