// src/Game.cpp
#include "Game.hpp"
#include <iostream>
#include<Windows.h>

void switchToEnglishInputMethod() {
    // 先加载英文键盘布局，语言编号+布局标志
    HKL hklEnglish = LoadKeyboardLayout("00000409", KLF_ACTIVATE);
    if (hklEnglish == NULL) return;
    

    // 获得当前窗口句柄
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL) return;
    

    // 发送信息来改变布局为hkl...信息类型为WM_INPUTLANGCHANGEREQUEST（请求改变输入语言）
    PostMessage(hwnd, WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)hklEnglish);
}

Game::Game()
    : mWindow(sf::VideoMode(800, 600), "Breakout Game")
    , mPaddle()
    , mBall()
    , mIsMovingLeft(false)
    , mIsMovingRight(false)
    , score(0)
{
    //切换一下输入法
    switchToEnglishInputMethod();
    // 初始化砖块
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) if(!(i > 2 && 3 < j && j < 8)){
            mBricks.emplace_back(sf::Vector2f(j * 60.0f + 100.0f + j * 2.0f, i * 20.0f + 50.0f + i * 2.0f));
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
    if (!font1.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        // 处理字体加载失败
        return;
    }
    startText.setString("Game starts in 3 seconds...");
    startText.setCharacterSize(48);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(400 - startText.getLocalBounds().width / 2.0f, 300  - startText.getLocalBounds().height / 2.0f); // 设置文本位置
     //等待3秒钟
    while (startClock.getElapsedTime().asSeconds() < 3) {
        // 在等待期间可以显示一个开始画面或空循环
        sf::Color backgroundColor = sf::Color::White;
        mWindow.clear(backgroundColor);
        mWindow.draw(startText);
        mWindow.display();
    }
    sf::Clock clock;
    mBall.isalive = 1;
    while (mWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        if (mBall.isalive == 0) {
            mBall = Ball();
        }
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
sf::FloatRect getBounds(void* a, char type) {
    return type == 'p' ? ((Paddle*)a)->getShape().getGlobalBounds() : ((Ball*)a)->getShape().getGlobalBounds();
}

void Game::update(sf::Time deltaTime) {
    mPaddle.update(deltaTime);

    mBall.update(deltaTime);
    // 检测碰撞
    if (mBall.getShape().getGlobalBounds().intersects(mPaddle.getShape().getGlobalBounds()) && getBounds(&mPaddle,'p').getPosition().y > getBounds(&mBall, 'b').getPosition().y) {
        mBall.reboundPaddle();
    }

    for (auto& brick : mBricks) {
        if (brick.isAlive() && mBall.getShape().getGlobalBounds().intersects(brick.getShape().getGlobalBounds())) {
            mBall.reboundBrick();
            brick.hit();
            score += 1;
        }
    }
}

void Game::render() {
    sf::Color backgroundColor = sf::Color::White;
    mWindow.clear(backgroundColor);
    mWindow.draw(mPaddle.getShape());
    mWindow.draw(mBall.getShape());
    for (const auto& brick : mBricks) {
        if (brick.isAlive()) {
            mWindow.draw(brick.getShape());
        }
    }
    sf::Text scoreText;
    scoreText.setFont(font1);
    scoreText.setString((std::string)"Score: " + std::to_string(score));
    scoreText.setCharacterSize(32);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(650, 10); // 设置文本位置
    mWindow.draw(scoreText);
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
