#include "DisplayControl.hpp"
#include "TextButton.hpp"
#include "ObjectStorage.hpp"
#include <memory>
#include <iostream>

static int wow = 0;

void DisplayControl::draw() {
    static sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
    //static std::shared_ptr<TextButton> button = std::make_shared<TextButton>(sf::Text(font), 30);
    static std::shared_ptr<GameButton> button = std::make_shared<GameButton>();
    button->onClick = []() {
        wow++;
        std::cout << wow << " OOMG IT WAS CLICKED\n";
    };
    //button->changeText("BRUH");
    button->setPosition(sf::Vector2f(0, 0));
    button->setSize(sf::Vector2f(200, 200));
    button->setFillColor(sf::Color::Yellow);
    //button->text.setFillColor(sf::Color::Black);

    ObjectStorage::buttons.push_back(button);

    window.clear(sf::Color(30, 45, 75));
    for (std::shared_ptr<GameButton>& b : ObjectStorage::buttons) {
        b->draw();
    }
    window.display();

}