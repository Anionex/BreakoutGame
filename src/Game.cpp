// src/Game.cpp
#include "Game.hpp"
#include <iostream>

Game::Game()
    : mWindow(sf::VideoMode(800, 600), "Breakout Game")
    , mPaddle()
    , mBall()
    , mIsMovingLeft(false)
    , mIsMovingRight(false)
{
    // 初始化砖块
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            mBricks.emplace_back(sf::Vector2f(j * 60.0f + 100.0f, i * 20.0f + 50.0f));
        }
    }
}

void Game::run() {
    sf::Clock startClock;

    sf::Font font;
    sf::Text startText;
    startText.setFont(font); 
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        // 处理字体加载失败
        return;
    }
    startText.setString("Game starts in 3 seconds...");
    startText.setCharacterSize(36);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(100, 100); // 设置文本位置
    // 等待3秒钟
    while (startClock.getElapsedTime().asSeconds() < 3) {
        // 在等待期间可以显示一个开始画面或空循环
        mWindow.clear();
        mWindow.draw(startText);
        mWindow.display();
    }

    sf::Clock clock;
    mBall.isalive = 1;
    while (mWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        if (mBall.isalive == 0) return;
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    mPaddle.update(deltaTime);

    mBall.update(deltaTime);
    // 检测碰撞
    if (mBall.getShape().getGlobalBounds().intersects(mPaddle.getShape().getGlobalBounds())) {
        mBall.reboundPaddle();
    }

    for (auto& brick : mBricks) {
        if (brick.isAlive() && mBall.getShape().getGlobalBounds().intersects(brick.getShape().getGlobalBounds())) {
            mBall.reboundBrick();
            brick.hit();
        }
    }
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPaddle.getShape());
    mWindow.draw(mBall.getShape());
    for (const auto& brick : mBricks) {
        if (brick.isAlive()) {
            mWindow.draw(brick.getShape());
        }
    }
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    }
    else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    }
}
