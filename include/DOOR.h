#pragma once
#include "BARRIER.h"
class DOOR :public BARRIER {
protected:
	DWORD t;//��������ʱ��
public:
	DOOR(int length, int code, IMAGE* image);
	void build(int _x, int _y);
	bool create(int n);//���ɵ��ˣ�n-���˵Ĵ��룬����ֵ���ɹ�����-1��ʧ��-0
	virtual void produce() = 0;//��������
};

