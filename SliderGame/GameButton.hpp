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
	bool active = true, visible = true;

	static std::shared_ptr<GameButton> create();

	std::function<void()> onClick, onClickRelease;

	virtual void clickEvent();

	virtual void clickReleaseEvent();

	virtual void draw() override;
};