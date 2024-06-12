// src/Game.cpp
#include "Game.hpp"
using namespace sf;
#define v2f Vector2f


Game::Game()
    : 
    window(VideoMode(GameState::windowSize.x, GameState::windowSize.y), "Breakout Game"),
    gameState(GameState::initLife, 0, 0),
	rm(),
    paddle(GameState::paddlePos, GameState::initPaddleV),
    ball(GameState::initBallPos, GameState::initBallV, 1) //这里有一点别扭，因为并不是所有mode都要用到ball和paddle, TODO考虑职责专一化
{
    
    // 加载字体
	rm.loadFont("main", "resources/fonts/arial.ttf"); //TODO put it in resources
    rm.loadTexture("paddle", "resources/textures/paddle.png");
    rm.loadTexture("ball", "resources/textures/ball.png");
    rm.loadTexture("brick", "resources/textures/brick.png");

    
    //切换输入法
    switchToEnglishInputMethod();
    menu = Menu(rm);
}

void Game::run()
{
    std::cout << "show menu" << std::endl;
	Menu::Selection selection = menu.show(window);

	switch (selection) {
	    case Menu::mode1:
            std::cout << "fuck 1" << std::endl;
		    runSinglePlayer();
		    break;
	    case Menu::mode2:
            std::cout << "fuck 2" << std::endl;
		    runDemo();
		    break;
	    case Menu::settings:
            std::cout << "fuck 3" << std::endl;
		    runSettings();
		    break;
	}
    std::cout << "end run() with mode : " <<  selection << std::endl;
}

void Game::runSinglePlayer() {
    //设置纹理
    std::cout << "at runsingle" << std::endl;
    ball.sprite.setTexture(rm.getTexture("ball"));
    paddle.sprite.setTexture(rm.getTexture("paddle"));
    paddle.sprite.setScale(1.5, 1.5);
    ball.sprite.setScale(0.75, 0.75);
    
    //常用量定义
    const v2f middle(window.getSize().x / 2, window.getSize().y / 2);

    // 初始化砖块
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) if (!(i > 2 && 3 < j && j < 6)) {
            bricks.emplace_back(Brick(v2f(j * 60.0f + 100.0f + j * 2.0f, i * 20.0f + 50.0f + i * 2.0f), v2f(0, 0), 2, rm.getTexture("brick")));
        }
    }

    // 显示还有preparetime开始游戏
    static const int prepareTime = 2;

    std::cout << "tag3" << std::endl;
    //等待3秒钟，让玩家准备
    Clock startClock;
    while (startClock.getElapsedTime().asSeconds() < prepareTime) {
        Color backgroundColor = Color::White;
        window.clear(backgroundColor);
        // 改变startText的内容
        showTextDefult(window, rm, "Prepare to start in " +
            std::to_string(prepareTime - (int)startClock.getElapsedTime().asSeconds()) + " seconds", 48, middle);
        Sleep(1000);
    }
    std::cout << "tag2" << std::endl;
    // 游戏主循环
    Clock clock;
    while (window.isOpen()) {
        Time deltaTime = clock.restart();
        float deltaTimeSec = deltaTime.asSeconds();

        processEvents();
        update(deltaTimeSec);
        render();
    }
}

void Game::runDemo()
{
}

void Game::runSettings()
{
}

void Game::processEvents() {
    //常用量定义
    const v2f middle(window.getSize().x / 2, window.getSize().y / 2);

    // 一般逻辑
    Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                window.close();
                break;
        }
    }

    //小球碰撞逻辑
    
    // 挡板碰撞逻辑
    if (ball.collidWith(paddle)) {
        // 判断是哪个
        FloatRect ballRect = ball.sprite.getGlobalBounds();
        FloatRect paddleRect = paddle.sprite.getGlobalBounds();
        // TODO
        ball.horizentalRebound();
    }

    // 砖块碰撞逻辑
    int tmp = 0;
    for(auto& brick: bricks)
        if (brick.hp && ball.collidWith(brick)) {
            FloatRect ballRect = ball.sprite.getGlobalBounds();
            FloatRect paddleRect = brick.sprite.getGlobalBounds();
            // TODO
            ball.horizentalRebound();
            brick.hit();
            tmp++;
        }
    std::cout << "mark1:" << tmp << std::endl;
    
    //边界碰撞逻辑
    if (ball.pos.x < 0 || ball.pos.x > GameState::windowSize.x) ball.verticalRebound();
    if (ball.pos.y < 0) ball.horizentalRebound();


    //掉出底部
    if (ball.pos.y > GameState::windowSize.y) {
        // 减除一条命
        gameState.life -= 1;
        if (gameState.life == 0) {
            // 游戏结束
            window.clear(Color::White), showTextDefult(window, rm, "Game Over", 48, middle);
            Sleep(3000);
            window.close();

        }
        ball = Ball(GameState::initBallPos, GameState::initBallV, 1, rm.getTexture("ball")); //重新初始化一个球， TODO，资源释放问题
    }

    // 通关逻辑
    if (gameState.score == gameState.totalBrick) {
        window.clear(Color::White), showTextDefult(window, rm, "You Win", 48, middle);
        Sleep(3000);
        window.close();
    }
}

void Game::update(float deltaTime) 
{
    ball.update(deltaTime);
    paddle.update(deltaTime);
    for (auto& brick : bricks) brick.update(deltaTime);

}

void Game::render()
{
    window.clear(Color::White);
    ball.draw(window);
    paddle.draw(window);
    for (auto& brick : bricks) if (brick.hp) { 
        std::cout << "fsdfskdfjhsjkdf" << std::endl;
        brick.draw(window); }
    window.display();
}




