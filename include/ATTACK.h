#pragma once
#include<graphics.h>
#include"CONST.h"
extern bool harm(int x, int y, int x1, int y1, CAMP camp, int ATK);
class ATTACK {
protected:
	int x, y;//λ������
	int length, height;//length-ˮƽ���򳤶�,height-��ֱ����߶�
	int ATK;//������
	bool life;//�Ƿ��ѱ�����
	CAMP camp;//��Ӫ
	DWORD t;//��¼����/�ϴ��ƶ���ʱ��
public:
	ATTACK();
	bool build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK);//���������_x,_y-��ʼ���꣬_direction-����_length-ʹ���ߵı߳���_camp-ʹ������Ӫ�� vertical_length ��vertival_width-�ù������Դ�ֱ���򴴽�ʱ�ĳ��Ⱥ͸߶ȣ�_ATK-������������ֵ�������ɹ�-1��ʧ��-0
	virtual void attack() = 0;//���й���
	virtual void draw()const = 0;//����ͼ��
};

