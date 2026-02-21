#pragma once
#include "GameWindow.hpp"
#include "StateHandler.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameButton.hpp"


void upPressEvent(), downPressEvent(), leftPressEvent(), rightPressEvent(), clickPressEvent(), enterPressEvent(), escPressEvent();
extern std::vector<std::shared_ptr<GameButton>> buttons;

const auto onKeyPressed = [](const sf::Event::KeyPressed& keyPressed) {
    using namespace sf::Keyboard;

    if (keyPressed.scancode == Scancode::Escape) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::ESC, true);
        escPressEvent();
    }
    else if (GameState::Accessors::canAcceptInput() == false) {
        return;
    }
    else if (keyPressed.scancode == Scancode::W || keyPressed.scancode == Scancode::Up) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::W, true);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::UP, true);
        upPressEvent();
    }
    else if (keyPressed.scancode == Scancode::A || keyPressed.scancode == Scancode::Left) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::A, true);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::LEFT, true);
        leftPressEvent();
    }
    else if (keyPressed.scancode == Scancode::S || keyPressed.scancode == Scancode::Down) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::S, true);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::DOWN, true);
        downPressEvent();
    }
    else if (keyPressed.scancode == Scancode::D || keyPressed.scancode == Scancode::Right) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::D, true);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::RIGHT, true);
        rightPressEvent();
    }
};

const auto onKeyReleased = [](const sf::Event::KeyReleased& keyReleased) {
    using namespace sf::Keyboard;

    if (keyReleased.scancode == Scancode::Escape) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::ESC, false);
    }
    else if (keyReleased.scancode == Scancode::W || keyReleased.scancode == Scancode::Up) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::W, false);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::UP, false);
    }
    else if (keyReleased.scancode == Scancode::A || keyReleased.scancode == Scancode::Left) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::A, false);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::LEFT, false);
    }
    else if (keyReleased.scancode == Scancode::S || keyReleased.scancode == Scancode::Down) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::S, false);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::DOWN, false);
    }
    else if (keyReleased.scancode == Scancode::D || keyReleased.scancode == Scancode::Right) {
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::D, false);
        GameState::Modifiers::setKeyPressed(GameState::Enums::Keys::RIGHT, false);
    }
};

const auto onClick = [](const sf::Event::MouseButtonPressed& mouseClick) {
    if (!GameState::Accessors::canAcceptInput()) return;
    for (auto& b : buttons) {
        b->clickEvent(mouseClick);
    }
    clickPressEvent();
};

const auto onClickRelease = [](const sf::Event::MouseButtonReleased& mouseClickRelease) {
    for (auto& b : buttons) {
        b->clickReleaseEvent(mouseClickRelease);
    }
};