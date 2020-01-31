#include "mainLoop.hpp"

namespace fp {
	game::game(int width, int height, std::string name) {
		d->wnd.create(sf::VideoMode(width, height), name,sf::Style::Close | sf::Style::Titlebar);
		this->run();
	}

	void game::run() {
		float nTime, fTime, intPol;

		float currTime = this->clk.getElapsedTime().asSeconds();
		float acc = 0.0f;

		while (this->d->wnd.isOpen()) {
			this->d->sM.stateChanges();
			nTime = this->clk.getElapsedTime().asSeconds();
			fTime = nTime;

			if (0.25f < fTime) {
				fTime = 0.25;
			}
			currTime = nTime;
			acc += fTime;
			while (time <= acc) {
				this->d->sM.currentState()->inputHandler();
				this->d->sM.currentState()->update(time);
				acc -= time;
			}
			intPol = acc / time;
			this->d->sM.currentState()->draw(intPol);
		}
	}
}