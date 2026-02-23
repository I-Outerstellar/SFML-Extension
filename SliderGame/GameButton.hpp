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

	GameButton(unsigned int zIndex);
public:
	bool active = true, visible = true;

	static std::shared_ptr<GameButton> create(unsigned int zIndex = 0);

	static void remove(std::shared_ptr<GameButton>& button);

	std::function<void()> onClick, onClickRelease;

	bool isPressed() { return this->pressed; };

	virtual void clickEvent();

	virtual void clickReleaseEvent();

	virtual void draw() override;

	virtual ~GameButton() = default;
};