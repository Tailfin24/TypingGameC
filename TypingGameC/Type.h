#pragma once
/* Type.h
 * ---------------
 * �����ṹ�壺�������ש�顢�������ĸ������
 */
struct Block {
	int xgrid; //x��������
	int ygrid; //y��������
	bool exist; //���ש���Ƿ����
};

struct Letter {
	char letter; //��ĸ������
	int xgrid; //x��������
	int y; //y����
};

struct Key {
	bool press; //�Ƿ��µ�״̬
	int x; //������x����
	int y; //������y����
	char letter; //��������Ӧ����ĸ
};
