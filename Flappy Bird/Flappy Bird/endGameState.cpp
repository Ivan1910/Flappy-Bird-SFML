#pragma once

#include "def.hpp"
#include <iostream>
#include <sstream>
#include "endGameState.hpp"
#include "game.hpp"

namespace fp
{
	GameOverState::GameOverState(dataRef dr) : dR(dr){}

	void GameOverState::init()
	{
		this->dR->aM.loadTexture("game over", GAME_OVER_BKGND);
		this->dR->aM.loadTexture("body", SCORE_BODY);
		this->dR->aM.loadTexture("title", GAME_OVER_TEXT);
		this->dR->aM.loadTexture("button", RESTART_BUTTON);

		bckgrd.setTexture(this->dR->aM.getTexture("game over"));
		scorebody.setTexture(this->dR->aM.getTexture("body"));
		title.setTexture(this->dR->aM.getTexture("title"));
		newgame.setTexture(this->dR->aM.getTexture("button"));

		scorebody.setPosition(dR->wnd.getSize().x / 2 - scorebody.getGlobalBounds().width / 2, dR->wnd.getSize().y / 2 - scorebody.getGlobalBounds().height / 2);
		title.setPosition(dR->wnd.getSize().x / 2 - title.getGlobalBounds().width / 2,scorebody.getPosition().y-title.getGlobalBounds().height*1.2);
		newgame.setPosition(dR->wnd.getSize().x / 2 - newgame.getGlobalBounds().width / 2,scorebody.getPosition().y+scorebody.getGlobalBounds().height+newgame.getGlobalBounds().height*0.2);
	}

	void GameOverState::inputHandler()
	{
		sf::Event event;

		while (this->dR->wnd.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->dR->wnd.close();
			}
			if (dR->iM.spriteClicked(newgame, sf::Mouse::Left, dR->wnd)) {
				dR->sM.stateToStack(sRef(new gameScreen(dR)),true);
			}
		}
	}

	void GameOverState::update(float dt){}

	void GameOverState::draw(float dt)
	{
		this->dR->wnd.clear();
		this->dR->wnd.draw(this->bckgrd);
		this->dR->wnd.draw(this->title);
		this->dR->wnd.draw(this->scorebody);
		this->dR->wnd.draw(this->newgame);

		this->dR->wnd.display();
	}
	void GameOverState::pause() {};
	void GameOverState::resume() {};
}