#include "splash.hpp"
#include "def.hpp"
#include "menu.hpp"
#include <sstream>
#include <iostream>


namespace fp {
	splash::splash(dataRef d) :dR(d){}
	
	void splash::init(){
	
		dR->aM.loadTexture("splash", SPLASH_PATH);
		spr.setTexture(this->dR->aM.getTexture("splash"));
	}

	void splash::inputHandler() {
		sf::Event e;
		while (dR->wnd.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				dR->wnd.close();
			}
		}
	}

	void splash::update(float time) {
		if (clk.getElapsedTime().asSeconds() > SPLASH_TIME) {
			dR->sM.stateToStack(sRef(new menu(dR)),true); 
		}
	}
	void splash::draw(float time) {
		dR->wnd.clear();
		dR->wnd.draw(spr);
		dR->wnd.display();
	}
   void splash::resume(){}
   void splash::pause() {}
}