#pragma once
#include"CONST.h"
extern void setmap(int x, int y, int length, int code);//��������������Ĵ��룬x,y-���������Ͻ����꣬length-�����α߳�,code-����
extern bool empty(int x1, int y1, int x2, int y2);//�����������Ƿ�Ϊ�գ�x1,y1-�������Ͻ����꣬x2,y2-�������½����꣬����ֵ��������-0������Ϊ��-1
extern bool empty(int x, int y, int length);//��������������Ƿ�Ϊ�գ�x,y-���������Ͻ����꣬length-�����α߳�������ֵ��������-0������Ϊ��-1
extern bool harm(int x1, int y1, int x2, int y2, CAMP camp, int ATK);// �����������������˵�����, ������˺���x1, y1 - �������Ͻ����꣬x2, y2 - �������½����꣬camp - �˺���Դ������Ӫ��ATK - ������������ֵ��1 - ������˺���0 - û����˺�
extern void harmnear(int x, int y, int length, int range, CAMP camp, int ATK);//�ֱ���ĸ�������lengthΪ����rangeΪ��ľ�����������˺���x,y-�˺���Դ���꣬length-�˺���Դ�߳���range-�˺���Χ��camp-�˺���Դ������Ӫ��ATK-������
extern void shownum(int x, int y, int n);//��ָ��λ����ʾ����������x,y-�������Ͻ����꣬n-������ֵ