#include "TRAP.h"
#include"BARRIERS.h"
extern BARRIERS* barriers;
TRAP::TRAP(int n) :SOFT_BARRIER(small_length, trap_s + n, &images->trap, 5) {}
void TRAP::die()const {//���ɽ����Ϊ����
	barriers->buildaward(x, y, 2, 1, 0);//���ɽ���
}