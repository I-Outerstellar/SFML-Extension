#pragma once
#include <vector>
#include <memory>

class GameButton;
class GameShape;

class GameScene {
protected:
	void moveBackButton();
	void moveBackShape();
	std::vector<std::shared_ptr<GameButton>> sceneButtons{};
	std::vector<std::shared_ptr<GameShape>> sceneShapes{};
	
public:
	GameScene();

	static void switchScene(GameScene& scene);

	std::vector<std::shared_ptr<GameButton>> getSceneButtons();
	std::vector<std::shared_ptr<GameShape>> getSceneShapes();
	void add(std::shared_ptr<GameButton>& button);
	void add(std::shared_ptr<GameShape>& shape);
	void remove(std::shared_ptr<GameButton>& button);
	void remove(std::shared_ptr<GameShape>& shape);
};