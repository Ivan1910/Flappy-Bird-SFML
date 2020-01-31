#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace fp {
	class assetManager {
	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;
	public:
		assetManager(){}
		~assetManager() {}

		void loadFont(std::string fontName, std::string fileName);
		sf::Font &getFont(std::string fontName);
		void loadTexture(std::string textureName, std::string fileName);
		sf::Texture &getTexture(std::string textureName);

	};

}