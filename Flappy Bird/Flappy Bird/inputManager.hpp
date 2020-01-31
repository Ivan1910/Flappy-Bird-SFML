#pragma once

#include <SFML/Graphics.hpp>

namespace fp {
	class inputManager {
	public:
		inputManager(){}
		~inputManager(){}

		sf::Vector2i mousePosition(sf::RenderWindow &wnd);
		bool spriteClicked(sf::Sprite sprObj, sf::Mouse::Button btn, sf::RenderWindow &wnd);
					};
	}