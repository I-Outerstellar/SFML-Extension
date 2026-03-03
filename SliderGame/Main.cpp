#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"
#include "GameControllers.hpp"
#include "GameObjects.hpp"
#include <iostream>

using namespace GameObjects;

int wow = 0;

int main()
{
    std::srand(std::time(nullptr));
    static GameScene scene;
    static GameScene scene2;
    SceneControl::switchScene(scene);

    static sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
    static std::shared_ptr<TextButton> button = TextButton::create(sf::Text(font), 42);
    button->onClick = []() {
        wow++;
        std::cout << std::to_string(wow) << " OMG IT WAS CLICKED\n";
        button->changeText("WOW\n" + std::to_string(wow));
    };
    scene.keyPressFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::E)] = []() {
        SceneControl::switchScene(scene2);
        scene2.backgroundColour = { static_cast<uint8_t>(rand() % 128), static_cast<uint8_t>(rand() % 128), static_cast<uint8_t>(rand() % 128) };
    };
    scene2.keyReleaseFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::E)] = []() {
        SceneControl::switchScene(scene);
    };
    button->changeText("WOW");
    button->setPosition({0, 0});
    button->setSize({200, 200});
    button->setFillColor(sf::Color::Yellow);
    button->text.setFillColor(sf::Color::Black);

    static std::shared_ptr<GameRectangle> rect = GameRectangle::create(1);
    rect->setPosition({400, 200});
    rect->setSize({200, 200});

    static std::shared_ptr<GameCircle> circle = GameCircle::create();
    circle->setPosition(sf::Vector2f(400, 200));
    circle->setRadius(100);
    circle->setFillColor(sf::Color(153, 153, 153));
    circle->setOutlineColor(sf::Color::Black);
    circle->setOutlineThickness(2);

    std::shared_ptr<GamePolygon> polygon = GamePolygon::create(1);

    polygon->setPointCount(4);
    polygon->setPoint(0, { 500, 500 });
    polygon->setPoint(1, { 600, 400 });
    polygon->setPoint(2, { 700, 500 });
    polygon->setPoint(3, { 600, 300 });

    polygon->setFillColor(sf::Color::Green);
    polygon->setOutlineColor(sf::Color::White);
    polygon->setOutlineThickness(5);
    polygon->visible = true;

    scene.add(button).add(rect).add(circle).add(polygon);
    scene2.add(button);
    //SceneControl::switchScene(scene2);

    //GameRectangle::remove(rect);

    window.setFramerateLimit(30); //Window is declared globally

    while (window.isOpen())
    {
        window.handleEvents(EventListeners::onKeyPressed, EventListeners::onKeyReleased, 
            EventListeners::onClick, EventListeners::onClickRelease, EventListeners::windowClosed);
        
        SceneControl::draw();
    }
}