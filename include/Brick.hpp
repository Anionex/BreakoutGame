// include/Brick.hpp
#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(sf::Vector2f position);
    void hit();
    bool isAlive() const;
    sf::RectangleShape getShape() const;

private:
    sf::RectangleShape mShape;
    bool mIsAlive;
};

#endif // BRICK_HPP
