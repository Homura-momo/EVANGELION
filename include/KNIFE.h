#pragma once
#include"PROP.h"
class KNIFE :public PROP {
private:
	int ATK;//������
public:
	KNIFE(int ATK, int length, CAMP camp);
	void use(int x, int y, DIRECTION direction);
	void changeatk(double n);//�޸�С����ATKΪԭ����n��
};