#pragma once
#include <SFML/Graphics/Color.hpp>
#include <vector>
#include <memory>
#include <functional>

namespace GameObjects {

	class GameButton;
	class GameShape;

	/// <summary>
	/// Class that stores shape and button info as a "Scene"
	/// </summary>
	class GameScene {
	protected:
		/// <summary>
		/// Helper method that moves the pushed-to-back button forward in its vector.
		/// </summary>
		const virtual void moveBackButton();

		/// <summary>
		/// Helper method that moves the pushed-to-back shape forward in its vector.
		/// </summary>
		const virtual void moveBackShape();
		std::vector<std::shared_ptr<GameButton>> sceneButtons{};
		std::vector<std::shared_ptr<GameShape>> sceneShapes{};

	public:
		GameScene();

		sf::Color backgroundColour = sf::Color(30, 45, 75);

		std::function<void()> keyPressFunctions[147], keyReleaseFunctions[147];

		/// <summary>
		/// Returns the vector of scene buttons.
		/// </summary>
		/// <returns></returns>
		std::vector<std::shared_ptr<GameButton>> getSceneButtons();

		/// <summary>
		/// Returns the vector of scene shapes.
		/// </summary>
		/// <returns></returns>
		std::vector<std::shared_ptr<GameShape>> getSceneShapes();

		/// <summary>
		/// Adds a button to a scene.
		/// </summary>
		/// <param name="button"></param>
		GameScene& add(const std::shared_ptr<GameButton>& button);

		/// <summary>
		/// Adds a shape to a scene.
		/// </summary>
		/// <param name="shape"></param>
		GameScene& add(const std::shared_ptr<GameShape>& shape);

		/// <summary>
		/// Removes a button from a scene.
		/// </summary>
		/// <param name="button"></param>
		GameScene& remove(const std::shared_ptr<GameButton>& button);

		/// <summary>
		/// Removes a shape from a scene.
		/// </summary>
		/// <param name="shape"></param>
		GameScene& remove(const std::shared_ptr<GameShape>& shape);
	};

}