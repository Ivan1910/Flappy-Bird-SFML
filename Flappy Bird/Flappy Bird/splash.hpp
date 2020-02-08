#pragma once

#include <SFML/Graphics.hpp>
#include "states.hpp"
#include "mainLoop.hpp"

namespace fp {
	class splash : public state{
	public:
		splash(dataRef d);
		void init();
		void pause();
		void resume();
		void inputHandler();
		void update(float time);
		void draw(float time);
	private:
		dataRef dR;
		sf::Clock clk;
		sf::Texture txt;
		sf::Sprite spr;
	};
}
