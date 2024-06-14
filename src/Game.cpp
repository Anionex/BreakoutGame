// src/Game.cpp
#include "Game.hpp"
using namespace sf;
#define v2f Vector2f
#define background GameState::background
#define _USE_MATH_DEFINES
#include<math.h>

Game::Game()
    : 
    window(VideoMode(GameState::windowSize.x, GameState::windowSize.y), "Breakout Game"),
    gameState(GameState::initLife, 0, 0),
	rm(),
    paddle(GameState::paddlePos, GameState::initPaddleV),
    ball(GameState::initBallPos, GameState::initBallV, 1) //这里有一点别扭，因为并不是所有mode都要用到ball和paddle, TODO考虑职责专一化
{
    
    // 加载字体
	rm.loadFont("main", "resources/fonts/DS-DIGI.ttf"); 
    rm.loadFont("noto", "resources/fonts/NotoEmoji-Regular.ttf");
    rm.loadTexture("paddle", "resources/textures/paddle.png");
    rm.loadTexture("ball", "resources/textures/ball.png");
    rm.loadTexture("brick", "resources/textures/brick.png");
    rm.loadTexture("background", "resources/textures/background.png");
    

    background.setSize(v2f(GameState::windowSize));
    background.setTexture(&rm.getTexture("background"));
    background.setPosition(0, 0);
    //切换输入法
    switchToEnglishInputMethod();
    menu = Menu(rm);
}

void Game::run()
{
    std::cout << "show menu" << std::endl;
    while (1) {
        Menu::Selection selection = menu.show(window);
        switch (selection) {
        case Menu::mode1:
            runSinglePlayer();
            break;
        case Menu::mode2:
            runDemo();
            break;
        case Menu::settings:
            runSettings();
            break;
        }
        menu.setDefult();
    }
    //std::cout << "end run() with mode : " <<  selection << std::endl;
}

void Game::runSinglePlayer() {
    //设置纹理
    std::cout << "at runsingle" << std::endl;
    ball.sprite.setTexture(rm.getTexture("ball"));
    paddle.sprite.setTexture(rm.getTexture("paddle"));
    paddle.sprite.setScale(1.5, 1.5);
    ball.sprite.setScale(0.75, 0.75);
	ball.accelarate = GameState::ballAcceleration;
    
    //常用量定义
    const v2f middle(window.getSize().x / 2, window.getSize().y / 2);

    // 初始化砖块

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) 
            if (!(i > 2 && 3 < j && j < 6) && !(i == 0 && (j < 1 || j > 8))) {
            bricks.emplace_back(Brick(v2f(j * 60.0f + 100.0f + j * 2.0f, i * 20.0f + 50.0f + i * 5.0f), v2f(0, 0), 1, rm.getTexture("brick")));
        }
    }
	GameState::totalBrick = bricks.size();
    





    // 显示还有preparetime开始游戏
    static const int prepareTime = 0;

    //等待prepareTime，让玩家准备
    Clock startClock;
    while (startClock.getElapsedTime().asSeconds() < prepareTime) {
        Color backgroundColor = Color::White;
        window.clear(backgroundColor), window.draw(background);
        // 改变startText的内容
        drawTextDefult(window, rm, "Prepare to start in " +
            std::to_string(prepareTime - (int)startClock.getElapsedTime().asSeconds()) + " seconds", 64, middle);
        Sleep(1000);
    }

    //初始化一个返回按钮在左上角，点击后返回主菜单
    Button backButton(v2f(50, 25), "Back", 48, rm.getFont("main"), Color::Black);

    // 游戏主循环
    Clock clock;
    while (window.isOpen()) {
        Time deltaTime = clock.restart();
        float deltaTimeSec = deltaTime.asSeconds();
        
		// 单独处理back按钮 TODO
		if (backButton.isClicked(window)) return;
        processEvents();

        backButton.update(window);
        update(deltaTimeSec);


        render();
        backButton.draw(window);
        window.display();
    }
}

void Game::runDemo()
{
    Text text("Demo", rm.getFont("main"));
    text.setCharacterSize(64);
    text.setFillColor(Color::Black);
    FloatRect bounds = text.getLocalBounds();
    text.setPosition(v2f(GameState::windowSize.x / 2 - bounds.width / 2, 50));

    while (window.isOpen()) {
        window.clear(Color::White);
        window.draw(background);
        window.draw(text);
        window.display();
    }
}

//ballAccelerationPlus按钮点击的callback函数实现
void ballAccelerationPlusCallback()
{
	GameState::ballAcceleration.x += 10;
    GameState::ballAcceleration.y += 10;
}

//ballAccelerationMinus按钮点击的callback函数实现
void ballAccelerationMinusCallback()
{
	GameState::ballAcceleration.x -= 10;
	GameState::ballAcceleration.y -= 10;
}

//initLifePlus按钮点击的callback函数实现
void initLifePlusCallback()
{
	GameState::initLife += 1;
}

//initLifeMinus按钮点击的callback函数实现
void initLifeMinusCallback()
{
	GameState::initLife -= 1;
}

void Game::runSettings()
{
	Text text("Settings", rm.getFont("main"));
	text.setCharacterSize(64);
	text.setFillColor(Color::Black);
	FloatRect bounds = text.getLocalBounds();
	text.setPosition(v2f(GameState::windowSize.x / 2 - bounds.width / 2, 50));

    // 计算文本和按钮的水平中心位置
    float centerX = GameState::windowSize.x / 2;

    // 设定垂直位置的起点和行间距
    float startY = 150;
    float lineSpacing = 100;

    // 文字和按钮之间的水平间距
    float textButtonSpacing = 20;
    float buttonSpacing = 50;

    // 初始化"Ball Acceleration"组件
    Text ballAccelerationText("Ball Acceleration: " + std::to_string(GameState::ballAcceleration.x), rm.getFont("main"));
    ballAccelerationText.setCharacterSize(48);
    ballAccelerationText.setFillColor(Color::Black);

    // 获取文本的边界尺寸
    sf::FloatRect ballAccelerationBounds = ballAccelerationText.getLocalBounds();
    ballAccelerationText.setPosition(centerX - ballAccelerationBounds.width / 2, startY);

    Button ballAccelerationPlus(v2f(centerX + ballAccelerationBounds.width / 2 + textButtonSpacing, startY), "+ ", 48, rm.getFont("main"), Color::Black);
    Button ballAccelerationMinus(v2f(centerX + ballAccelerationBounds.width / 2 + textButtonSpacing + buttonSpacing, startY), "- ", 48, rm.getFont("main"), Color::Black);

    std::vector<Button*> settingsItems = { &ballAccelerationPlus, &ballAccelerationMinus };

    // 初始化"Initial Life"组件
    Text initLifeText("Initial Life: " + std::to_string(GameState::initLife), rm.getFont("main"));
    initLifeText.setCharacterSize(48);
    initLifeText.setFillColor(Color::Black);

    // 获取文本的边界尺寸
    sf::FloatRect initLifeBounds = initLifeText.getLocalBounds();
    initLifeText.setPosition(centerX - initLifeBounds.width / 2, startY + lineSpacing);

    Button initLifePlus(v2f(centerX + initLifeBounds.width / 2 + textButtonSpacing, startY + lineSpacing), "+ ", 48, rm.getFont("main"), Color::Black);
    Button initLifeMinus(v2f(centerX + initLifeBounds.width / 2 + textButtonSpacing + buttonSpacing, startY + lineSpacing), "- ", 48, rm.getFont("main"), Color::Black);

    

    // 添加到设置项
    settingsItems.push_back(&initLifePlus);
    settingsItems.push_back(&initLifeMinus);



	//初始化一个返回按钮在左上角，点击后返回主菜单
	Button backButton(v2f(50, 50), "Back", 48, rm.getFont("main"), Color::Black);
	settingsItems.push_back(&backButton);


    //设置按钮回调函数内容
    ballAccelerationPlus.callback = ballAccelerationPlusCallback;
    ballAccelerationMinus.callback = ballAccelerationMinusCallback;
    initLifePlus.callback = initLifePlusCallback;
    initLifeMinus.callback = initLifeMinusCallback;



	while (window.isOpen()) {
		Clock clock;
		
		// 处理事件
		Event event;
		while (window.pollEvent(event)) {
            Time deltaTime = clock.restart();
			// 处理一般事件
			if (event.type == Event::Closed) {
				window.close();
				return;
			}

			// 按钮的update事件，包含callback函数的调用
			for (auto& item : settingsItems) item->update(window);

			// 返回按钮的点击事件
			if (backButton.isClicked(window)) {
				return;
			}
            //控制帧率为60
			if (deltaTime.asSeconds() < 1.0 / 60) {
				Sleep((1.0 / 60 - deltaTime.asSeconds()) * 1000);
			}
			
		}
        //重新设定字符串内容为当前数值
		ballAccelerationText.setString("Ball Acceleration: " + std::to_string(GameState::ballAcceleration.x));
		initLifeText.setString("Initial Life: " + std::to_string(GameState::initLife));



		// 绘制
        window.clear(Color::White);
        window.draw(background);
		for (auto& item : settingsItems) item->draw(window);

        window.draw(ballAccelerationText);
		window.draw(initLifeText);

		window.draw(text);
        //显示新的加速度和life
        window.draw(ballAccelerationText);
		window.draw(initLifeText);

        // cout 新的initLife
		std::cout << "initLife: " << GameState::initLife << std::endl;

		window.display();
	}
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
    if (!(ball.pos.y > paddle.pos.y) && ball.collidWith(paddle)) {
        // 判断是哪个
        FloatRect ballRect = ball.sprite.getGlobalBounds();
        FloatRect paddleRect = paddle.sprite.getGlobalBounds();
		int collidType = checkCollidType(ballRect, paddleRect);
        if (collidType == 0) 
            ball.verticalRebound();	
		else 
			ball.horizentalRebound(), ball.velocity.x += paddle.velocity.x * 0.1;
    }

    // 砖块碰撞逻        
    for(auto& brick: bricks)
        if (brick.hp && ball.collidWith(brick)) {
            FloatRect ballRect = ball.sprite.getGlobalBounds();
            FloatRect paddleRect = brick.sprite.getGlobalBounds();
            int collidType = checkCollidType(ballRect, paddleRect);
            if (collidType == 0)
                ball.verticalRebound();
            else
                ball.horizentalRebound();

            brick.hit();
            gameState.score++;
        }
    //std::cout << "mark1:" << tmp << std::endl;
    
    ////边界碰撞逻辑
    if ((ball.pos.x < 0 || ball.pos.x + ball.sprite.getLocalBounds().width > GameState::windowSize.x)
		&& ball.ballClock.getElapsedTime() > ball.reboundCoolDown) ball.verticalRebound(), ball.ballClock.restart();
    if (ball.pos.y < 0 && ball.ballClock.getElapsedTime() > ball.reboundCoolDown) ball.horizentalRebound(), ball.ballClock.restart();


    //掉出底部
    if (ball.pos.y > GameState::windowSize.y) {
        // 减除一条命
        gameState.life -= 1;
        if (gameState.life == 0) {
            // 游戏结束
            window.clear(Color::White), window.draw(background), drawTextDefult(window, rm, "Game Over\n Press R to restart", 88, middle);
            
			bool choice = false;
			// 按R重新开始游戏
            while (window.isOpen()) {

				if (Keyboard::isKeyPressed(Keyboard::R)) {
					gameState.life = GameState::initLife;
					gameState.score = 0;
					// 重新初始化砖块
					for (auto& brick : bricks) brick.hp = 1;

                    //重新初始化挡板
					paddle = Paddle(GameState::paddlePos, GameState::initPaddleV);
                    paddle.sprite.setTexture(rm.getTexture("paddle"));
					paddle.sprite.setScale(1.5, 1.5);

					

                    choice = 1;
					break;
				}
            }
			// 如果玩家选择退出游戏
			if(!choice)window.close();

        }
        // 重新初始化球
        ball = Ball(GameState::initBallPos, GameState::initBallV, 1, rm.getTexture("ball")); //重新初始化一个球， TODO，资源释放问题
        ball.sprite.setScale(0.75, 0.75);
        ball.accelarate = GameState::ballAcceleration;
        
    }

    // 通关逻辑
    //if (gameState.score == gameState./*totalBrick * 2) {
    //    window.clear(Color::White),window.draw(background), drawTextDefult(window, rm, "You Win", 88, middle);
    //    Sleep(3000);
    //    window.close();
    //}*/
}
float& min(float a, float b) {
	return a < b ? a : b;
}
void Game::update(float deltaTime) 
{
    // 将ball的加速度方向设置为和速度同向
    if (ball.velocity.x * ball.accelarate.x < 0) ball.accelarate.x *= -1;
	if (ball.velocity.y * ball.accelarate.y < 0) ball.accelarate.y *= -1;
    

    //如果速度分量的平方和大于最大速度的平方和，加速度清零
	if (ball.velocity.x * ball.velocity.x + ball.velocity.y * ball.velocity.y > 
        GameState::ballMaxSpeed.x * GameState::ballMaxSpeed.x + GameState::ballMaxSpeed.y * GameState::ballMaxSpeed.y) ball.accelarate = v2f(0, 0);
    ball.update(deltaTime);
	std::cout << ball.velocity.x << " " << ball.velocity.y << std::endl;
	
    paddle.update(deltaTime);
    for (auto& brick : bricks) brick.update(deltaTime);

}

void Game::render()
{
    window.clear(Color::White);
    window.draw(background);
    ball.draw(window);
    paddle.draw(window);
    for (auto& brick : bricks) if (brick.hp) brick.draw(window); 

    //右上角根据生命数量显示对应数量的
	std::string lifeStr = "Score: " + std::to_string(gameState.score) + "      Life: ";
	for (int i = 0; i < gameState.life; ++i) lifeStr += "0 " ;
	drawTextDefult(window, rm, lifeStr, 48, v2f(GameState::windowSize.x - 350, 20));



}




