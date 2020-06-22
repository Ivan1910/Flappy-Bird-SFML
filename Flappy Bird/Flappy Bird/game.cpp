#include "game.hpp"
#include "def.hpp"
#include <sstream>
#include <iostream>


namespace fp {
	gameScreen::gameScreen(dataRef d) :dR(d) {}

	void gameScreen::init() {

		dR->aM.loadTexture("game background", GAME_BACKGROUND_PATH);
		dR->aM.loadTexture("pipe up", PIPE_UP_PATH);
		dR->aM.loadTexture("pipe dw", PIPE_DW_PATH);
		dR->aM.loadTexture("ground", GROUND_PATH);
		dR->aM.loadTexture("bf1", Player_F1);
		dR->aM.loadTexture("bf2", Player_F2);
		dR->aM.loadTexture("bf3", Player_F3);
		dR->aM.loadTexture("bf4", Player_F4);
		pp = std::unique_ptr<pipe>(new pipe(dR));
		gndP = std::unique_ptr<ground>(new ground(dR));
		bird = std::unique_ptr<Player>(new Player(dR));
		gbkgnd.setTexture(this->dR->aM.getTexture("game background"));

	}

	void gameScreen::inputHandler() {
		sf::Event e;
		while (dR->wnd.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				dR->wnd.close();
			}
			if (this->dR->iM.spriteClicked(this->gbkgnd, sf::Mouse::Left, this->dR->wnd))
			{
				bird->Flap();
			}
		}
	}

	void gameScreen::update(float time) {
		pp->movement(time);
		gndP->movement(time);
		if (clk.getElapsedTime().asSeconds() > PIPE_SPAWN_FQ) {
			pp->randPipe();
			pp->spawnDw();
			pp->spawnUp();
			clk.restart();
		}
		bird->Animation(time);
		bird->Update(time);
	}
	void gameScreen::draw(float time) {
		dR->wnd.clear();
		dR->wnd.draw(gbkgnd);
		pp->drawP();
		gndP->drawG();
		bird->Draw();
		dR->wnd.display();
	}
	void gameScreen::resume() {}
	void gameScreen::pause() {}
}