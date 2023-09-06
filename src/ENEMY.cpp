#include"ENEMY.h"
#include"HERO.h"
extern HERO* hero;
extern int map[LENGTH][HEIGHT];
ENEMY::ENEMY(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code) :ROLE(length, HP_max, speed, firerate, i1, i2, i3, i4, code) {}
void ENEMY::track() {
	DIRECTION d1, d2, tempd;//d1Ϊ�������ߵĴ�ֱ����d2Ϊ�������ߵ�ˮƽ����tempd���ݴ汸ѡ����
	//��ȡ������ϽǺ͵��˵�ˮƽ����ֱ���Գ����ˮƽ����ֱ������
	int tempx = x+length/2 - hero->getx();
	int tempy = y+length/2- hero->gety();
	if (tempx > 0 && tempx < hero->getlength()) {//������˴�ֱ�ĶԳ���������ཻ�����������(��)���������ܻ�����ң�˵����ҽ�����˵Ĵ�ֱ������Χ
		direction = tempy > 0 ? UP : DOWN;//������������С�ڵ��˵ĶԳ��ᣨ�ڵ��˵��Ϸ���������˷������Ϊ���ϣ���������
		move(direction);
	}
	else if (tempy >0&& tempy < hero->getlength()) {//��ҽ�����˵�ˮƽ������Χ
		direction = tempx > 0 ? LEFT : RIGHT;//�����Һ�����С�ڵ��˵ĶԳ��ᣨ�ڵ��˵��󷽣�������˷������Ϊ���󣬷�������
		move(direction);
	}
	else {//������û�н�����˹�����Χ����ȷ������ڵ��˵��ĸ�����Ȼ�����������ǰ��
		if (tempy > 0)d1 = UP;//������Ϸ�
		else {//������·�
			d1 = DOWN;
			tempy = -tempy;//��֤����Ϊ����
		}
		if (tempx > 0)d2 = LEFT;//�������
		else {//������ҷ�
			d2 = RIGHT;
			tempx = -tempx;
		}
		if (tempy > tempx) {//��ֱ���������ֱ����Ϊ��ѡ����ˮƽ����Ϊ��ѡ����
			direction = d1;
			tempd = d2;
		}
		else {//ˮƽ���������ˮƽ����Ϊ��ѡ���򣬴�ֱ����Ϊ��ѡ����
			direction = d2;
			tempd = d1;
		}
		if (!move(direction)) {//�������ѡ�����ƶ�ʧ�ܣ��򳯱�ѡ�����ƶ�
			direction = tempd;
			move(direction);
		}
	}
	//�ƶ���,����ɫ�����Ƿ���������Ʒ
	detect(x, y - 1, x + length - 1, y - 1);
	detect(x, y + length, x + length - 1, y + length);
	detect(x - 1, y, x - 1, y + length - 1);
	detect(x + length, y, x + length, y + length - 1);
}
void ENEMY::walk() {
	if (walktime()) track();
}
bool ENEMY::build(int _x, int _y, DIRECTION _direction) {
	if (HP <= 0) {
		ROLE::build(_x, _y, _direction);
		HP = HP_max;
		return 1;
	}
	else return 0;
}
void ENEMY::attack() {
	if (attacktime())attackway();
}
void ENEMY::attacked(int h) {
	if (HP > 0) {
		reaction(h);//�ȶԹ���������Ӧ��Ӧ
		HP -= h;
		if (HP <= 0) {//Ѫ��<0,����
			clearrectangle(x - 1, y - 1, x + length, y + length);//���ͼ��
			setmap(x, y, length, empty_s);//��������λ��Ϊ��
			die();//�ṩ��������
		}
	}
}
void ENEMY::reaction(int& h){}
void ENEMY::detect(int x1, int y1, int x2, int y2)const {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {//��⵽δʰȡ���ߣ�����߱�ʰȡ
			if (i >= 0 && i < LENGTH && j >= 0 && j < HEIGHT && map[j][i] != empty_s) {
				if (map[j][i] >= machinegun_s && map[j][i] < machinegun_s + barrier_n) {
					barriers->machinegun[map[j][i] - machinegun_s]->picked();
				}
				else if (map[j][i] >= mine_s && map[j][i] < mine_s + barrier_n) {
					barriers->mine[map[j][i] - mine_s]->picked();
				}
				else if (map[j][i] >= spear_s && map[j][i] < spear_s + barrier_n) {
					barriers->spear[map[j][i] - spear_s]->picked();
				}
				else if (map[j][i] >= cannon_s && map[j][i] < cannon_s + barrier_n) {
					barriers->cannon[map[j][i] - cannon_s]->picked();
				}
				else if (map[j][i] >= shield_s && map[j][i] < shield_s + barrier_n) {
					barriers->shield[map[j][i] - shield_s]->picked();
				}
				else if (map[j][i] >= gold_s && map[j][i] < gold_s + barrier_n) {
					barriers->gold[map[j][i] - gold_s]->picked();
				}
			}
		}
}