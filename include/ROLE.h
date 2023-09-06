#pragma once
#include"GLOBAL_FUNCTION.h"
#include"BARRIERS.h"
#include"IMAGES.h"
#include"GUN.h"
#include"KNIFE.h"
#include"MACHINEGUN.h"
#include"MINE.h"
#include"SPEAR.h"
#include"CANNON.h"
#include"SHIELD.h"
extern BARRIERS* barriers;
extern IMAGES* images;
class ROLE {
protected:
	int x, y;//λ�ã�x-�����ꡢy-������
	int HP_max;//����ֵ����
	int HP;//����ֵ
	int speed, firerate;//�����ٶ�,�����ٶȣ���ÿ�����ߣ�����������೤ʱ��
	DIRECTION direction;//����
	int length;//�߳�
	IMAGE* image[4];//�ֱ����ĸ�����Ľ�ɫͼ��
	int code;//����
	DWORD t_walk, t_attack;//��һ�����ߵ�ʱ�䣬��һ�ι�����ʱ��
public:
	ROLE(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code);
	void build(int _x, int _y, DIRECTION _direction);//������ɫ��_x��_y-��ʼ����_direction-��ʼ����
	bool attacktime();//�Ƿ���Թ���,1-���ԣ�0-������
	bool walktime();//�Ƿ�������ߣ�1-���ԣ�0-������
	bool move(DIRECTION direction);//�������ƶ�1����,direction-����1-�ƶ��ɹ���2-�ƶ�ʧ��
	void draw()const;//���ƽ�ɫ
	virtual void attacked(int h) = 0;//�ܹ�����h-�˺�
};