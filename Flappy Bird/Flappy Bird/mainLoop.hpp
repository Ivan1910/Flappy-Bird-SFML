#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include "stateMachine.hpp"
#include "inputManager.hpp"
#include "assetManager.hpp"

namespace fp {
	
	class data {
	public:
		sf::RenderWindow wnd;
		inputManager iM;
		assetManager aM;
		stateMachine sM;
	};
	typedef std::shared_ptr<data> dataRef;
	class game {
	public:
		game(int heigh, int width, std::string name);
	private:
		const float time = 1.0f / 60.0f;
		sf::Clock clk;
		dataRef d = std::make_shared<data>();
		void run();
	};
}

