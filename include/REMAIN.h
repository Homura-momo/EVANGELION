#pragma once
#include"ATTACK.h"
class REMAIN :public ATTACK {
private:
	DIRECTION direction;//����
	COLORREF color;//��ɫ
public:
	REMAIN();
	bool build(int x, int y, int length, DIRECTION direction, CAMP camp, int vertical_length, int vertical_height, int ATK, COLORREF color);//����,_color-��ֹ��������ɫ�� ����ͬATTACK::build()
	void attack();
	void draw()const;
};