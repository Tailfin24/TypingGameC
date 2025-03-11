#include "Draw.h"
#include "GameData.h"

void drawChoice() {
	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"微软雅黑");
	font.lfQuality = DEFAULT_QUALITY;
	font.lfHeight = 32;
	settextstyle(&font);
	settextcolor(BLACK);
	outtextxy(10,10,L"按下对应数字进行选择");
	outtextxy(32, 2 * 32, L"0:随机");
	outtextxy(32, 3 * 32, L"1:输出Hello World程序");
	outtextxy(32, 4 * 32, L"2:全排列程序");
	outtextxy(32, 5 * 32, L"3:文本输出程序");
	outtextxy(32, 6 * 32, L"4:文本1");
	outtextxy(32, 7 * 32, L"5:文本2");
	outtextxy(32, 8 * 32, L"6:文本3");
	outtextxy(32, 9 * 32, L"7:文本4");
	
}
void draw() {
	drawMap();
	drawText();
	drawBlocks();
	drawKeyBoard();
	if (sizeCurrent > 0) {
		drawLetter();
	}
}

void drawMap() {
	roundrect(16, 16, WINDOW_X - 16, WINDOW_Y - 16, 16, 16);
	rectangle(GRID, GRID, 11 * GRID, 10 * GRID);
}

void drawText() {
	/*字体设置*/
	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"微软雅黑");
	font.lfQuality = DEFAULT_QUALITY;
	/*绘制标题*/
	font.lfHeight = 64;
	settextstyle(&font);
	settextcolor(BLACK);
	outtextxy(400, 50, L"打字");
	outtextxy(400, 120, L"游戏");


	/*绘制分数与时间*/
	font.lfHeight = 32;
	settextstyle(&font);
	settextcolor(BLACK);

	wchar_t str[10];
	wsprintf(str, L"时间：%u s", gameTime / 500);
	outtextxy(360, 200, str);
	wsprintf(str, L"分数：%u", score);
	outtextxy(360, 240, str);
}

void drawBlocks() {
	for (int i = 0; i < 26; i++) {
		for(int j = 0; j < 4; j++) {
			if (block[i][j].exist) {
				setfillcolor(BLACK);
				fillrectangle(block[i][j].xgrid * GRID + 2, block[i][j].ygrid * GRID + 2,
					(block[i][j].xgrid + 1) * GRID - 2, (block[i][j].ygrid + 1) * GRID - 2);

				setfillcolor(BROWN);
				fillrectangle(block[i][j].xgrid * GRID + 4, block[i][j].ygrid * GRID + 4,
					(block[i][j].xgrid + 1) * GRID - 4, (block[i][j].ygrid + 1) * GRID - 4);
			}
		}
	}
}

void drawKeyBoard() {
	for (int i = 0; i < 26; i++) {
		if (key[i].press) {
			keyPress(i);
		}
		keyDraw(i);
	}
}

void keyPress(int i) {
	setbkmode(OPAQUE);
	setfillcolor(0XFF7A7A);
	fillrectangle(key[i].x, key[i].y, key[i].x + SIZE_OF_KEY, key[i].y + SIZE_OF_KEY);
}

void keyDraw(int i) {
	setfillcolor(BLACK);
	rectangle(key[i].x, key[i].y, key[i].x + SIZE_OF_KEY, key[i].y + SIZE_OF_KEY);
	setbkmode(TRANSPARENT);

	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"Arial");
	font.lfQuality = DEFAULT_QUALITY;
	font.lfHeight = 24;
	settextstyle(&font);
	settextcolor(BLACK);
	outtextxy(key[i].x + 12, key[i].y + 12, key[i].letter);
}

void drawLetter() {
	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"Arial");
	font.lfQuality = DEFAULT_QUALITY;
	font.lfHeight = 24;
	settextstyle(&font);
	settextcolor(BLACK);

	for (int i = 0; i < sizeCurrent; i++) {
		if (i == 0) {
			setfillcolor(0XFF7A7A);
			fillrectangle(letterCurrent[i].xgrid * GRID, letterCurrent[i].y,
				(letterCurrent[i].xgrid + 1) * GRID, letterCurrent[i].y + GRID);
		}
		setbkmode(TRANSPARENT);
		outtextxy(letterCurrent[i].xgrid * GRID + 8, letterCurrent[i].y + 6, letterCurrent[i].letter);
		setbkmode(OPAQUE);
	}
}

void drawEnd() {
	setfillcolor(WHITE);
	fillrectangle(100, 100, WINDOW_X - 100, WINDOW_Y - 100);
	setlinecolor(BLACK);
	rectangle(100, 100, WINDOW_X - 100, WINDOW_Y - 100);

	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"Arial");
	font.lfQuality = DEFAULT_QUALITY;
	font.lfHeight = 48;
	settextstyle(&font);
	settextcolor(RED);

	outtextxy(200, 200, L"游戏结束!");

	settextcolor(BLACK);
	wchar_t str[10];
	font.lfHeight = 32;
	settextstyle(&font);
	wsprintf(str, L"你获得了%u分!", score);
	outtextxy(200, 300, str);

	font.lfHeight = 28;
	settextstyle(&font);
	outtextxy(190, 350, L"按下R键重新开始");
	outtextxy(200, 400, L"按下ESC键退出");

}
