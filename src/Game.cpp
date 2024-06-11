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
    // �� C:\\Windows\\Fonts\\arial.ttf��������
    if (!font1.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
		//��������fail
		std::cout << "Error loading font\n";
    }
    //�л�һ�����뷨
    switchToEnglishInputMethod();
    // ��ʼ��ש��
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) if(!(i > 2 && 3 < j && j < 6)){
            mBricks.emplace_back(Vector2f(j * 60.0f + 100.0f + j * 2.0f, i * 20.0f + 50.0f + i * 2.0f));
        }
    }
}

void Game::run() {
    
    Clock startClock;
    static const int prepareTime = 2;
	// ���壬��С����ʾ����preparetime��ʼ��Ϸ
    Text startText(
        "Prepare to start in " + std::to_string(prepareTime) + " seconds",
        font1, 
        48
    );
	startText.setColor(Color::Black);
	startText.setPosition(400 - startText.getLocalBounds().width / 2.0f, 250 - startText.getLocalBounds().height / 2.0f); // �����ı�λ��


     //�ȴ�3���ӣ������׼��
    while (startClock.getElapsedTime().asSeconds() < prepareTime) {
        Color backgroundColor = Color::White;
        mWindow.clear(backgroundColor);
		// �ı�startText������
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
			// ����һ����
			life -= 1;
			if (life == 0) {
				// ��Ϸ����
				Text endText;
				endText = Text("Game Over!", font1, 48);
                endText.setColor(Color::Black);
				endText.setPosition(
                    400 - endText.getLocalBounds().width / 2.0f, 
                    300 - endText.getLocalBounds().height / 2.0f
                ); // �����ı�λ��
				mWindow.clear(Color::White),
				mWindow.draw(endText), mWindow.display();
				Sleep(3000);
				mWindow.close();

            }
            mBall = Ball();
        }
        if (score == totalBrick) {
            // ͨ����
			Text winText;
			winText = Text("You Win!", font1, 48);
			winText.setPosition(400 - winText.getLocalBounds().width / 2.0f, 300 - winText.getLocalBounds().height / 2.0f); // �����ı�λ��
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
    // �����ײ
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

    //����paddle��ball
    mWindow.draw(mPaddle.getShape());
    mWindow.draw(mBall.getShape());

    //����ש��
    for (const auto& brick : mBricks) {
        if (brick.isAlive()) {
            mWindow.draw(brick.getShape());
        }
    }
    
    // ���ϽǷ�����ʾ
    Text scoreText(
        (std::string)"Score: " + std::to_string(score),
        font1,
		32
	);
	scoreText.setColor(Color::Black);
    scoreText.setPosition(650, 10); // �����ı�λ��
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
