#include "pipe.hpp"
#include "def.hpp"
#include <iostream>
#include <iterator>
#include <time.h>
#include <stdlib.h>
namespace fp {
	pipe::pipe(dataRef d) : dR(d){
		groundHeight = dR->aM.getTexture("ground").getSize().y;
		pipeYOffset = 0;
	}
	void pipe::drawP() {
		for(auto const& spr : pipesSpr) {
			dR->wnd.draw(spr);
		}
	}
	void pipe::spawnDw() {
		sf::Sprite dwSpr(dR->aM.getTexture("pipe dw"));
		dwSpr.setPosition(dR->wnd.getSize().x, dR->wnd.getSize().y - dwSpr.getGlobalBounds().height/2-groundHeight-pipeYOffset);
		pipesSpr.push_back(dwSpr);
	}
	void pipe::spawnUp(){
		sf::Sprite upSpr(dR->aM.getTexture("pipe up"));
		upSpr.setPosition(dR->wnd.getSize().x, -upSpr.getGlobalBounds().height/2-pipeYOffset);
		pipesSpr.push_back(upSpr);
		//std::cout << -pipeYOffset << std::endl; for testing purpose only
	}
	void pipe::movement(float t) {
		for (auto &spr : pipesSpr) {
			if (spr.getPosition().x < 0 - spr.getGlobalBounds().width) {
				pipesSpr.erase(pipesSpr.begin());
			}
		}
		for (auto &spr : pipesSpr) {
			if (!(spr.getPosition().x < 0 - spr.getGlobalBounds().width)) {
				float m = PIPE_SPEED * t;
				spr.move(-m, 0);
			}

		}
	}

	void pipe::randPipe() {
		srand(time(NULL)*10);
		pipeYOffset = rand() % (groundHeight + MAX_PIPE_MOVEMENT);
		switch (rand() % 2) {
		case 0:
			pipeYOffset = -pipeYOffset;
			break;
		case 1:
			pipeYOffset = pipeYOffset;
			break;
		}
	}
}