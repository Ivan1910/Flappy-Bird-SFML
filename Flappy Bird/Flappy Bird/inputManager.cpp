#include "inputManager.hpp"

namespace fp {
	sf::Vector2i inputManager::mousePosition(sf::RenderWindow &wnd) {
		return sf::Mouse::getPosition(wnd);
	}
	bool inputManager::spriteClicked(const sf::Sprite &sprObj,const sf::Mouse::Button &btn,const sf::RenderWindow &wnd) {
		return sf::Mouse::isButtonPressed(btn) &&
			sprObj.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(wnd)));
	}
};