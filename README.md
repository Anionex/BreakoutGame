# BrekoutGame

## 2sfmlQ&A
1. xy����------->x
|
|
|
.
y
## 1ģ�����

### Game���� 
#### ��Ա�ͷ���: 
##### ����
1. ball
2. paddle 
3. bricks : vector of bricks
4. score
5. life
6. mode
7. round 
8. window
9. gameState

##### ����
1. run_mode1
1. run_mode2
2. update
3. processEvents 
4. render

### GameObject���� 
#### ���Ժͷ���: 
##### ����
1. pos
2. sprite ͼ�α�ʾ
3. ~ alive �Ƿ��� ~  hp ��������
4. velocity �ٶ�ʸ��

##### ����
1. virtual update
2. virtual draw
3. collidWith()

### Ball���� �̳�GameObject
#### ���Ժͷ���: 
##### ����
1. pos
2. sprite ͼ�α�ʾ
3. alive �Ƿ���
4. velocity �ٶ�ʸ��

##### ����
1. update
2. draw
3. collidWith()
4. �����ӣ� rebound()

### Paddle�̳�GameObject���� 
#### ���Ժͷ���: 
##### ����
1. pos
2. sprite ͼ�α�ʾ
3. alive �Ƿ���
4. velocity �ٶ�ʸ��

##### ����
1. update
2. draw
3. collidWith()
4. �����ӣ� moveLeft
5. (add) moveRight

### brick����̳�GameObject���� 
#### ���Ժͷ���: 
##### ����
1. pos
2. sprite ͼ�α�ʾ
3. ~ alive �Ƿ��� ~  hp ��������
4. velocity �ٶ�ʸ��

##### ����
1.  update
2.  draw
3. collidWith() �Ƿ��B��ײ
4. (add) hit ��С����ײ����߼�



