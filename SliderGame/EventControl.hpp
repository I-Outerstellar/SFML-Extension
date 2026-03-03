#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <functional>

/// <summary>
/// The lambda functions required for event listening
/// </summary>
namespace EventListeners {
    extern const std::function<void(const sf::Event::Closed& event)> windowClosed;
    extern const std::function<void(const sf::Event::KeyPressed& keyPressed)> onKeyPressed;
    extern const std::function<void(const sf::Event::KeyReleased& keyPressed)> onKeyReleased;
    extern const std::function<void(const sf::Event::MouseButtonPressed& keyPressed)> onClick;
    extern const std::function<void(const sf::Event::MouseButtonReleased& keyPressed)> onClickRelease;
}

