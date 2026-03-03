#include "EventControl.hpp"
#include "GameButton.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"
#include "GameWindow.hpp"
#include "StateControl.hpp"

void EventFunctions::upPressEvent() {

}

void EventFunctions::downPressEvent() {

}

void EventFunctions::leftPressEvent() {

}

void EventFunctions::rightPressEvent() {

}

void EventFunctions::clickPressEvent() {

}

void EventFunctions::enterPressEvent() {

}

void EventFunctions::escPressEvent() {
    window.close();
}

const std::function<void(const sf::Event::KeyPressed& keyPressed)> 
EventListeners::onKeyPressed = [](const sf::Event::KeyPressed& keyPressed) {
    using namespace sf::Keyboard;

    if (keyPressed.scancode == Scancode::Escape) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::ESC, true);
        EventFunctions::escPressEvent();
    }
    else if (StateControl::Accessors::canAcceptInput() == false) {
        return;
    }
    else if (keyPressed.scancode == Scancode::W) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::W, true);
    }
    else if (keyPressed.scancode == Scancode::A) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::A, true);
    }
    else if (keyPressed.scancode == Scancode::S) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::S, true);
    }
    else if (keyPressed.scancode == Scancode::D) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::D, true);
    }
    else if (keyPressed.scancode == Scancode::Up) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::UP, true);
    }
    else if (keyPressed.scancode == Scancode::Left) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::LEFT, true);
    }
    else if (keyPressed.scancode == Scancode::Down) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::DOWN, true);
    }
    else if (keyPressed.scancode == Scancode::Right) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::RIGHT, true);
    }
};

const std::function<void(const sf::Event::KeyReleased& keyReleased)> 
EventListeners::onKeyReleased = [](const sf::Event::KeyReleased& keyReleased) {
    using namespace sf::Keyboard;

    if (keyReleased.scancode == Scancode::Escape) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::ESC, false);
    }
    else if (keyReleased.scancode == Scancode::W) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::W, false);
    }
    else if (keyReleased.scancode == Scancode::A) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::A, false);
    }
    else if (keyReleased.scancode == Scancode::S) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::S, false);
    }
    else if (keyReleased.scancode == Scancode::D) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::D, false);
    }
    else if (keyReleased.scancode == Scancode::Up) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::UP, false);
    }
    else if (keyReleased.scancode == Scancode::Left) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::LEFT, false);
    }
    else if (keyReleased.scancode == Scancode::Down) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::DOWN, false);
    }
    else if (keyReleased.scancode == Scancode::Right) {
        StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::RIGHT, false);
    }
};

#pragma warning (push)
#pragma warning (disable : 4100)
const std::function<void(const sf::Event::MouseButtonPressed& mouseClick)> 
EventListeners::onClick = [](const sf::Event::MouseButtonPressed& mouseClick) {
    if (!StateControl::Accessors::canAcceptInput()) return;
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->clickEvent();
    }
    EventFunctions::clickPressEvent();
};

const std::function<void(const sf::Event::MouseButtonReleased& mouseClickRelease)> 
EventListeners::onClickRelease = [](const sf::Event::MouseButtonReleased& mouseClickRelease) {
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->clickReleaseEvent();
    }
};
#pragma warning (pop)