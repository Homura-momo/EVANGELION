#pragma once
#include "PICKPROP.h"
class SHIELD : public PICKPROP {
public:
	SHIELD(int length, CAMP camp);
	void skill(int x, int y, DIRECTION direction) const;
	void defend(int& h);//�����������˺���h-�˺�
	void show(int x, int y) const;
};