#pragma once
#include "GameWindow.hpp"

class GameScene;

/// <summary>
/// The namespace for controlling the scene being drawn
/// </summary>
namespace SceneControl {
	/// <summary>
	/// The repeatedly looped function to draw the scene
	/// </summary>
	void draw();

	/// <summary>
	/// Change the current GameScene being used
	/// </summary>
	/// <param name="gameScene"></param>
	void switchScene(GameScene& gameScene);
}
