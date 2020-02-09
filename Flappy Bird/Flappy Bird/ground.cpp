#include "def.hpp"
#include "ground.hpp"

namespace fp {
	ground::ground(dataRef d) :dR(d) {
		sf::Sprite gndSpr(dR->aM.getTexture("ground"));
		sf::Sprite gndSpr2(dR->aM.getTexture("ground"));

		gndSpr.setPosition(0, dR->wnd.getSize().y - gndSpr.getGlobalBounds().height);
		gndSpr2.setPosition(gndSpr.getGlobalBounds().width, dR->wnd.getSize().y - gndSpr.getGlobalBounds().height);
		gnd.push_back(gndSpr);
		gnd.push_back(gndSpr2);
	}
		void ground::movement(float t){
			for (auto &spr : gnd) {
				float mov = PIPE_SPEED * t;
				spr.move(-mov,0.0f);
				if (spr.getPosition().x < 0 - spr.getGlobalBounds().width) {
					sf::Vector2f pos(dR->wnd.getSize().x, spr.getPosition().y);
					spr.setPosition(pos);

				}
			}
		
		}
	void ground::drawG(){
		for (auto &spr : gnd) {
			dR->wnd.draw(spr);
		}
	}
}