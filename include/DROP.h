#pragma once
#include"BARRIER.h"
class DROP:public BARRIER{
public:
	DROP(IMAGE* image, int code);
	bool build(int x, int y);////����һ�������x,y-��ʼ���꣬����ֵ�������ɹ�-1,ʧ��-0
	void picked();//��ʰȡ
};