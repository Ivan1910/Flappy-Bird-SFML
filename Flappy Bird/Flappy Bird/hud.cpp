#include "HUD.hpp"

#include <string>
#include "mainLoop.hpp"


namespace fp
{
	HUD::HUD(dataRef dr) : dR(dr)
	{
		scoreLabel.setFont(this->dR->aM.getFont("fp font"));
		scoreLabel.setString("0");
		scoreLabel.setCharacterSize(SCORE_SIZE);
		scoreLabel.setFillColor(sf::Color::White);
		scoreLabel.setOrigin(sf::Vector2f(scoreLabel.getGlobalBounds().width / 2, scoreLabel.getGlobalBounds().height / 2));
		scoreLabel.setPosition(sf::Vector2f(dR->wnd.getSize().x / 2, dR->wnd.getSize().y / 5));
	}


	void HUD::Draw()
	{
		dR->wnd.draw(scoreLabel);
	}

	void HUD::ScoreUpdate(int score)
	{
		scoreLabel.setString(std::to_string(score));
	}
}