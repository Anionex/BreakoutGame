// src/Game.cpp
#include "Game.hpp"
using namespace sf;

Game::Game()
    : mWindow(VideoMode(800, 600), "Breakout Game")
    , mPaddle()
    , mBall()
    , mIsMovingLeft(false)
    , mIsMovingRight(false)
    , score(0)
	, totalBrick(46)
	, life(3)

{
    // 从 C:\\Windows\\Fonts\\arial.ttf加载字体
    if (!font1.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
		//加载字体fail
		std::cout << "Error loading font\n";
    }
    //切换一下输入法
    switchToEnglishInputMethod();
    // 初始化砖块
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) if(!(i > 2 && 3 < j && j < 6)){
            mBricks.emplace_back(Vector2f(j * 60.0f + 100.0f + j * 2.0f, i * 20.0f + 50.0f + i * 2.0f));
        }
    }
}

void Game::run() {
    
    Clock startClock;
    static const int prepareTime = 2;
	// 字体，大小，显示还有preparetime开始游戏
    Text startText(
        "Prepare to start in " + std::to_string(prepareTime) + " seconds",
        font1, 
        48
    );
	startText.setColor(Color::Black);
	startText.setPosition(400 - startText.getLocalBounds().width / 2.0f, 250 - startText.getLocalBounds().height / 2.0f); // 设置文本位置


     //等待3秒钟，让玩家准备
    while (startClock.getElapsedTime().asSeconds() < prepareTime) {
        Color backgroundColor = Color::White;
        mWindow.clear(backgroundColor);
		// 改变startText的内容
		startText.setString("Prepare to start in " + 
                std::to_string(prepareTime - (int)startClock.getElapsedTime().asSeconds()) +
                " seconds"
        );
        mWindow.draw(startText), mWindow.display();
        Sleep(1000);
    }
    Clock clock;
    mBall.isalive = 1;
    while (mWindow.isOpen()) {
        Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        if (mBall.isalive == 0) {
			// 减除一条命
			life -= 1;
			if (life == 0) {
				// 游戏结束
				Text endText;
				endText = Text("Game Over!", font1, 48);
                endText.setColor(Color::Black);
				endText.setPosition(
                    400 - endText.getLocalBounds().width / 2.0f, 
                    300 - endText.getLocalBounds().height / 2.0f
                ); // 设置文本位置
				mWindow.clear(Color::White),
				mWindow.draw(endText), mWindow.display();
				Sleep(3000);
				mWindow.close();

            }
            mBall = Ball();
        }
        if (score == totalBrick) {
            // 通关了
			Text winText;
			winText = Text("You Win!", font1, 48);
			winText.setPosition(400 - winText.getLocalBounds().width / 2.0f, 300 - winText.getLocalBounds().height / 2.0f); // 设置文本位置
			mWindow.draw(winText);
			mWindow.display();
			Sleep(3000);
			mWindow.close();
        }
        render();
    }
}

void Game::processEvents() {
    Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case Event::Closed:
                mWindow.close();
                break;
        }
    }
}
FloatRect getBounds(void* a, char type) {
    return type == 'p' ? ((Paddle*)a)->getShape().getGlobalBounds() : ((Ball*)a)->getShape().getGlobalBounds();
}

void Game::update(Time deltaTime) {
    mPaddle.update(deltaTime);

    mBall.update(deltaTime);
    // 检测碰撞
    //mBall.checkRebound("");
    if (getBounds(&mBall, 'b').intersects(getBounds(&mPaddle, 'p')) && getBounds(&mPaddle,'p').getPosition().y > getBounds(&mBall, 'b').getPosition().y) {
        mBall.reboundPaddle();
    }

    for (auto& brick : mBricks) {
        if (brick.isAlive() && getBounds(&mBall, 'b').intersects(brick.getShape().getGlobalBounds())) {
            mBall.reboundBrick();
            brick.hit();
            score += 1;
        }
    }
}

void Game::render() {
    Color backgroundColor = Color::White;
    mWindow.clear(backgroundColor);

    //绘制paddle和ball
    mWindow.draw(mPaddle.getShape());
    mWindow.draw(mBall.getShape());

    //绘制砖块
    for (const auto& brick : mBricks) {
        if (brick.isAlive()) {
            mWindow.draw(brick.getShape());
        }
    }
    
    // 右上角分数显示
    Text scoreText(
        (std::string)"Score: " + std::to_string(score),
        font1,
		32
	);
	scoreText.setColor(Color::Black);
    scoreText.setPosition(650, 10); // 设置文本位置
    mWindow.draw(scoreText), mWindow.display();
}

void Game::handlePlayerInput(Keyboard::Key key, bool isPressed) {
    if (key == Keyboard::A) {
        mIsMovingLeft = isPressed;
    }
    else if (key == Keyboard::D) {
        mIsMovingRight = isPressed;
    }
}
