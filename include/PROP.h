#pragma once
#include"IMAGES.h"
#include"ATTACKS.h"
extern IMAGES* images;
extern ATTACKS* attacks;
class PROP {
protected:
	CAMP camp;//����ʹ����������Ӫ
	int length;//�߳�
	IMAGE* image;//ͼ��
public:
	PROP(int lentgh, CAMP camp, IMAGE* image);
	virtual void show() const;//չʾ������Ϣ
	virtual void use(int x, int y, DIRECTION direction) = 0;//ʹ�õ��ߣ�x,y-ʹ�õ�λ�ã�direction-ʹ�õķ���
};