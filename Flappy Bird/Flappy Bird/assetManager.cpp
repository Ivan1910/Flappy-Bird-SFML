#include "assetManager.hpp"

namespace fp {

	void assetManager::loadFont(std::string fontName, std::string fileName) {
		sf::Font f;
		if (f.loadFromFile(fileName)) {
			this->fonts[fontName] = f;
		}
	}

	sf::Font &assetManager::getFont(std::string fontName) {
		return this->fonts.at(fontName);
	}

	void assetManager::loadTexture(std::string textureName, std::string fileName) {
		sf::Texture t;
		if (t.loadFromFile(fileName)) {
			this->textures[textureName] = t;
		}
	}

	sf::Texture &assetManager::getTexture(std::string textureName) {
		return this->textures.at(textureName);
	}

}