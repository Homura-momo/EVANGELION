#pragma once
#include"ATTACK.h"
class BULLET:public ATTACK {
private:
	DIRECTION direction;//����
	COLORREF color;//��ɫ
public:
	BULLET();
	bool build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK, COLORREF _color);//������_color-�ӵ���ɫ������ͬATTACK::build()
	void attack();
	void draw() const;
};