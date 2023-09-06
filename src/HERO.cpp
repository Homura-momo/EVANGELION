#include"HERO.h"
#include"ENEMYS.h"
extern ENEMYS* enemys;
extern int map[LENGTH][HEIGHT];
HERO::HERO(int HP, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4) :ROLE(midium_length, HP, speed, firerate, i1, i2, i3, i4, hero_s), gun(length, CAMP::hero), knife(2, length, CAMP::hero), machinegun(length, CAMP::hero), mine(length, CAMP::hero), spear(length, CAMP::hero), cannon(length, CAMP::hero, 4), shield(length, CAMP::hero), prop{ &gun,&knife,&machinegun,&mine,&spear,&cannon,&shield }, gold(0), prop_i(0), crazy(0), t_crazy(0) {}
int HERO::getx()const {
	return x;
}
int HERO::gety()const {
	return y;
}
int HERO::getlength()const {
	return length;
}
bool HERO::live()const {
	if (HP > 0)  return 1;
	else return 0;
}
void HERO::build(int _x, int _y, DIRECTION _direction) {
	ROLE::build(_x, _y, _direction);
	if (HP <= 0)HP = HP_max;//���Ѫ��Ϊ0����������Ϸ��һ�δ�����ң�����Ѫ�����������򲻻�Ѫ
}
void HERO::walk(DIRECTION _direction) {
	if (walktime()) {//��������ƶ�,�򰴷����ƶ�1����
		bool m = move(_direction);
		//�ƶ���,����ɫ�����Ƿ���������Ʒ
		detect(x, y - 1, x + length - 1, y - 1, m);
		detect(x, y + length, x + length - 1, y + length, m);
		detect(x - 1, y, x - 1, y + length - 1, m);
		detect(x + length, y, x + length, y + length - 1, m);
	}
}
void HERO::attack(DIRECTION _direction) {
	if (attacktime()) {//������Թ�������ı���ҷ��򣬲�ʹ�õ�ǰ����
		direction = _direction;
		prop[prop_i]->use(x, y, direction);
	}
}
void  HERO::selectPROP(int x) {
	if (!crazy)prop_i = x - 1;//��������ڡ����ߡ���������һ������
}
void HERO::switchPROP() {
	if (!crazy) {//��������ڡ����ߡ���������һ������
		if (prop_i == 6)prop_i = 0;//����������ĵ��ߣ��л�����һ��
		else prop_i++;
	}
}
void HERO::reswitchPROP() {
	if (!crazy) {//��������ڡ����ߡ���������һ������
		if (prop_i == 0)prop_i = 6;//������ǵ�һ�����ߣ��л������һ��
		else prop_i--;
	}
}
void HERO::buyprop(int n) {
	if (gold >= 5) {//�������㹻������Թ��������ٵ���
		switch (n) {
		case hero_s:
			if (HP + 10 <= HP_max)HP += 10;//���Ѫ��+10��δ��������Ի�Ѫ10
			else if (HP < HP_max)HP = HP_max;//���Ѫ��δ��������Իص�Ѫ������
			else return;//���Ѫ���������򲻼��ٽ��
			break;
		case machinegun_s:
			machinegun.innum(50);
			break;
		case mine_s:
			mine.innum(4);
			break;
		case spear_s:
			spear.innum(4);
			break;
		case cannon_s:
			cannon.innum(4);
			break;
		case shield_s:
			shield.innum(20);
			break;
		}
		gold -= 5;
	}
}
void HERO::attacked(int h) {
	if (crazy)h /= 2;//������ڡ����ߡ������˺�����
	if (prop[prop_i] == &shield)shield.defend(h);//�����ǰ�����Ƕ��ƣ��򴥷����Ʒ���
	HP -= h;
	//���˺�ﵽ��ӦѪ�����򴥷������ߡ��򡰲��ꡱ
	if (HP <= HP_max / 2 && HP + h > HP_max / 2)becrazy();
	if (HP <= HP_max / 4 && HP + h > HP_max / 4)becrazy();
	if (HP <= HP_max / 8 && HP + h > HP_max / 8)instrumentality();
}
void HERO::detect(int x1, int y1, int x2, int y2, bool move) {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {
			if (i >= 0 && i < LENGTH && j >= 0 && j < HEIGHT && map[j][i] != empty_s) {
				if (move && map[j][i] >= trap_s && map[j][i] < trap_s + barrier_n) {//��⵽���壬��ɫ��Ѫ
					attacked(1);
					return;//ֹͣ��⣬�����ظ���Ѫ
				}
				//��⵽δʰȡ���ߣ����߱�ʰȡ����ɫ������������
				else if (map[j][i] >= machinegun_s && map[j][i] < machinegun_s + barrier_n) {
					barriers->machinegun[map[j][i] - machinegun_s]->picked();
					machinegun.innum(50);
				}
				else if (map[j][i] >= mine_s && map[j][i] < mine_s + barrier_n) {
					barriers->mine[map[j][i] - mine_s]->picked();
					mine.innum(5);
				}
				else if (map[j][i] >= spear_s && map[j][i] < spear_s + barrier_n) {
					barriers->spear[map[j][i] - spear_s]->picked();
					spear.innum(5);
				}
				else if (map[j][i] >= cannon_s && map[j][i] < cannon_s + barrier_n) {
					barriers->cannon[map[j][i] - cannon_s]->picked();
					cannon.innum(5);
				}
				else if (map[j][i] >= shield_s && map[j][i] < shield_s + barrier_n) {
					barriers->shield[map[j][i] - shield_s]->picked();
					shield.innum(20);
				}
				else if (map[j][i] >= gold_s && map[j][i] < gold_s + barrier_n) {
					barriers->gold[map[j][i] - gold_s]->picked();
					getgold(1);
				}
				else if (map[j][i] == bossdoor_s) {//�������
					barriers->bossdoor->enter();
				}
			}
		}
}
void HERO::getgold(int n) {
	gold += n;
}
void HERO::becrazy() {
	if (!crazy) {//��������ڡ����ߡ�������롰���ߡ�
		t_crazy = GetTickCount();
		crazy = 1;
		speed /= 2;
		prop_i = 1;
		knife.changeatk(2);
	}
	else if (crazy)t_crazy += 10000;//������ڡ����ߡ��������ӡ����ߡ���ʱ��
}
void HERO::detectcrazy() {
	if (crazy && GetTickCount() - t_crazy > 10000) {//��ʱ����رա����ߡ������Իָ�
		crazy = 0;
		speed *= 2;
		knife.changeatk(0.5);
	}
}void HERO::instrumentality() {//�������е��˺��ϰ���
	enemys->boss->attacked(20);
	for (int i = 0; i < mob_n; i++) {
		enemys->average1[i]->attacked(10);
		enemys->average2[i]->attacked(10);
	}
	for (int i = 0; i < barrier_n; i++) {
		barriers->stone[i]->attacked(10);
		barriers->iron[i]->attacked(10);
		barriers->trap[i]->attacked(10);
	}
}
void HERO::draw()const {
	if (crazy) {//������ڡ����ߡ�,��ɫͼ����
		setfillcolor(LIGHTRED);
		solidrectangle(x - 1, y - 1, x + length, y + length);
	}
	if (prop[prop_i] == &shield) shield.show(x, y);//�����ǰ�����Ƕ��ƣ���ʾ����
	ROLE::draw();
}
void HERO::show()const {
	setlinecolor(WHITE);
	setfillcolor(RED);
	//����Ѫ������ʾѪ��
	if (HP > 0)solidrectangle(0, 0, HP, 15);
	rectangle(0, 0, HP_max, 15);
	//չʾ��ǰ������Ϣ
	shownum(HP_max + 1, 0, HP);
	prop[prop_i]->show();
	//չʾ�������
	putimage(0, HEIGHT - small_length, &images->gold);
	shownum(small_length, HEIGHT - 15, gold);
}