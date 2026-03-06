#pragma once
#include <functional>
#include <vector>
#include <string>

namespace GameObjects {
	class GameScene;
}

/// <summary>
/// The namespace for controlling the scene being drawn
/// </summary>
namespace SceneControl {
	/// <summary>
	/// The repeatedly looped function to draw the scene
	/// </summary>
	void draw();

	/// <summary>
	/// Returns the current scene being used in a modifiable state
	/// </summary>
	/// <returns></returns>
	GameObjects::GameScene& currentScene();

	/// <summary>
	/// Change the current GameScene being used
	/// </summary>
	/// <param name="gameScene"></param>
	void switchScene(GameObjects::GameScene& gameScene);
}
