#include "pipe.hpp"
#include "def.hpp"
#include <iostream>
#include <iterator>
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
		dwSpr.setPosition(dR->wnd.getSize().x, dR->wnd.getSize().y - dwSpr.getGlobalBounds().height-pipeYOffset);
		pipesSpr.push_back(dwSpr);
	}
	void pipe::spawnUp(){
		sf::Sprite upSpr(dR->aM.getTexture("pipe up"));
		upSpr.setPosition(dR->wnd.getSize().x, -pipeYOffset);
		pipesSpr.push_back(upSpr);
	}
	void pipe::spawnScorePipe(){
		sf::Sprite scoreSpr(dR->aM.getTexture("pipe score"));
		scoreSpr.setPosition(dR->wnd.getSize().x, dR->wnd.getSize().y - scoreSpr.getGlobalBounds().height);
		scoreSpr.setColor(sf::Color(0, 0, 0, 0));
		pipesSpr.push_back(scoreSpr);
	}
	void pipe::movement(float t){
		for (auto &spr : pipesSpr) {
			if (spr.getPosition().x < 0 - spr.getGlobalBounds().width) {
		    pipesSpr.erase(pipesSpr.begin());
			}
			else {
				float m = PIPE_SPEED * t;
				spr.move(-m, 0);
			}
				}
	}

	void pipe::randPipe() {
		pipeYOffset = rand() % (groundHeight + 1);
	}
}