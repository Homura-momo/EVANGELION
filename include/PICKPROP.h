#pragma once
#include"PROP.h"
class PICKPROP :public PROP {
protected:
	int num;//����
public:
	PICKPROP(int length, CAMP camp,IMAGE*image);
	void use(int x, int y, DIRECTION direction);
	void innum(int n);//��������n��
	void show() const;//չʾͼ�������
	virtual void skill(int x, int y, DIRECTION direction)const=0;//ÿ����ʰȡ���ߵ�����������x,y-ʹ�������꣬direction-ʹ�õķ���
};