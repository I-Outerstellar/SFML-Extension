#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"
#include "EventHandler.hpp"
#include "DisplayHandler.hpp"
#include <iostream>

int main()
{
    window.setFramerateLimit(30); //Window is declared globally

    while (window.isOpen())
    {
        window.handleEvents(onKeyPressed, onKeyReleased, onClick, onClickRelease);
        DisplayHandler::draw();
    }
}