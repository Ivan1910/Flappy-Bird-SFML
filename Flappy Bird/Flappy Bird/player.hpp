#pragma once

#include <SFML/Graphics.hpp>
#include "mainLoop.hpp"
#include "def.hpp"

namespace fp {

	class Player {
	public:
		Player(dataRef d);
		void Draw();
	private:
		dataRef dR;
		sf::Sprite birdSpr;
	};
}

