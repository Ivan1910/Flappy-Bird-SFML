#include "menu.hpp"
#include "def.hpp"
#include <sstream>
#include <iostream>


namespace fp {
	menu::menu(dataRef d) :dR(d) {}

	void menu::init() {

		dR->aM.loadTexture("menu background", MENU_BACKGROUND_PATH);
		dR->aM.loadTexture("play button", PLAYBTN_PATH);
		dR->aM.loadTexture("title", TITLE_PATH);
		title.setTexture(this->dR->aM.getTexture("title"));
		playBtn.setTexture(this->dR->aM.getTexture("play button"));
		bkgnd.setTexture(this->dR->aM.getTexture("menu background"));
		playBtn.setPosition((SCREEN_WIDTH / 2) - playBtn.getGlobalBounds().width / 2, (SCREEN_WIDTH / 2) - playBtn.getGlobalBounds().height / 2);
		title.setPosition((SCREEN_WIDTH/2)-title.getGlobalBounds().width/2,title.getGlobalBounds().height/2);
	}

	void menu::inputHandler() {
		sf::Event e;
		while (dR->wnd.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				dR->wnd.close();
			}
			if (dR->iM.spriteClicked(playBtn, sf::Mouse::Left, dR->wnd)) {
				std::cout << "click"; //call game state
			}
		}
	}
    void menu::update(float time) {	}
	void menu::draw(float time) {
		dR->wnd.clear();
		dR->wnd.draw(bkgnd);
		dR->wnd.draw(playBtn);
		dR->wnd.draw(title);
		dR->wnd.display();
	}
	void menu::resume() {}
	void menu::pause() {}
}