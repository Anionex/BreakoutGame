# BrekoutGame
### 作者
杨丁玮（暨南大学）


#### 项目仓库地址
https://github.com/Anionex/BreakoutGame
#### 项目概述
用C++简单实现一个经典的“Breakout Game”的经典打砖块游戏，使用SFML库作为媒体库。项目的主要模块包括游戏主逻辑、菜单管理、资源管理以及各个游戏元素（如球、砖块、挡板）的实现。
#### 重要知识点

1. **基础语法**
    - 指针与引用

2. **面向对象编程**
   - 构造函数和析构函数
   - 继承与多态
   - 虚函数和纯虚函数

3. **STL使用**
4. 游戏开发相关知识
5. Cmake项目构建





#### 功能

1. 挡板速度影响小球碰撞后速度。提高游戏可玩性。
2. 支持设置初始生命值和小球加速度大小。
3. 消除砖块积一分，当消除所有方块显示通关。生命值降为0显示游戏结束，按下R重新开始游戏。
4. 支持返回菜单栏重新设置参数。

#### 模块说明

1. **Game 类**
    - 主要职责：处理游戏主循环、初始化游戏对象、切换游戏模式、管理事件处理和渲染。
    - 主要方法：
        - `Game()`: 构造函数，初始化窗口和资源，加载字体和纹理，设置背景。
        - `run()`: 主循环，根据用户选择进入不同模式。
        - `initObject()`: 初始化游戏对象，包括球、挡板和砖块。
        - `runSinglePlayer()`: 单人模式逻辑。
        - `runDemo()`: 演示模式逻辑。
        - `runSettings()`: 设置模式逻辑，处理设置相关的按钮回调。
        - `processEvents()`: 事件处理函数，处理游戏中的各种事件（如关闭窗口、碰撞检测）。
        - `update(float deltaTime)`: 更新游戏状态，包括球、挡板和砖块的位置和状态。
        - `render()`: 渲染游戏画面。

2. **Menu 类**
    - 主要职责：管理游戏菜单的显示和用户选择。
    - 主要方法：
        - `show(RenderWindow& window)`: 显示菜单并等待用户选择。
        - `setDefult()`: 重置菜单到默认状态。

3. **ResourceManager 类**
    - 主要职责：管理游戏中的资源，如字体和纹理。
    - 主要方法：
        - `loadFont(const std::string& id, const std::string& filename)`: 加载字体。
        - `getFont(const std::string& id)`: 获取字体。
        - `loadTexture(const std::string& id, const std::string& filename)`: 加载纹理。
        - `getTexture(const std::string& id)`: 获取纹理。

4. **GameObject 类**
    - 主要职责：作为游戏中所有对象的基类，提供基础的属性和方法。
    - 主要方法：
        - `GameObject()`: 默认构造函数。
        - `GameObject(Vector2f pos, Vector2f velocity)`: 初始化位置和速度的构造函数。
        - `GameObject(Vector2f pos, Vector2f velocity, int hp)`: 初始化位置、速度和生命值的构造函数。
        - `collidWith(const GameObject& B)`: 碰撞检测。

5. **Ball 类**
    - 主要职责：表示游戏中的球，包括其位置、速度和加速度。
    - 主要方法：
        - `update(float deltaTime)`: 更新球的位置和状态。
        - `draw(RenderWindow& window)`: 渲染球。
        - `collidWith(const Paddle& paddle)`: 检测与挡板的碰撞。
        - `collidWith(const Brick& brick)`: 检测与砖块的碰撞。
        - `verticalRebound()`: 垂直反弹。
        - `horizentalRebound()`: 水平反弹。

6. **Paddle 类**
    - 主要职责：表示游戏中的挡板，包括其位置和速度。
    - 主要方法：
        - `update(float deltaTime)`: 更新挡板的位置和状态。
        - `draw(RenderWindow& window)`: 渲染挡板。

7. **Brick 类**
    - 主要职责：表示游戏中的砖块，包括其位置和耐久度。
    - 主要方法：
        - `update(float deltaTime)`: 更新砖块的状态。
        - `draw(RenderWindow& window)`: 渲染砖块。
        - `hit()`: 处理砖块被击中的逻辑。

8. **Button 类**
    - 主要职责：表示游戏中的按钮，用于设置菜单中的交互。
    - 主要方法：
        - `Button()`: 默认构造函数。
        - `Button(v2f pos, const std::string& content, int size, const Font& font, const Color& textColor)`: 初始化按钮的构造函数。
        - `draw(RenderWindow& window)`: 渲染按钮。
        - `isMouseOn(RenderWindow& window)`: 检测鼠标是否在按钮上。
        - `isClicked(RenderWindow& window)`: 检测按钮是否被点击。
        - `update(RenderWindow& window)`: 更新按钮的状态，调用回调函数（如果有）。

...


# 感谢。
