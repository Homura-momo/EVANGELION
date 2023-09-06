#include "MOBDOOR.h"
MOBDOOR::MOBDOOR(int n) :DOOR(midium_length, mobdoor_s + n, &images->mobdoor) {}
void MOBDOOR::produce() {
	if (life && GetTickCount() - t > 5000) {//ÿ��5s��������С��
		t = GetTickCount();//����ʱ��
		switch (rand() % 5) {//��������������С��
		case 0:
			create(average1_s);
			break;
		case 1:
			create(average2_s);
			break;
		default:
			return;
		}
	}
}