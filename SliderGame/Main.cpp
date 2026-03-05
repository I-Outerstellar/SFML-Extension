#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"
#include "GameControllers.hpp"
#include "GameObjects.hpp"
#include <iostream>

/*
    Use this main file as a demo
*/

using namespace GameObjects;

int wow = 0;

/*
    TODO:
    - Research how sprites/images are done in SFML
 */

int main()
{
    std::srand(std::time(nullptr)); //Randomization setup

    /*Creating scenes and showing what they are capable of*/
    static GameScene scene;
    static GameScene scene2;
    SceneControl::switchScene(scene);
    scene.keyPressFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::E)] = []() {
        SceneControl::switchScene(scene2);
        };
    scene2.keyReleaseFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::E)] = []() {
        if (scene2.hasProperty("ReleaseCancel")) scene2.deleteProperty("ReleaseCancel");
        else SceneControl::switchScene(scene);
        };
    scene2.switchedTo = [](GameScene& scene) { //There is also a switchedFrom method
        scene2.setProperty<char*>("ReleaseCancel", nullptr); /*Can be commented out safely*/
        scene2.backgroundColour = { static_cast<uint8_t>(rand() % 128), static_cast<uint8_t>(rand() % 128), static_cast<uint8_t>(rand() % 128) };
        return true;
        };

    /*Creating a text game object*/
    static sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
    static std::shared_ptr<TextButton> button = GameButton::create<TextButton>(sf::Text(font), 42); 
    //When creating these shared pointers via the factory method, it's fine to use auto. This is merely for demonstration purposes.

    /*Defining how a button reacts on click*/
    button->onClick = [](sf::Mouse::Button mouseButton) { //There is also a onClickRelease method
        if (mouseButton != sf::Mouse::Button::Left) return;
        wow++;
        std::cout << std::to_string(wow) << " OMG IT WAS CLICKED\n";
        button->changeText("WOW\n" + std::to_string(wow));
    };
    /*Then setting attributes*/
    button->changeText("WOW");
    button->setPosition({0, 0});
    button->setSize({200, 200});
    button->setFillColor(sf::Color::Yellow);
    button->text.setFillColor(sf::Color::Black);

    /*Creating a rectangle and setting its attributes*/
    static std::shared_ptr<GameRectangle> rect = GameShape::create<GameRectangle>(1); //Unsigned integer is zIndex.
    rect->setPosition({400, 200});
    rect->setSize({200, 200});

    /*Creating a circle and setting its attributes*/
    static std::shared_ptr<GameCircle> circle = GameShape::create<GameCircle>();
    circle->setPosition(sf::Vector2f(400, 200));
    circle->setRadius(100);
    circle->setFillColor(sf::Color(153, 153, 153));
    circle->setOutlineColor(sf::Color::Black);
    circle->setOutlineThickness(2);

    /*Creating a polygon and setting its points*/
    std::shared_ptr<GamePolygon> polygon = GameShape::create<GamePolygon>(1);
    polygon->setPointCount(4);
    polygon->setPoint(0, { 500, 500 });
    polygon->setPoint(1, { 600, 400 });
    polygon->setPoint(2, { 700, 500 });
    polygon->setPoint(3, { 600, 300 });
    /*Then setting its attributes*/
    polygon->setFillColor(sf::Color::Green);
    polygon->setOutlineColor(sf::Color::White);
    polygon->setOutlineThickness(5);


    /*Anything between this and the below comment can be commented out safely*/

    scene.add(button).add(rect).add(circle).add(polygon);
    scene2.add(button);
    //scene.remove(circle); 

    /*Anything between this and the above comment can be commented out safely*/


    WindowControl::beginWindowLoop("Demo", sf::State::Fullscreen, 30);
}