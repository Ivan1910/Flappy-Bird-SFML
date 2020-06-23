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
		void movement(float t);
		void randPipe();
		void spawnScorePoint();
		const std::vector<sf::Sprite> &GetSprites() const;
		std::vector<sf::Sprite> &GetScoringSprites();
	private:
		dataRef dR;
		std::vector<sf::Sprite> pipesSpr;
		std::vector<sf::Sprite> scoringPointSpr;
		int groundHeight;
		int pipeYOffset;
	};

}
