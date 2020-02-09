#include "game.hpp"
#include "def.hpp"
#include <sstream>
#include <iostream>


namespace fp {
	gameScreen::gameScreen(dataRef d) :dR(d) {}

	void gameScreen::init() {

		dR->aM.loadTexture("game background", GAME_BACKGROUND_PATH);
		dR->aM.loadTexture("pipe up",PIPE_UP_PATH);
		dR->aM.loadTexture("pipe dw", PIPE_DW_PATH);
		dR->aM.loadTexture("pipe score", PIPE_SCORE_PATH);
		dR->aM.loadTexture("ground", GROUND_PATH);
		pp = std::unique_ptr<pipe>(new pipe(dR));
		gndP = std::unique_ptr<ground>(new ground(dR));
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
		pp->movement(time);
		gndP->movement(time);
		if (clk.getElapsedTime().asSeconds() > PIPE_SPAWN_FQ) {
			pp->spawnScorePipe();
			pp->spawnDw();
			pp->spawnUp();
			clk.restart();
		}
	}
	void gameScreen::draw(float time) {
		dR->wnd.clear();
		dR->wnd.draw(gbkgnd);
		pp->drawP();
		gndP->drawG();
		dR->wnd.display();
	}
	void gameScreen::resume() {}
	void gameScreen::pause() {}
}