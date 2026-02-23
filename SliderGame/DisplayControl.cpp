#include "DisplayControl.hpp"
#include "TextButton.hpp"
#include "GameRectangle.hpp" //This class uses GameShape
#include "GameCircle.hpp" //This class also uses GameShape
#include "ObjStorageData.hpp"
#include <memory>
#include <iostream>

static int wow = 0;

void DisplayControl::draw() {
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
        
    window.clear(sf::Color(30, 45, 75));
    for (auto& b : ObjectStorage::buttons) {
        b->draw();
    }
    for (auto& s : ObjectStorage::shapes) {
        s->draw();
    }
    window.display();

}