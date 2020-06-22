#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "mainLoop.hpp"
#include "def.hpp"

namespace fp {

	class Player {
	public:
		Player(dataRef d);
		void Draw();
		void Animation(float deltaT);
		void Flap();
		void Update(float deltaT);
	private:
		dataRef dR;
		sf::Clock clk;
		sf::Clock moveClk;
		int birdState;
		sf::Sprite birdSpr;
		std::vector<sf::Texture> animFrames;
	    int animIterator;
	};
}

