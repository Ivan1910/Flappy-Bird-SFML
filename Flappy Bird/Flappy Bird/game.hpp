#pragma once

#include <SFML/Graphics.hpp>
#include "states.hpp"
#include "mainLoop.hpp"
#include "pipe.hpp"
#include "ground.hpp"

namespace fp {
	class gameScreen : public state {
	public:
		gameScreen(dataRef d);
		void init();
		void pause();
		void resume();
		void inputHandler();
		void update(float time);
		void draw(float time);
	private:
		dataRef dR;
		sf::Sprite gbkgnd;
		std::unique_ptr<pipe> pp;
		std::unique_ptr<ground> gndP;
		sf::Clock clk;
	};
}
