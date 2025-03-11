#pragma once
/* GameData.h
 * -------------
 * ������õ�������
 */
#include "Type.h"
#include <cctype>
#include <cstdlib>
#include <windows.h>

/*����*/
const unsigned GRID = 32; //����һ������ش�С
const unsigned WINDOW_X = 18 * GRID; //���ڵ�x����
const unsigned WINDOW_Y = 18 * GRID; //���ڵ�y����

const unsigned Q_X = 50; //Q����x����
const unsigned Q_Y = 360; //Q����y����
const unsigned SIZE_OF_KEY = 48; //һ����λ�Ĵ�С

const unsigned SPEED = 3; //��ĸһ��ѭ���ƶ��ľ���


const unsigned SIZE_OF_STRINGS = 5; //��ѡ�ַ�������
const unsigned TIME_OF_LETTER = 360; //������ʱ�����һ����ĸ



/*����*/
extern int choice; //����ѡ���ѡ�� 
extern unsigned score; //����
extern unsigned gameTime; //ʱ��
extern Key key[26];
extern Block block[10][4];
extern Letter letterSaved[100], letterCurrent[100]; //�ֱ��ʾδ��������Ļ�ϵ���ĸ���ѳ�������Ļ�ϵ���ĸ
extern int sizeSaved, sizeCurrent; //��ʾletterSaved��letterCurrent����Ĵ�С

/*�ı�����*/
extern char text1[];
extern char text2[];
extern char text3[];
extern char text4[];
extern char text5[];
extern char text6[];
extern char text7[];

/*����*/
#define random(a,b) (rand() % (b - a + 1)) + a //�ض��������
