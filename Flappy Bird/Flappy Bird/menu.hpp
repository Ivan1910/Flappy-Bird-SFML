#pragma once

#include <SFML/Graphics.hpp>
#include "states.hpp"
#include "mainLoop.hpp"

namespace fp {
	class menu : public state {
	public:
		menu(dataRef d);
		void init();
		void pause();
		void resume();
		void inputHandler();
		void update(float time);
		void draw(float time);
	private:
		dataRef dR;

		sf::Sprite title;
		sf::Sprite playBtn;
		sf::Sprite bkgnd;
	};
}
