// include/Game.hpp
#pragma once
#define GAME_HPP

#include <SFML/Graphics.hpp>
using namespace sf;
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "GameObject.hpp"
#include <vector>
#include <iostream>
#include<Windows.h>
#include <string>
#include "utils.hpp"
#include "Menu.hpp"
#include "ResourceManager.hpp"
#include "GameState.hpp"

class Game {
    public:
        Game();
        void run();
        

    private:

        void runSinglePlayer();
        void runDemo();
        void runSettings();

        void processEvents();
        // ball, paddle, bricks的更新
        void update(float deltaTime);  
        // 各种对象的渲染
        void render();  

        RenderWindow window;
		ResourceManager rm;
        GameState gameState;
        Menu menu;

        Paddle paddle;
        Ball ball;
        std::vector<Brick> bricks;



};

