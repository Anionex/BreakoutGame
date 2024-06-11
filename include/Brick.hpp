// include/Brick.hpp
#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Brick {
    public:
        Brick(Vector2f position);
        void hit();
        bool isAlive() const;
        RectangleShape getShape() const;

    private:
        RectangleShape mShape;
        bool mIsAlive;
};

#endif // BRICK_HPP
