#pragma once
#include"STONE.h"
#include"IRON.h"
#include"TRAP.h"
#include"MOBDOOR.h"
#include"BOSSDOOR.h"
#include"DR_CANNON.h"
#include"DR_GOLD.h"
#include"DR_MACHINEGUN.h"
#include"DR_MINE.h"
#include"DR_SHIELD.h"
#include"DR_SPEAR.h"
struct BARRIERS {
	SOFT_BARRIER* stone[barrier_n];
	SOFT_BARRIER* iron[barrier_n];
	SOFT_BARRIER* trap[barrier_n];
	MOBDOOR* mobdoor[barrier_n];
	BOSSDOOR* bossdoor;
	SOFT_BARRIER** soft_barrier[3];
	DROP* gold[barrier_n];
	DROP* machinegun[barrier_n];
	DROP* spear[barrier_n];
	DROP* mine[barrier_n];
	DROP* cannon[barrier_n];
	DROP* shield[barrier_n];
	DROP** drop[6] = { gold,machinegun,spear,mine,cannon,shield };
	BARRIERS();
	~BARRIERS();
	void draw()const;//����
	void produce();//���ɵ���
	void buildaward(int x, int y, int total, int r_gold, int r_prop);//����һ�����߻��ң�x,y-λ�ã�r_prop/total-ÿ�����ߵĸ��ʣ�r_gold/toal-��Ҹ���
};