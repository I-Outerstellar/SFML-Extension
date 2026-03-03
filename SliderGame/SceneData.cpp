#include "SceneData.hpp"
#include "GameScene.hpp"

GameScene SceneStorage::defaultScene = GameScene();
GameScene& SceneStorage::currentScene = defaultScene;