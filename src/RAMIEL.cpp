#include "RAMIEL.h"
RAMIEL::RAMIEL() :BOSS(100, 20, 2000, &images->ramiel[UP], &images->ramiel[DOWN], &images->ramiel[LEFT], &images->ramiel[RIGHT]), cannon(length,CAMP::enemy,8), shield(length, CAMP::enemy),prop(&cannon) {
}
void RAMIEL::skill(){
	if (rand() % 10 == 0) {//����л�����
		if (prop == &cannon) {
			prop = &shield;
			shield.innum(50);//���Ӷ����������ڷ���
		}
		else prop = &cannon;
	}
	for (DIRECTION d = UP; d <= RIGHT; d = (DIRECTION)(d + 1))prop->use(x, y, d);//���ĸ�����ʹ�õ���
}
void RAMIEL::draw()const{
	if (prop == &shield)shield.show(x, y);//�����ǰ�����Ƕ��ƣ�չʾ����
	BOSS::draw();
}
void RAMIEL::reaction(int& h){
	if (prop== &shield)shield.defend(h);//����ʱ�������ǰ�����Ƕ��ƣ��������Ʒ���
}