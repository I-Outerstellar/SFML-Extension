#include "SceneData.hpp"
#include "GameScene.hpp"

static GameScene defaultScene = GameScene();
GameScene& SceneStorage::currentScene = defaultScene;