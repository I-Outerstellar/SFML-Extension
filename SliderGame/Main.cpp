#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"
#include "EventControl.hpp"
#include "DisplayControl.hpp"
#include "TextButton.hpp"
#include "GameRectangle.hpp"
#include "GameCircle.hpp"
#include <iostream>

static int wow = 0;

int main()
{
    static sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
    static std::shared_ptr<TextButton> button = TextButton::create(sf::Text(font), 42);
    //static std::shared_ptr<GameButton> button = GameButton::create();
    button->onClick = []() {
        wow++;
        std::cout << wow << " OOMG IT WAS CLICKED\n";
        };
    button->changeText("BRUH");
    button->setPosition(sf::Vector2f(0, 0));
    button->setSize(sf::Vector2f(200, 200));
    button->setFillColor(sf::Color::Yellow);
    button->text.setFillColor(sf::Color::Black);

    static std::shared_ptr<GameRectangle> rect = GameRectangle::create();
    rect->setPosition(sf::Vector2f(400, 200));
    rect->setSize(sf::Vector2f(200, 200));

    static std::shared_ptr<GameCircle> circle = GameCircle::create(1);
    circle->setPosition(sf::Vector2f(400, 200));
    circle->setRadius(100);
    circle->setFillColor(sf::Color(153, 153, 153));
    circle->setOutlineColor(sf::Color::Black);
    circle->setOutlineThickness(2);

    window.setFramerateLimit(30); //Window is declared globally

    while (window.isOpen())
    {
        window.handleEvents(EventListeners::onKeyPressed, EventListeners::onKeyReleased, EventListeners::onClick, EventListeners::onClickRelease);
        DisplayControl::draw();
    }
}