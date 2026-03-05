#include "EventControl.hpp"
#include "GameButton.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"
#include "StateControl.hpp"

const std::function<void(const sf::Event::Closed& event)> EventListeners::windowClosed = [](const sf::Event::Closed& event) {
    window.close();
};

const std::function<void(const sf::Event::KeyPressed& keyPressed)> 
EventListeners::onKeyPressed = [](const sf::Event::KeyPressed& keyPressed) {
    using namespace sf::Keyboard;
    
    if (StateControl::Accessors::canAcceptInput() == true) {
        StateControl::Modifiers::setKeyPressed(keyPressed.scancode, true);
        std::function<void()> keyPressFunction = SceneStorage::currentScene->keyPressFunctions.at(StateControl::scancodeToInt(keyPressed.scancode));
        if (keyPressFunction != nullptr) keyPressFunction();
        
    }
};

const std::function<void(const sf::Event::KeyReleased& keyReleased)> 
EventListeners::onKeyReleased = [](const sf::Event::KeyReleased& keyReleased) {
    using namespace sf::Keyboard;

    StateControl::Modifiers::setKeyPressed(keyReleased.scancode, false);
    std::function<void()> keyReleaseFunction = SceneStorage::currentScene->keyReleaseFunctions.at(StateControl::scancodeToInt(keyReleased.scancode));
    if (keyReleaseFunction != nullptr) keyReleaseFunction();
};

#pragma warning (push)
#pragma warning (disable : 4100)
const std::function<void(const sf::Event::MouseButtonPressed& mouseClick)> 
EventListeners::onClick = [](const sf::Event::MouseButtonPressed& mouseClick) {
    if (!StateControl::Accessors::canAcceptInput()) return;
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->clickEvent();
    }
};

const std::function<void(const sf::Event::MouseButtonReleased& mouseClickRelease)> 
EventListeners::onClickRelease = [](const sf::Event::MouseButtonReleased& mouseClickRelease) {
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->clickReleaseEvent();
    }
};
#pragma warning (pop)