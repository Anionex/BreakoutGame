#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Paddle : public GameObject {
public:
    Paddle();
    Paddle(Vector2f pos, Vector2f velocity);
    Paddle(Vector2f pos, Vector2f velocity, int hp);
    void update(float deltaTime);
    void draw(RenderWindow& window);

private:
};
