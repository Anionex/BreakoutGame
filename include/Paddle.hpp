// include/Paddle.hpp
#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle();
    void update(sf::Time deltaTime);
    sf::RectangleShape getShape();

private:
    sf::RectangleShape mShape;
    float mSpeed;
};

#endif // PADDLE_HPP
