#include "inputManager.hpp"

namespace fp {
	sf::Vector2i inputManager::mousePosition(sf::RenderWindow &wnd) {
		return sf::Mouse::getPosition(wnd);
	}
	bool inputManager::spriteClicked(sf::Sprite sprObj, sf::Mouse::Button btn, sf::RenderWindow &wnd) {
		return sf::Mouse::isButtonPressed(btn) &&
			sprObj.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(wnd)));
	}
};