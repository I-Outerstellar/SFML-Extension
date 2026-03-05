#include "GameWindow.hpp"
#include "WindowControl.hpp"
#include "SceneControl.hpp"
#include "EventControl.hpp"

void WindowControl::beginWindowLoop(const std::string title, sf::State windowState, unsigned int fps) {
    window = sf::RenderWindow(sf::VideoMode::getDesktopMode(), title, windowState);
    window.setFramerateLimit(fps);

    while (window.isOpen())
    {
        window.handleEvents(EventListeners::onKeyPressed, EventListeners::onKeyReleased,
            EventListeners::onClick, EventListeners::onClickRelease, EventListeners::windowClosed);

        SceneControl::draw();
    }
}