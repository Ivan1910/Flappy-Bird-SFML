#include "player.hpp"

namespace fp { 
	Player::Player(dataRef d) : dR(d){
		animIterator = 0;
		animFrames.push_back(dR->aM.getTexture("bf1"));
		animFrames.push_back(dR->aM.getTexture("bf2"));
		animFrames.push_back(dR->aM.getTexture("bf3"));
		animFrames.push_back(dR->aM.getTexture("bf4"));

		birdSpr.setTexture(animFrames.at(animIterator));
	birdSpr.setPosition(dR->wnd.getSize().x / 4 - birdSpr.getGlobalBounds().width / 2, dR->wnd.getSize().y / 2 - birdSpr.getGlobalBounds().height / 2);
	birdState = STATE_STILL;

	}
	void Player::Draw() {
		dR->wnd.draw(birdSpr);
	}

	void Player::Animation(float deltaT) {
		if (clk.getElapsedTime().asSeconds() > BIRD_ANIM / animFrames.size()) {
			if (animIterator < animFrames.size() - 1) {
				animIterator++;
			}
			else {
				animIterator = 0;
			}
			birdSpr.setTexture(animFrames.at(animIterator));
			clk.restart();
		}
	}

	void Player::Update(float deltaT) {

		if (STATE_FALL == birdState) {
			birdSpr.move(0, GRAVITY*deltaT);
		}
		else if (STATE_FLY == birdState) {
			birdSpr.move(0, -FLY_SPEED*deltaT);
		}
		if (moveClk.getElapsedTime().asSeconds() > FLY_DURATION) {
			moveClk.restart();
			birdState = STATE_FALL;
		}
	}

	void Player::Flap() {
		moveClk.restart();
		birdState = STATE_FLY;
	}

	const sf::Sprite &Player::GetSprite() const {
		return birdSpr;
	}

}