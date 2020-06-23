#pragma once

#include <SFML/Graphics.hpp>
#include "states.hpp"
#include "player.hpp"
#include "mainLoop.hpp"
#include "ground.hpp"
#include "pipe.hpp"
#include "hud.hpp"
#include "collision.hpp"



namespace fp {
	class gameScreen : public state {
	public:
		gameScreen(dataRef d);
		void init();
		void resume();
		void pause();
		void inputHandler();
		void update(float time);
		void draw(float time);
	private:
		dataRef dR;
		sf::Sprite gbkgnd;	
		std::unique_ptr<HUD> hud;
		std::unique_ptr<pipe> pp;
		std::unique_ptr<ground> gndP;
		std::unique_ptr<Player> bird;
		sf::Clock clk;
		Collision coll;
		int gameState;
	    sf::Clock clickTimer;
		int scoreCounter = 0;
	};
}
