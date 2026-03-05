#include "SceneControl.hpp"
#include "GameButton.hpp"
#include "GameShape.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"

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

GameObjects::GameScene& SceneControl::getCurrentScene() {
    return *SceneStorage::currentScene;
}

void SceneControl::switchScene(GameObjects::GameScene& scene) {
    GameObjects::GameScene& beforeScene = *SceneStorage::currentScene;
    if (beforeScene.switchedFrom != nullptr) {
        SceneStorage::currentScene->switchedFrom(scene);
    }
    SceneStorage::currentScene = &scene;
    if (scene.switchedTo != nullptr) {
        scene.switchedTo(beforeScene);
    }
}