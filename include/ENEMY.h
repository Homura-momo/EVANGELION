#pragma once
#include"ROLE.h"
extern int score;
class ENEMY :public ROLE {
public:
	ENEMY(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code);
	bool build(int _x, int _y, DIRECTION _direction);//����һ�����ˣ�_x��_y-��ʼ���꣬_direction-��ʼ���򣬴����ɹ�-1��ʧ��-0
	void track();//׷�����,����ҷ���ǰ��
	void detect(int x1, int y1, int x2, int y2) const;//�������������Ƿ����������壬�����ж�Ӧ������x1,y1-�������Ͻ����꣬x2,y2-�������½�����
	void attack();//�Զ�����
	void attacked(int h);
	virtual void walk();//����
	virtual void reaction(int& h);//�ܹ���ʱ�ķ�Ӧ��h-�˺�
	virtual void attackway() = 0;//��������
	virtual void die()const = 0;//��������
};