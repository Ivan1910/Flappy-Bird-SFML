#include "mainLoop.hpp"
#include "splash.hpp"
namespace fp {
	game::game(int width, int height, std::string name) {
		d->wnd.create(sf::VideoMode(width, height), name,sf::Style::Close | sf::Style::Titlebar);
		d->sM.stateToStack(sRef(new splash(this->d)));
		this->run();
	}

	void game::run() {
		float nTime, fTime, intPol;

		float currTime = this->clk.getElapsedTime().asSeconds();
		float acc = 0.0f;

		while (this->d->wnd.isOpen()) {
			this->d->sM.stateChanges();
			nTime = this->clk.getElapsedTime().asSeconds();
			fTime = nTime - currTime;                       //duration between frames

			if (0.25f < fTime) {
				fTime = 0.25f;
			}
			currTime = nTime;
			acc += fTime;
			while (deltaT <= acc) {                            //framerate independent motion
				this->d->sM.currentState()->inputHandler();
				this->d->sM.currentState()->update(deltaT);
				acc -= deltaT;
			}
			intPol = acc / deltaT;
			this->d->sM.currentState()->draw(intPol);
		}
	}
}