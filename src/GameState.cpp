#include"GameState.hpp"
const v2f GameState::windowSize = v2f(800, 600);
const v2f GameState::paddlePos = v2f(350, 550);
const v2f GameState::initPaddleV = v2f(400, 0);
const v2f GameState::initBallPos = v2f(200, 450);
const v2f GameState::initBallV = v2f(400, 400);
const int GameState::initLife = 100;


GameState::GameState(int life, int mode, int round) :

	totalBrick(46) {
	this->life = life;
	this->mode = mode;
	this->round = round;
	score = 0;
}