#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GameWindow.hpp"
#include "GameDrawable.hpp"
#include "EventHandler.hpp"

class GameButton : public sf::RectangleShape, public GameDrawable {
protected:
	bool pressed = false;
public:
	bool active = true, invisible = false;

	GameButton() :
	RectangleShape() {}

	std::function<void()> onClick, onClickRelease;

	virtual void clickEvent(const sf::Event::MouseButtonPressed& mousePressed) {
		if (this->pressed || !this->active) return;
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (!this->getGlobalBounds().contains(mousePos))
			return;
		this->pressed = true;
		if (onClick != NULL)
			onClick();
	}

	virtual void clickReleaseEvent(const sf::Event::MouseButtonReleased& mouseReleased) {
		if (!this->pressed) return;
		this->pressed = false;
		if (onClickRelease != NULL)
			onClickRelease();
	}

	virtual void draw() override {
		window.draw(*this);
	}
};