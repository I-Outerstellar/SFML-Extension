#pragma once
#include <SFML/Graphics.hpp>

namespace GameObjects {

	class TextImplement {
	protected:

	public:
		sf::Text text;

		TextImplement(const sf::Text& text) : text(text) {}

		virtual void changeText(std::string text) = 0;
		virtual ~TextImplement() = default;
	};

}