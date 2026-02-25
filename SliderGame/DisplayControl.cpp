#include "DisplayControl.hpp"
#include "GameButton.hpp"
#include "GameShape.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"

void DisplayControl::draw() {
    window.clear(sf::Color(30, 45, 75));
    for (auto& s : SceneStorage::currentScene.getSceneButtons()) {
        if (s->visible)
            s->draw();
    }
    for (auto& b : SceneStorage::currentScene.getSceneShapes()) {
        if (b->visible)
            b->draw();
    }
    window.display();

}