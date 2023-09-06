#include"MACHINEGUN.h"
MACHINEGUN::MACHINEGUN(int length, CAMP camp) :PICKPROP(length, camp, &images->machinegun) {}
void MACHINEGUN::skill(int x, int y, DIRECTION direction)const {//����3���ӵ�
	int tempx[3] = { x,x,x };//ÿ���ӵ��ĺ�����
	int tempy[3] = { y,y,y };//ÿ���ӵ���������
	if (direction == UP || direction == DOWN) {//���䷽��Ϊ�ϣ��£����������ӵ���ˮƽ���겻ͬ
		tempx[1] -= 8;
		tempx[2] += 8;
	}
	else {//���䷽��Ϊ���ң����������ӵ���ˮƽ���겻ͬ
		tempy[1] -= 8;
		tempy[2] += 8;
	}
	for (int j = 0; j < 3; j++) {//ѭ������3���ӵ�
		for (int i = 0; i < attack_n; i++) {
			if (attacks->bullet[i].build(tempx[j], tempy[j], length, direction, camp, 4, 4, 1, WHITE))break;
		}
	}
}