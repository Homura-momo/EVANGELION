#include"MOB.h"
MOB::MOB(int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code,PROP*prop):ENEMY(midium_length, 10, 15, firerate, i1, i2, i3, i4, code),prop(prop) {}
void MOB::die() const{
	barriers->buildaward(x, y, 10, 5, 1);//���ɽ���
	score += 50;//��������
}
void MOB::attackway(){//С�ֵĹ���������ʹ�õ���
	prop->use(x,y,direction);
}