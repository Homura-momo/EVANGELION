#pragma once
#include"GLOBAL_FUNCTION.h"
#include"IMAGES.h"
extern IMAGES*images;
class BARRIER {
protected:
	int x, y;//λ������
	int length;//�߳�
	IMAGE* image;//ͼ��
	int code;//�ڵ�ͼ�ϵĴ���
	bool life;//�Ƿ��ѱ�����
public:
	BARRIER(int length, int code, IMAGE* image);
	void build(int x, int y);//�����ϰ��x��y-��ʼ����
	void draw()const;//����
};