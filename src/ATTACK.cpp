#include "ATTACK.h"
ATTACK::ATTACK():x(0), y(0), length(0), height(0), ATK(0),life(0), camp(CAMP::hero), t(0) {}
bool ATTACK::build(int _x, int _y, int _length, DIRECTION direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK) {
	if (!life) {//��������ڣ�����Դ���
		t = GetTickCount();//����ʱ��
		life = 1;
		camp = _camp;
		ATK = _ATK;
		if (direction == UP || direction == DOWN) {//����Ǵ�ֱ�����򳤶Ⱥ͸߶Ⱦ��Ǵ�ֱʱ�ģ�����λ��Ҫ���ݴ����ߵı߳�����
			length = vertical_length;
			height = vertical_height;	
			x = _x + _length / 2 - length / 2;
			if (direction == UP) y = _y - height - 1;
			else y = _y + _length;
		}
		else {//�����ˮƽ�����򳤶Ⱥ͸߶��봹ֱʱ�෴
			length = vertical_height;
			height = vertical_length;	
			y = _y + _length / 2 - height / 2;
			if (direction == LEFT) x = _x - length - 1;
			else x = _x + _length;
		}
		return 1;
	}
	else return 0;
}
