#include "SPEAR.h"


SPEAR::SPEAR(int length, CAMP camp) :PICKPROP(length, camp, &images->spear) {}
void SPEAR::skill(int x, int y, DIRECTION direction)const {//����1���ӵ�
	for (int i = 0; i < attack_n; i++) {
		if (attacks->bullet[i].build(x, y, length, direction, camp, 4, 30, 10, RED))break;
	}
}