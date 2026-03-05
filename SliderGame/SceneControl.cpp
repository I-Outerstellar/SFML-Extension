#include "SceneControl.hpp"
#include "GameButton.hpp"
#include "GameShape.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"

void SceneControl::draw() {
    window.clear(SceneStorage::currentScene->backgroundColour);
    for (auto& s : SceneStorage::currentScene->getSceneButtons()) {
        if (s->visible)
            s->draw();
    }
    for (auto& b : SceneStorage::currentScene->getSceneShapes()) {
        if (b->visible)
            b->draw();
    }
    window.display();

}

GameObjects::GameScene& SceneControl::currentScene() {
    return *SceneStorage::currentScene;
}

void SceneControl::switchScene(GameObjects::GameScene& scene) {
    GameObjects::GameScene& beforeScene = *SceneStorage::currentScene;
    bool scene1Pass = true, scene2Pass = true;
    if (beforeScene.switchedFrom != nullptr) {
        scene1Pass = SceneStorage::currentScene->switchedFrom(scene);
    }
    if (scene.switchedTo != nullptr) {
        scene2Pass = scene.switchedTo(beforeScene);
    }
    if (scene1Pass && scene2Pass)
        SceneStorage::currentScene = &scene;
    
}