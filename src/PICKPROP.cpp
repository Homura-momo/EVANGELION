#include"PICKPROP.h"
extern void shownum(int x, int y, int n);
PICKPROP::PICKPROP(int length, CAMP camp, IMAGE* image) :PROP(length, camp, image), num(0) {}
void PICKPROP::innum(int n) {
	num += n;
}
void PICKPROP::show()const {
	PROP::show();
	shownum(LENGTH - small_length - 25, HEIGHT - 15, num);
}
void PICKPROP::use(int x, int y, DIRECTION direction) {
	if (camp == CAMP::enemy) {//���ʹ�����ǵ��ˣ������ʹ�õ���
		skill(x, y, direction);
	}
	else if (num > 0) {//���������������㹻
		num--;//��������
		skill(x, y, direction);
	}
}