#pragma once

#include "def.hpp"
#include <iostream>
#include <fstream>
#include "endGameState.hpp"
#include "game.hpp"

namespace fp
{
	GameOverState::GameOverState(dataRef dr,int score) : dR(dr),scoreC(score){}

	void GameOverState::init()
	{
		std::ifstream readF;
		readF.open(HIGHSCORE);
		if (readF.is_open()) {
			while (!readF.eof()) {
				readF >> highscoreC;
			}
		}
		readF.close();
		std::ofstream writeF;
		writeF.open(HIGHSCORE);
		if (writeF.is_open()) {
			if (scoreC > highscoreC) {
				highscoreC = scoreC;
			}
			writeF << highscoreC;
		}
		writeF.close();
		this->dR->aM.loadTexture("game over", GAME_OVER_BKGND);
		this->dR->aM.loadTexture("body", SCORE_BODY);
		this->dR->aM.loadTexture("title", GAME_OVER_TEXT);
		this->dR->aM.loadTexture("button", RESTART_BUTTON);

		this->dR->aM.loadTexture("bronze", BRONZE);
		this->dR->aM.loadTexture("silver", SILVER);
		this->dR->aM.loadTexture("gold", GOLD);
		this->dR->aM.loadTexture("platinum", PLATINUM);


		bckgrd.setTexture(this->dR->aM.getTexture("game over"));
		scorebody.setTexture(this->dR->aM.getTexture("body"));
		title.setTexture(this->dR->aM.getTexture("title"));
		newgame.setTexture(this->dR->aM.getTexture("button"));

		scorebody.setPosition(dR->wnd.getSize().x / 2 - scorebody.getGlobalBounds().width / 2, dR->wnd.getSize().y / 2 - scorebody.getGlobalBounds().height / 2);
		title.setPosition(dR->wnd.getSize().x / 2 - title.getGlobalBounds().width / 2, scorebody.getPosition().y - title.getGlobalBounds().height*1.2);
		newgame.setPosition(dR->wnd.getSize().x / 2 - newgame.getGlobalBounds().width / 2, scorebody.getPosition().y + scorebody.getGlobalBounds().height + newgame.getGlobalBounds().height*0.2);

		score.setFont(dR->aM.getFont("fp font"));
		score.setString(std::to_string(scoreC));
		score.setCharacterSize(20);
		score.setFillColor(sf::Color::White);
		score.setOrigin(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 2);
		score.setPosition(dR->wnd.getSize().x / 10 * 7.25, dR->wnd.getSize().y / 2.15);

		highscore.setFont(dR->aM.getFont("fp font"));
		highscore.setString(std::to_string(highscoreC));
		highscore.setCharacterSize(20);
		highscore.setFillColor(sf::Color::White);
		highscore.setOrigin(highscore.getGlobalBounds().width / 2, highscore.getGlobalBounds().height / 2);
		highscore.setPosition(dR->wnd.getSize().x / 10 * 7.25, dR->wnd.getSize().y / 1.78);

		if (scoreC >= 0 && scoreC <= SILVERSCORE) {
			medal.setTexture(dR->aM.getTexture("bronze"));
		}
		else if (scoreC > SILVERSCORE && scoreC <= GOLDSCORE) {
			medal.setTexture(dR->aM.getTexture("silver"));
		}
		else if (scoreC > GOLDSCORE && scoreC <= PLATINUMSCORE) {
			medal.setTexture(dR->aM.getTexture("gold"));
		}
		else if (scoreC >= PLATINUMSCORE) {
			medal.setTexture(dR->aM.getTexture("platinum"));
		}
		medal.setPosition(120, 275);
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
		this->dR->wnd.draw(this->score);
		this->dR->wnd.draw(this->highscore);
		this->dR->wnd.draw(this->medal);
		this->dR->wnd.display();
	}
	void GameOverState::pause() {};
	void GameOverState::resume() {};
}