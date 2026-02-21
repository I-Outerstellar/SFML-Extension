#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"
#include "EventControl.hpp"
#include "DisplayControl.hpp"
#include <iostream>

int main()
{
    window.setFramerateLimit(30); //Window is declared globally

    while (window.isOpen())
    {
        window.handleEvents(EventListeners::onKeyPressed, EventListeners::onKeyReleased, EventListeners::onClick, EventListeners::onClickRelease);
        DisplayControl::draw();
    }
}