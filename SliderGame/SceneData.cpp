#include "SceneData.hpp"
#include "GameScene.hpp"

GameObjects::GameScene SceneStorage::defaultScene = GameObjects::GameScene();
GameObjects::GameScene* SceneStorage::currentScene = &defaultScene;