#pragma once
#include"DOOR.h"
class BOSSDOOR :public DOOR {
private:
	enum class STATUS { produce, shut, open, entered }status;//״̬,��Ϊ����״̬���ر�״̬������״̬���ѽ���״̬
public:
	BOSSDOOR();
	void produce();//����BOSS
	void open();//�򿪳���
	void enter();//�������
	bool entered()const;//�����Ƿ�����˳��ڣ���-1����-0
};