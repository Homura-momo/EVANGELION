#include "BOSSDOOR.h"
BOSSDOOR::BOSSDOOR() :DOOR(large_length, bossdoor_s, &images->bossdoor), status(STATUS::produce) {}
void BOSSDOOR::produce() {
	if (status == STATUS::produce && GetTickCount() - t > 20000) {//���Ϊ����״̬���Ѿ���������20s��������һ��BOSS
		if (create(boss_s))status = STATUS::shut;//�ɹ�����BOSS�������ر�״̬
	}
}
void BOSSDOOR::open() {//������ں����Ϊ����״̬��������ͼ��
	status = STATUS::open;
	image = &images->bossdoor_open;
}
void BOSSDOOR::enter() {//���Ϊ����״̬�������Ϊ������״̬
	if (status == STATUS::open)status = STATUS::entered;
}
bool BOSSDOOR::entered()const {
	if (status == STATUS::entered)return 1;
	else return 0;
}