#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Brick : public GameObject{
public:
    Brick(Vector2f pos, Vector2f velocity);
    Brick(Vector2f pos, Vector2f velocity, int hp);
    Brick(Vector2f pos, Vector2f velocity, int hp, const Texture& texture);
    void update(float deltaTime);
    void draw(RenderWindow& window);
    void hit();

private:
};


