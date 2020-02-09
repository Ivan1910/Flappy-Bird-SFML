#include "game.hpp"
#include "def.hpp"
#include <sstream>
#include <iostream>


namespace fp {
	gameScreen::gameScreen(dataRef d) :dR(d) {}

	void gameScreen::init() {

		dR->aM.loadTexture("game background", GAME_BACKGROUND_PATH);
		gbkgnd.setTexture(this->dR->aM.getTexture("game background"));
	}

	void gameScreen::inputHandler() {
		sf::Event e;
		while (dR->wnd.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				dR->wnd.close();
			}
		}
	}

	void gameScreen::update(float time) {

	}
	void gameScreen::draw(float time) {
		dR->wnd.clear();
		dR->wnd.draw(gbkgnd);
		dR->wnd.display();
	}
	void gameScreen::resume() {}
	void gameScreen::pause() {}
}