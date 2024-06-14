#include"GameState.hpp"
 v2f GameState::windowSize = v2f(800, 800);
 v2f GameState::paddlePos = v2f(350, 750);
 v2f GameState::initPaddleV = v2f(400, 0);
 v2f GameState::initBallPos = v2f(200, 175);
 v2f GameState::initBallV = v2f(-200, 200);
 int GameState::initLife = 3;
 v2f GameState::ballAcceleration = v2f(25, 25);
 v2f GameState::ballMaxSpeed = v2f(400, 400);
int GameState::totalBrick;
RectangleShape GameState::background;


GameState::GameState(int life, int mode, int round) {
	this->life = life;
	this->mode = mode;
	this->round = round;
	score = 0;
}