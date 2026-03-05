#pragma once
#include <SFML/Graphics/Color.hpp>
#include <vector>
#include <memory>
#include <functional>
#include <array>
#include <unordered_map>
#include <any>
#include <string>

namespace GameObjects {

	class GameButton;
	class GameShape;

	/// <summary>
	/// Class that stores shape and button info as a "Scene"
	/// </summary>
	class GameScene {
	private:
		/// <summary>
		/// Helper method that moves the pushed-to-back button forward in its vector.
		/// </summary>
		const void moveBackButton();

		/// <summary>
		/// Helper method that moves the pushed-to-back shape forward in its vector.
		/// </summary>
		const void moveBackShape();
		std::vector<std::shared_ptr<GameButton>> sceneButtons{};
		std::vector<std::shared_ptr<GameShape>> sceneShapes{};
		std::unordered_map<std::string, std::any> properties;

	public:
		GameScene();

		sf::Color backgroundColour = sf::Color(30, 45, 75);

		std::array<std::function<void()>, 147> keyPressFunctions{}, keyReleaseFunctions{};
		std::function<void(GameScene& sceneAfter)> switchedFrom;
		std::function<void(GameScene& sceneBefore)> switchedTo;

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

		/// <summary>
		/// Checks if the name of a property exists.
		/// </summary>
		/// <param name="propertyName"></param>
		/// <returns>True if found, false if not.</returns>
		bool hasProperty(const std::string propertyName);

		/// <summary>
		/// Allows a property to be gotten to the scene, as long as it exists and is the type specified.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="propertyName"></param>
		/// <param name="propertyValue"></param>
		template<typename T>
		T* getProperty(const std::string propertyName) {
			auto iter = this->properties.find(propertyName);
			if (iter != this->properties.end()) return std::any_cast<T>(&iter->second);
			else return nullptr;
		}

		/// <summary>
		/// Allows a property to be added/overwritten to the scene, whether that be a value or lambda function.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="propertyName"></param>
		/// <param name="propertyValue"></param>
		template<typename T>
		GameScene& setProperty(const std::string propertyName, T propertyValue) {
			this->properties[propertyName] = propertyValue;
			return *this;
		}

		/// <summary>
		/// Removes an existing property if it exists.
		/// </summary>
		/// <param name="propertyName"></param>
		GameScene& deleteProperty(const std::string propertyName);
	};

}