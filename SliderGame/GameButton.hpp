#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameWindow.hpp"
#include "GameDrawable.hpp"

class GameButton : public sf::RectangleShape, public GameDrawable {
protected:
	bool pressed = false;

	GameButton();
public:
	bool active = true, invisible = false;

	static std::shared_ptr<GameButton> create();

	std::function<void()> onClick, onClickRelease;

	virtual void clickEvent(const sf::Event::MouseButtonPressed& mousePressed);

	virtual void clickReleaseEvent(const sf::Event::MouseButtonReleased& mouseReleased);

	virtual void draw() override;
};