#pragma once
#include"BARRIER.h"
class SOFT_BARRIER :public BARRIER {
protected:
	int HP;//����ֵ
public:
	SOFT_BARRIER(int length, int code, IMAGE* i, int h);
	void attacked(int h);//�ܹ�����h-�˺�
	virtual void die()const = 0;//��������
};