#pragma once

#define CLICK_FQ 0.05f

#define PIPE_DISTANCE 20
#define MAX_PIPE_MOVEMENT 30

#define HIGHSCORE "../Resources/highscore.txt"

#define SCORE_BODY "../Resources/scorebody.png"
#define GAME_OVER_TEXT "../Resources/gameover.png"
#define GAME_OVER_BKGND "../Resources/bkgnd.png"
#define RESTART_BUTTON "../Resources/play.png"

#define GOLD "../Resources/gold.png"
#define BRONZE "../Resources/bronze.png"
#define SILVER "../Resources/silver.png"
#define PLATINUM "../Resources/platinum.png"

#define BRONZESCORE 0
#define SILVERSCORE 2
#define GOLDSCORE 50
#define PLATINUMSCORE 100

#define SCORE_SIZE 60
#define SCORE_POINT_WIDTH 15

#define Player_F1 "../Resources/f1.png"
#define Player_F2 "../Resources/f2.png"
#define Player_F3 "../Resources/f3.png"
#define Player_F4 "../Resources/f4.png"

#define ScorePoint "../Resources/scorePoint.png"
#define FP_FONT "../Resources/FlappyFont.ttf"

#define STATE_STILL 1
#define STATE_FALL 2
#define STATE_FLY 3
#define GRAVITY 350.0f
#define FLY_SPEED 200.0f
#define FLY_DURATION 0.25f

#define BIRD_ANIM 0.8f

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 600

#define SPLASH_TIME 2.0

#define PIPE_SPAWN_FQ 2.0f
#define PIPE_SPEED 200.0f

#define TITLE_PATH "../Resources/flappybird.png"
#define PLAYBTN_PATH "../Resources/play.png"
#define MENU_BACKGROUND_PATH "../Resources/bkgnd.png"
#define SPLASH_PATH "../Resources/Splash.png"
#define GAME_BACKGROUND_PATH "../Resources/bkgnd.png"
#define PIPE_UP_PATH "../Resources/dwpipe.png"
#define PIPE_DW_PATH "../Resources/uppipe.png"
#define GROUND_PATH "../Resources/ground.png"

enum gameStates {
	ePreGameState,
	eGameState,
	eGameOverState
};
