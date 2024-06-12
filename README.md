# BrekoutGame

## 2sfmlQ&A
1. xy方向------->x
|
|
|
.
y
## 1模块设计

### Game对象 
#### 成员和方法: 
##### 属性
1. ball
2. paddle 
3. bricks : vector of bricks
4. score
5. life
6. mode
7. round 
8. window
9. gameState

##### 方法
1. run_mode1
1. run_mode2
2. update
3. processEvents 
4. render

### GameObject对象 
#### 属性和方法: 
##### 属性
1. pos
2. sprite 图形表示
3. ~ alive 是否存活 ~  hp 健康点数
4. velocity 速度矢量

##### 方法
1. virtual update
2. virtual draw
3. collidWith()

### Ball对象 继承GameObject
#### 属性和方法: 
##### 属性
1. pos
2. sprite 图形表示
3. alive 是否存活
4. velocity 速度矢量

##### 方法
1. update
2. draw
3. collidWith()
4. （增加） rebound()

### Paddle继承GameObject对象 
#### 属性和方法: 
##### 属性
1. pos
2. sprite 图形表示
3. alive 是否存活
4. velocity 速度矢量

##### 方法
1. update
2. draw
3. collidWith()
4. （增加） moveLeft
5. (add) moveRight

### brick对象继承GameObject对象 
#### 属性和方法: 
##### 属性
1. pos
2. sprite 图形表示
3. ~ alive 是否存活 ~  hp 健康点数
4. velocity 速度矢量

##### 方法
1.  update
2.  draw
3. collidWith() 是否和B碰撞
4. (add) hit 和小球碰撞后的逻辑



