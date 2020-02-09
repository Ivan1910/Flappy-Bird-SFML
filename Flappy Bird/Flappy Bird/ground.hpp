#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "mainLoop.hpp"

namespace fp {

	class ground {
	public:
		ground(dataRef d);
		void movement(float t);
		void drawG();
	private:
		std::vector<sf::Sprite> gnd;
		dataRef dR;

	};

}
