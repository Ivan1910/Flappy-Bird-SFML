#pragma once

#include <SFML/Graphics.hpp>

namespace fp {
	 
	class Collision {
	public:
		Collision();
		bool spriteCollision(sf::Sprite spr1, sf::Sprite spr2);
	};

}