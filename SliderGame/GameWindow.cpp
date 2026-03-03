#include "GameWindow.hpp"
#include "GameControllers.hpp"

sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::State::Fullscreen);

void beginWindowLoop() {
    while (window.isOpen())
    {
        window.handleEvents(EventListeners::onKeyPressed, EventListeners::onKeyReleased,
            EventListeners::onClick, EventListeners::onClickRelease, EventListeners::windowClosed);

        SceneControl::draw();
    }
}