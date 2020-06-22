#include "player.hpp"

namespace fp { 
	Player::Player(dataRef d) : dR(d){
		birdSpr.setTexture(dR->aM.getTexture("bf1"));
	}
	void Player::Draw() {
		dR->wnd.draw(birdSpr);
	}
}