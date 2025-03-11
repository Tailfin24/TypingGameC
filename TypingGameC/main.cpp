/*
 * 打字小游戏
 * 作者：黄玮琦
 * 编译环境：Visual Studio 2022 + EasyX_20220610
 */

#include "GameData.h"
#include "Initialization.h"
#include "Draw.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <conio.h>




int main() {
	/*窗口创建*/
	SetWindowText(initgraph(WINDOW_X, WINDOW_Y), L"Typing Game");
start:
	/*初始化*/
	srand((unsigned)time(NULL)); //随机数重置
	keyInit(); //重置按键
	blockInit(); //重置砖块状态
	clearData(); //清除已经游玩的数据

	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);

	//绘制选择界面
	drawChoice();

	while (!_kbhit()) {
		char c = _getch();
		choice = c - '0';
		if (choice <= 7 && choice >= 0) {
			break;
		}
	}
	cleardevice();

	/*游戏开始*/
	BeginBatchDraw();
	while (true) {
		//绘制界面
		draw();

		//如果待选字母队列为空，则重新分配字符串
		if (sizeSaved == 0) {
			if (choice == 0) {
				toSaved(readText(random(1, SIZE_OF_STRINGS)));
			}
			else {
				toSaved(readText(choice));
			}
		}
		//生成新的字母
		if (sizeCurrent == 0) {
			Sleep(50);
			gameTime += 50;
			createLetter();
		}
		if (gameTime % TIME_OF_LETTER == 0)
		{
			createLetter();
		}
		//判断是否发生碰撞并进行处理
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

		//判断按键
		getKey();

		//字母移动
		if (sizeCurrent > 0) {
			moveLetter();
		}

		Sleep(15);
		gameTime += 15;
		FlushBatchDraw();
		cleardevice();

		//判断游戏是否结束
		if (gameEnd()) {
			break;
		}


	}

	EndBatchDraw();

	//游戏结束后的操作
	drawEnd();//绘制游戏结束界面

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