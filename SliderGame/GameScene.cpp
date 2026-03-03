#include "GameScene.hpp"
#include "GameButton.hpp"
#include "GameShape.hpp"
#include "SceneData.hpp"
#include <algorithm>

using namespace GameObjects;

GameScene::GameScene() {}

void GameScene::moveBackButton() {
	for (size_t i = this->sceneButtons.size() - 1; i >= 1; i--) {
		if (this->sceneButtons.at(i - 1)->getZIndex() < this->sceneButtons.at(i)->getZIndex())
			std::swap(this->sceneButtons.at(i - 1), this->sceneButtons.at(i));
	}
}

void GameScene::moveBackShape() {
	for (size_t i = this->sceneShapes.size() - 1; i >= 1; i--) {
		if (this->sceneShapes.at(i - 1)->getZIndex() < this->sceneShapes.at(i)->getZIndex())
			std::swap(this->sceneShapes.at(i - 1), this->sceneShapes.at(i));
	}
}

std::vector<std::shared_ptr<GameButton>> GameScene::getSceneButtons() {
	return this->sceneButtons;
}

std::vector<std::shared_ptr<GameShape>> GameScene::getSceneShapes() {
	return this->sceneShapes;
}

void GameScene::add(std::shared_ptr<GameButton>& button) {
	this->sceneButtons.push_back(button);

	for (size_t i = this->sceneButtons.size() - 1; i >= 1; i--) {
		if (this->sceneButtons.at(i - 1)->getZIndex() < this->sceneButtons.at(i)->getZIndex())
			std::swap(this->sceneButtons.at(i - 1), this->sceneButtons.at(i));
	}
}

void GameScene::add(std::shared_ptr<GameShape>& shape) {
	this->sceneShapes.push_back(shape);

	for (size_t i = this->sceneShapes.size() - 1; i >= 1; i--) {
		if (this->sceneShapes.at(i - 1)->getZIndex() < this->sceneShapes.at(i)->getZIndex())
			std::swap(this->sceneShapes.at(i - 1), this->sceneShapes.at(i));
	}
}

void GameScene::remove(std::shared_ptr<GameButton>& button) {
	auto iter = std::find(this->sceneButtons.begin(), this->sceneButtons.end(), button);
	if (iter != this->sceneButtons.end())
		this->sceneButtons.erase(iter);
}

void GameScene::remove(std::shared_ptr<GameShape>& shape) {
	auto iter = std::find(this->sceneShapes.begin(), this->sceneShapes.end(), shape);
	if (iter != this->sceneShapes.end())
		this->sceneShapes.erase(iter);
}