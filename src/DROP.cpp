#include "DROP.h"
DROP::DROP(IMAGE* image, int code) :BARRIER(small_length,code,image){}
bool DROP::build(int _x, int _y) {
	if (!life) {//�����������������ߣ�����Դ���
	BARRIER::build(_x, _y);
	return 1;
	}
	else return 0;
}
void DROP::picked() {
	life = 0;
	setmap(x, y, small_length, empty_s);
}