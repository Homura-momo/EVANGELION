#pragma once
#include"ROLE.h"
class HERO :public ROLE {
protected:
	//��ҵĵ���
	GUN gun;
	KNIFE knife;
	MACHINEGUN machinegun;
	MINE mine;
	SPEAR spear;
	CANNON cannon;
	SHIELD shield;
	PROP* prop[7];//���ߵ�ָ�������
	int prop_i;//prop[7]���±꣬��ʾ��ǰ����������ڼ���
	int gold;//�������
	bool crazy;//�Ƿ��ڡ����ߡ�
	DWORD t_crazy;//���롰���ߡ���ʱ��
public:
	HERO(int HP, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4);
	int getx()const;//����x
	int gety()const;//����y
	int getlength() const;//����length
	bool live()const;//�����Ƿ���ţ�1-���ţ�0-������
	void build(int _x, int _y, DIRECTION _direction);
	void walk(DIRECTION _direction);//����������, _direction-����
	void attack(DIRECTION _direction);//�����򹥻�, _direction-����
	void selectPROP(int x);//ѡ���x������
	void switchPROP();//��˳���л�����
	void reswitchPROP();//����˳���л�����
	void buyprop(int n);//������ߣ�n-���ߵ�prop_s����
	void attacked(int h);
	void detect(int x1, int y1, int x2, int y2, bool move);//�������������Ƿ����������壬�����ж�Ӧ������x1,y1-�������Ͻ����꣬x2,y2-�������½����꣬move-���ǰ���ƶ��Ƿ�ɹ�
	virtual void getgold(int n);//��ý��,n-�����
	void becrazy();//����"����"
	void detectcrazy();//����Ƿ�ر�"����"
	void instrumentality();//ʹ��"����"
	void draw()const;
	void show() const;//չʾ��Ϣ
};