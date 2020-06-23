#pragma once

#include <SFML/Graphics.hpp>
#include "def.hpp"
#include "mainLoop.hpp"

namespace fp
{
	class HUD
	{
	public:
		HUD(dataRef dt);
		void Draw();
		void ScoreUpdate(int score);
	private:
		dataRef dR;
		sf::Text scoreLabel;
	};
}
