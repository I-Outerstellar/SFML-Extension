#pragma once
#include <vector>
#include <memory>

class GameScene;

/// <summary>
/// Namespace that holds the currently used scene
/// </summary>
namespace SceneStorage {
	extern GameScene defaultScene;
	extern GameScene& currentScene;
}
