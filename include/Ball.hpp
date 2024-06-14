#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Ball : public GameObject {
public:
    Ball();
    Ball(Vector2f pos, Vector2f velocity);
    Ball(Vector2f pos, Vector2f velocity, int hp);
    Ball(Vector2f pos, Vector2f velocity, int hp, const Texture& texture);
    v2f accelarate;
    bool collidWith(const GameObject& B) override;
    void update(float deltaTime);
    void draw(RenderWindow& window);
    void verticalRebound();
    void horizentalRebound();
    Clock ballClock;
	static const Time reboundCoolDown;

private:
};
