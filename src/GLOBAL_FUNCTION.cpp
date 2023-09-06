#include"GLOBAL_FUNCTION.h"
#include"HERO.h"
#include"ENEMYS.h"
extern HERO* hero;
extern ENEMYS*enemys;
extern int map[LENGTH][HEIGHT];
void setmap(int x, int y, int length, int code) {
	for (int i = x; i < x + length; i++)
		for (int j = y; j < y + length; j++) {
			map[j][i] = code;
		}
}
bool empty(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 >= LENGTH || y2 >= HEIGHT)return 0;//���磬��Ϊ��
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {
			if (map[j][i] != empty_s) return 0;//ֻҪ�����壬�Ͳ�Ϊ��
		}
	return 1;
}
bool empty(int x, int y, int length) {
	return empty(x, y, x + length - 1, y + length - 1);
}
bool harm(int x1, int y1, int x2, int y2, CAMP camp, int ATK) {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {//��������ڵĵ�ͼ���룬���ݴ��뷴�Ƹ����������
			if (i >= 0 && i < LENGTH && j >= 0 && j < HEIGHT && map[j][i] != empty_s) {
				if (map[j][i] >= stone_s && map[j][i] < stone_s + barrier_n) {//�����ͼ������stone_s��stone_s+barrier_n��Χ�ڣ�˵����������һ��STONE�����
					barriers->stone[map[j][i] - stone_s]->attacked(ATK);//�õ�ͼ�����ȥSTONE�����ʼ����õ����STONE����������±꣬Ȼ���������˺�
					return 1;
				}
				else if (map[j][i] >= iron_s && map[j][i] < iron_s + barrier_n) {
					barriers->iron[map[j][i] - iron_s]->attacked(ATK);
					return 1;
				}
				else if (map[j][i] >= trap_s && map[j][i] < trap_s + barrier_n) {
					barriers->trap[map[j][i] - trap_s]->attacked(ATK);
					return 1;
				}
				else switch (camp) {
				case CAMP::hero://ֻ�ܱ�����˺�
					if (map[j][i] >= average1_s && map[j][i] < average1_s + mob_n) {
						enemys->average1[map[j][i] - average1_s]->attacked(ATK);
						return 1;
					}
					else if (map[j][i] >= average2_s && map[j][i] < average2_s + mob_n) {
						enemys->average2[map[j][i] - average2_s]->attacked(ATK);
						return 1;
					}
					else if (map[j][i] == boss_s) {
						enemys->boss->attacked(ATK);
						return 1;
					}
					break;
				case CAMP::enemy://ֻ�ܱ������˺�
					if (map[j][i] == hero_s) {
						hero->attacked(ATK);
						return 1;
					}
					break;
				}
			}
		}
	return 0;
}
void harmnear(int x, int y, int length, int range, CAMP camp, int ATK) {
	harm(x, y - range, x + length - 1, y - 1, camp, ATK);
	harm(x, y + length, x + length - 1, y + length + range - 1, camp, ATK);
	harm(x - range, y, x - 1, y + length - 1, camp, ATK);
	harm(x + length, y, x + length + range - 1, y + length - 1, camp, ATK);
}
void shownum(int x,int y,int n) {
	settextstyle(15, 0, _T("����"));
	setbkmode(TRANSPARENT);//���屳��͸��
	//��int�ͱ���ת����TCHAR�����
	TCHAR s[10];
    wsprintf(s,TEXT("%i"),n);
	outtextxy(x, y,s);
}