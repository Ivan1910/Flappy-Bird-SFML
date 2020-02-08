#pragma once

#include <SFML/Graphics.hpp>

namespace fp {
	class inputManager {
	public:
		inputManager(){}
		~inputManager(){}

		sf::Vector2i mousePosition(sf::RenderWindow &wnd);
		bool spriteClicked(const sf::Sprite &sprObj,const sf::Mouse::Button &btn,const sf::RenderWindow &wnd);
					};
	}