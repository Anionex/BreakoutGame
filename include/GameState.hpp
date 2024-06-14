#pragma once
#include <SFML/Graphics.hpp>
#define v2f Vector2f
using namespace sf;

class GameState {
public:
	GameState();
	GameState(int life, int mode, int round);

	static v2f initBallV, initPaddleV, windowSize;
	static v2f initBallPos, paddlePos;
	static int initLife;
	static v2f ballAcceleration, ballMaxSpeed;

	int score, life, mode, round;
	static int totalBrick;
	static RectangleShape background;
};

