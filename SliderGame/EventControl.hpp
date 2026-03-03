#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <functional>

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

    extern const std::function<void(const sf::Event::KeyPressed& keyPressed)> onKeyPressed;
    extern const std::function<void(const sf::Event::KeyReleased& keyPressed)> onKeyReleased;
    extern const std::function<void(const sf::Event::MouseButtonPressed& keyPressed)> onClick;
    extern const std::function<void(const sf::Event::MouseButtonReleased& keyPressed)> onClickRelease;
}

