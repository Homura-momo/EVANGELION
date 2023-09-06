#include"BARRIERS.h"
BARRIERS::BARRIERS():soft_barrier{ stone,iron,trap },drop{ gold,machinegun,spear,mine,cannon,shield } {
	for (int i = 0; i < barrier_n; i++) {
		stone[i] = new STONE(i);
		trap[i] = new TRAP(i);
		iron[i] = new IRON(i);
		mobdoor[i] = new MOBDOOR(i);
		gold[i] = new DR_GOLD(i);
		machinegun[i] = new DR_MACHINEGUN(i);
		spear[i] = new DR_SPEAR(i);
		mine[i] = new DR_MINE(i);
		cannon[i] = new DR_CANNON(i);
		shield[i] = new DR_SHIELD(i);
	}
	bossdoor = new BOSSDOOR;
}
BARRIERS::~BARRIERS() {
	for (int i = 0; i < barrier_n; i++) {
		for (int j = 0; j < 3; j++)delete soft_barrier[j][i];
		for (int j = 0; j < 6; j++)delete drop[j][i];
		delete mobdoor[i];
	}
	delete bossdoor;
}
void BARRIERS::draw()const {
	for (int i = 0; i < barrier_n; i++) {
		for (int j = 0; j < 3; j++)soft_barrier[j][i]->draw();
		for (int j = 0; j < 6; j++) drop[j][i]->draw();
		mobdoor[i]->draw();
	}
	bossdoor->draw();
}
void BARRIERS::produce() {
	for (int i = 0; i < barrier_n; i++)mobdoor[i]->produce();
	bossdoor->produce();
}
void BARRIERS::buildaward(int x, int y, int total, int r_gold, int r_prop) {
	int kind;//����DROP**drop[6]���±꣬ȷ��Ҫ���ɵ�δʰȡ���ߵ����࣬Ĭ��Ϊ���	
	int r = rand() % total;//һ����total�������
	if (r >= r_gold + 5 * r_prop)return;//��������˽�Һ͵��ߵ����䣬��ֹͣ����
	else if (r >= 0 && r < r_gold)kind = 0;//�ڽ�ҵ������ڣ������ɽ��
	else {
		for (kind = 1; kind < 6; kind++) {//������ĸ����ߵ�������
			if (r >= r_gold + (kind - 1) * r_prop && r < r_gold + kind * r_prop) break;//ÿ�����ߵ����䳤����r_prop,�������������ɵ���
		}
	}
	for (int i = 0; i < barrier_n; i++) {
		if (drop[kind][i]->build(x, y))
			break;//�ɹ�����һ����������ʱ����ѭ��
	}
}