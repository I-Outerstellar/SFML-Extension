#pragma once
#include <SFML/Graphics.hpp>

namespace WindowControl {
	extern void beginWindowLoop(const std::string title, sf::State windowState = sf::State::Windowed, unsigned int fps = 60);
}
