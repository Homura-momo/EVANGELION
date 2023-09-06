#include"ROLE.h"
extern bool empty(int x, int y, int x1, int y1);
ROLE::ROLE(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code) :length(length), HP_max(HP_max), speed(speed), firerate(firerate), code(code), direction(UP), x(0), y(0), HP(0), t_walk(0), t_attack(0), image{i1,i2,i3,i4}{}
void ROLE::build(int _x, int _y, DIRECTION _direction) {//�趨��ʼλ�úͷ���
	x = _x;
	y = _y;
	direction = _direction;
	setmap(x, y, length, code);
}
void ROLE::draw()const{
	if (HP > 0) {
		setlinecolor(RED);
		rectangle(x - 1, y - 1, x + length, y + length);//����AT����
		putimage(x, y, image[direction], SRCPAINT);//���ƽ�ɫͼ��
	}
}
bool ROLE::attacktime(){
	if (HP > 0 && GetTickCount() - t_attack >firerate) {//��������һ�ι���������Ӧʱ�䣬����Թ���
		t_attack = GetTickCount();//����ʱ��
		return 1;
	}
	else return 0;
}
bool ROLE::walktime(){
	if (HP > 0 && GetTickCount() - t_walk >speed) {//��������һ�����߹�����Ӧʱ�䣬���������
		t_walk = GetTickCount();//����
		return 1;
	}
	else return 0;
}
bool ROLE::move(DIRECTION direction) {
	int old_x = x, old_y = y;//��¼�ƶ�ǰ��λ��
	setmap(x, y, length, empty_s);//�����ƶ�ǰ���ڵ�λ��Ϊ��
	switch (direction) {//���ǰ�������ƶ����򣩵������Ƿ�Ϊ�գ�Ϊ�����ƶ���ɫλ��
	case UP:
		if (empty(x, y - 1, x + length - 1, y - 1)) y -= 1;
		break;
	case DOWN:
		if (empty(x, y + length, x + length - 1, y + length)) y += 1;
		break;
	case LEFT:
		if (empty(x - 1, y, x - 1, y + length - 1)) x -= 1;
		break;
	case RIGHT:
		if (empty(x + length, y, x + length, y + length - 1)) 	x += 1;
		break;
	}
	setmap(x, y, length, code);//�����ƶ�������λ�õĴ���
	if (old_x == x && old_y == y)return 0;//����ƶ�ǰ���λ����ͬ�����ƶ�ʧ�ܣ�����ɹ�
	else return 1;
}