#pragma once
/* Game.h
 * ---------------
 * ��Ϸ����
 */
#include "GameData.h"
char* readText(int); //ѡ���ַ���

void toSaved(char*); //���ַ���ת��letterSaved������

void createLetter(); //��letterSaved�����еĵ�һ��Ԫ��ת�Ƶ�letterCurrentβ��

void getKey(); //���ܰ���

bool isCollision(Block&, Letter&); //�ж��Ƿ�����ײ

bool isCmpKey(char); //�жϰ������һ����ĸ�Ƿ��Ӧ

void moveLetter(); //�ƶ���ĸ

void clearLetter(Letter* l,unsigned start, int& size); //ɾ��һ����ĸ�����еĵ�һ����ĸ

bool gameEnd(); //�ж���Ϸ�Ƿ����
