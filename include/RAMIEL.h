#pragma once
#include "BOSS.h"
class RAMIEL : public BOSS {
private:
	CANNON cannon;
	SHIELD shield;
	PROP* prop;//�Ե�ǰ���ߵ�ָ��
public:
	RAMIEL();
	void skill();
	void draw()const;
	void reaction(int& h);
};