#include "game.hpp"
#include "def.hpp"
#include <sstream>
#include <iostream>
#include "endGameState.hpp"

namespace fp {
	gameScreen::gameScreen(dataRef d) :dR(d) {}

	void gameScreen::init() {

		dR->aM.loadTexture("game background", GAME_BACKGROUND_PATH);
		dR->aM.loadTexture("pipe up", PIPE_UP_PATH);
		dR->aM.loadTexture("pipe dw", PIPE_DW_PATH);
		dR->aM.loadTexture("ground", GROUND_PATH);
		dR->aM.loadTexture("bf1", Player_F1);
		dR->aM.loadTexture("bf2", Player_F2);
		dR->aM.loadTexture("bf3", Player_F3);
		dR->aM.loadTexture("bf4", Player_F4);
		dR->aM.loadTexture("score point", ScorePoint);
		dR->aM.loadFont("fp font", FP_FONT);

		hud = std::unique_ptr<HUD>(new HUD(dR));
		pp = std::unique_ptr<pipe>(new pipe(dR));
		gndP = std::unique_ptr<ground>(new ground(dR));
		bird = std::unique_ptr<Player>(new Player(dR));
		gbkgnd.setTexture(this->dR->aM.getTexture("game background"));
		gameState = ePreGameState;
	}
	void gameScreen::resume() {}
	void gameScreen::pause() {}

	void gameScreen::inputHandler() {
		sf::Event e;
		while (dR->wnd.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				dR->wnd.close();
			}
			if (this->dR->iM.spriteClicked(this->gbkgnd, sf::Mouse::Left, this->dR->wnd))
			{
				if (gameState != eGameOverState && clickTimer.getElapsedTime().asSeconds() > CLICK_FQ) {
					clickTimer.restart();
					gameState = eGameState;
					bird->Flap();
				}
			}
		}
	}

	void gameScreen::update(float time) {
		if (gameState != eGameOverState) {
			bird->Animation(time);
			gndP->movement(time);
		}
		if (gameState == eGameState) {
			pp->movement(time);
			if (clk.getElapsedTime().asSeconds() > PIPE_SPAWN_FQ) {
				pp->randPipe();
				pp->spawnDw();
				pp->spawnUp();
				pp->spawnScorePoint();
				clk.restart();
			}
			bird->Update(time);
			std::vector<sf::Sprite> gndSpr = gndP->GetSprites();
			for (auto spr : gndSpr)
			{
				if (coll.spriteCollision(bird->GetSprite(),spr))
				{
					gameState = eGameOverState;
				}
			}
			std::vector<sf::Sprite> pipesSpr = pp->GetSprites();

			for (auto spr : pipesSpr)
			{
				if (coll.spriteCollision(bird->GetSprite(), spr))
				{
					gameState = eGameOverState;
				}
			}
			if (gameState == eGameState) {
				std::vector<sf::Sprite> &scoringPipeSpr = pp->GetScoringSprites();
				for (int i = 0; i < scoringPipeSpr.size(); i++)
				{
					if (coll.spriteCollision(bird->GetSprite(), scoringPipeSpr.at(i)))
					{
						++scoreCounter;
						hud->ScoreUpdate(scoreCounter);
				     	scoringPipeSpr.erase(scoringPipeSpr.begin() + i);
					}
				}
			}
			if (eGameOverState == gameState)
			{
				dR->sM.stateToStack(sRef(new GameOverState(dR)),true);
			}
		}
	}
	void gameScreen::draw(float time) {
		dR->wnd.clear();
		dR->wnd.draw(gbkgnd);
		pp->drawP();
		gndP->drawG();
		bird->Draw();
		hud->Draw();
		dR->wnd.display();
	}

}