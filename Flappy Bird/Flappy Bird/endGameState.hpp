#pragma once

#include <SFML/Graphics.hpp>
#include "states.hpp"
#include "mainLoop.hpp"

namespace fp
{
	class GameOverState : public state
	{
	public:
		GameOverState(dataRef dr,int score);
        void init();
		void inputHandler();
		void update(float deltaT);
		void pause();
		void resume();
		void draw(float deltaT);

	private:
		dataRef dR;
		int scoreC;
	    int highscoreC;
		sf::Text highscore;
		sf::Text score;
		sf::Sprite scorebody;
		sf::Sprite title;
		sf::Sprite newgame;
		sf::Sprite bckgrd;
	};
}