#pragma once
#include <SFML/Graphics.hpp>
#define v2f Vector2f
using namespace sf;

class GameState {
public:
	GameState(int life, int mode, int round);

	static const v2f initBallV, initPaddleV, windowSize;
	static const v2f initBallPos, paddlePos;
	static const int initLife;

	int score, life, mode, round;
	const int totalBrick;
};