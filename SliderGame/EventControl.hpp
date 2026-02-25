#pragma once
#include "GameWindow.hpp"
#include "StateControl.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameButton.hpp"
#include "GameScene.hpp"
#include "SceneData.hpp"

/// <summary>
/// Functions that are called upon reaction to an event
/// </summary>
namespace EventFunctions {
    void upPressEvent(), downPressEvent(), leftPressEvent(), rightPressEvent(), clickPressEvent(), enterPressEvent(), escPressEvent();
}

/// <summary>
/// The lambda functions required for event listening
/// </summary>
namespace EventListeners {
    using namespace EventFunctions;

    const auto onKeyPressed = [](const sf::Event::KeyPressed& keyPressed) {
        using namespace sf::Keyboard;

        if (keyPressed.scancode == Scancode::Escape) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::ESC, true);
            escPressEvent();
        }
        else if (StateControl::Accessors::canAcceptInput() == false) {
            return;
        }
        else if (keyPressed.scancode == Scancode::W || keyPressed.scancode == Scancode::Up) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::W, true);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::UP, true);
            upPressEvent();
        }
        else if (keyPressed.scancode == Scancode::A || keyPressed.scancode == Scancode::Left) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::A, true);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::LEFT, true);
            leftPressEvent();
        }
        else if (keyPressed.scancode == Scancode::S || keyPressed.scancode == Scancode::Down) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::S, true);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::DOWN, true);
            downPressEvent();
        }
        else if (keyPressed.scancode == Scancode::D || keyPressed.scancode == Scancode::Right) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::D, true);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::RIGHT, true);
            rightPressEvent();
        }
    };

    const auto onKeyReleased = [](const sf::Event::KeyReleased& keyReleased) {
        using namespace sf::Keyboard;

        if (keyReleased.scancode == Scancode::Escape) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::ESC, false);
        }
        else if (keyReleased.scancode == Scancode::W || keyReleased.scancode == Scancode::Up) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::W, false);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::UP, false);
        }
        else if (keyReleased.scancode == Scancode::A || keyReleased.scancode == Scancode::Left) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::A, false);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::LEFT, false);
        }
        else if (keyReleased.scancode == Scancode::S || keyReleased.scancode == Scancode::Down) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::S, false);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::DOWN, false);
        }
        else if (keyReleased.scancode == Scancode::D || keyReleased.scancode == Scancode::Right) {
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::D, false);
            StateControl::Modifiers::setKeyPressed(StateData::Enums::Keys::RIGHT, false);
        }
    };

#pragma warning (push)
#pragma warning (disable : 4100)
    const auto onClick = [](const sf::Event::MouseButtonPressed& mouseClick) {
        if (!StateControl::Accessors::canAcceptInput()) return;
        for (auto& b : SceneStorage::currentScene.getSceneButtons()) {
            b->clickEvent();
        }
        clickPressEvent();
        };

    const auto onClickRelease = [](const sf::Event::MouseButtonReleased& mouseClickRelease) {
        for (auto& b : SceneStorage::currentScene.getSceneButtons()) {
            b->clickReleaseEvent();
        }
    };
#pragma warning (pop)
}

