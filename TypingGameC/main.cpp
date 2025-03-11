/*
 * ����С��Ϸ
 * ���ߣ�������
 * ���뻷����Visual Studio 2022 + EasyX_20220610
 */

#include "GameData.h"
#include "Initialization.h"
#include "Draw.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <conio.h>




int main() {
	/*���ڴ���*/
	SetWindowText(initgraph(WINDOW_X, WINDOW_Y), L"Typing Game");
start:
	/*��ʼ��*/
	srand((unsigned)time(NULL)); //���������
	keyInit(); //���ð���
	blockInit(); //����ש��״̬
	clearData(); //����Ѿ����������

	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);

	//����ѡ�����
	drawChoice();

	while (!_kbhit()) {
		char c = _getch();
		choice = c - '0';
		if (choice <= 7 && choice >= 0) {
			break;
		}
	}
	cleardevice();

	/*��Ϸ��ʼ*/
	BeginBatchDraw();
	while (true) {
		//���ƽ���
		draw();

		//�����ѡ��ĸ����Ϊ�գ������·����ַ���
		if (sizeSaved == 0) {
			if (choice == 0) {
				toSaved(readText(random(1, SIZE_OF_STRINGS)));
			}
			else {
				toSaved(readText(choice));
			}
		}
		//�����µ���ĸ
		if (sizeCurrent == 0) {
			Sleep(50);
			gameTime += 50;
			createLetter();
		}
		if (gameTime % TIME_OF_LETTER == 0)
		{
			createLetter();
		}
		//�ж��Ƿ�����ײ�����д���
		if (sizeCurrent > 0)
		{
			bool iscolli[100] = { false };
			for (int i = 0; i < sizeCurrent; i++) {
				for (int j = 0; j < 4; j++) {
					if (isCollision(block[letterCurrent[i].xgrid - 1][j], letterCurrent[i])) {
						block[letterCurrent[i].xgrid - 1][j].exist = false;
						iscolli[i] = true;
					}
				}
			}
			Sleep(5);
			gameTime += 5;
			for(int i = 0; i < sizeCurrent; i++)
				if (iscolli[i]) {
				clearLetter(letterCurrent, i, sizeCurrent);
			}
		}

		//�жϰ���
		getKey();

		//��ĸ�ƶ�
		if (sizeCurrent > 0) {
			moveLetter();
		}

		Sleep(15);
		gameTime += 15;
		FlushBatchDraw();
		cleardevice();

		//�ж���Ϸ�Ƿ����
		if (gameEnd()) {
			break;
		}


	}

	EndBatchDraw();

	//��Ϸ������Ĳ���
	drawEnd();//������Ϸ��������

	while (!_kbhit()) {
			char c = _getch();
			if (c == 'R' || c == 'r') {
				cleardevice();
				goto start;
			}
			else if(c == 0x1b) {
				cleardevice();
				break;
			}
	}

	closegraph;
	return 0;
}