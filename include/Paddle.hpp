// include/Paddle.hpp
#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
class Paddle {
public:
    Paddle();
    void update(Time deltaTime);
    RectangleShape getShape();

private:
    RectangleShape mShape;
    float mSpeed;
};

#endif // PADDLE_HPP
