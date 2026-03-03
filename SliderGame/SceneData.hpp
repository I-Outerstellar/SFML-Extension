#pragma once
#include <vector>
#include <memory>

namespace GameObjects {
	class GameScene;
}

/// <summary>
/// Namespace that holds the currently used scene
/// </summary>
namespace SceneStorage {
	extern GameObjects::GameScene defaultScene;
	extern GameObjects::GameScene* currentScene;
}
