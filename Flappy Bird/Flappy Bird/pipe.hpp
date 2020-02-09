#pragma once

#include <SFML/Graphics.hpp>
#include "mainLoop.hpp"
#include <vector>

namespace fp{
	class pipe {
	public:
		pipe(dataRef d);
		void drawP();
		void spawnUp();
		void spawnDw();
		void spawnScorePipe();
		void movement(float t);
		void randPipe();
	private:
		dataRef dR;
		std::vector<sf::Sprite> pipesSpr;
		int landHeight;
		int pipeYOffset;
	};

}
