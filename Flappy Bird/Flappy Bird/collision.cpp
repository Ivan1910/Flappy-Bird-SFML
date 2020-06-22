#include "collision.hpp"

namespace fp {
	Collision::Collision() {  };
	bool Collision::spriteCollision(sf::Sprite spr1, sf::Sprite spr2) {
		sf::Rect<float> r1 = spr1.getGlobalBounds();
		sf::Rect<float> r2 = spr2.getGlobalBounds();
		if (r1.intersects(r2)) {
			return true;
		}
		else { return false; }

	};
}