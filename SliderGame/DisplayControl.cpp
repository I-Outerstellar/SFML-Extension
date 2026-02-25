#include "DisplayControl.hpp"
#include "GameButton.hpp"
#include "GameShape.hpp"
#include "ObjStorageData.hpp"
#include <memory>
#include <iostream>

void DisplayControl::draw() {
    window.clear(sf::Color(30, 45, 75));
    for (auto& s : ObjectStorage::shapes) {
        if (s->visible)
            s->draw();
    }
    for (auto& b : ObjectStorage::buttons) {
        if (b->visible)
            b->draw();
    }
    window.display();

}