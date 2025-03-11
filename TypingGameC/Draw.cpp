#include "Draw.h"
#include "GameData.h"

void drawChoice() {
	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"΢���ź�");
	font.lfQuality = DEFAULT_QUALITY;
	font.lfHeight = 32;
	settextstyle(&font);
	settextcolor(BLACK);
	outtextxy(10,10,L"���¶�Ӧ���ֽ���ѡ��");
	outtextxy(32, 2 * 32, L"0:���");
	outtextxy(32, 3 * 32, L"1:���Hello World����");
	outtextxy(32, 4 * 32, L"2:ȫ���г���");
	outtextxy(32, 5 * 32, L"3:�ı��������");
	outtextxy(32, 6 * 32, L"4:�ı�1");
	outtextxy(32, 7 * 32, L"5:�ı�2");
	outtextxy(32, 8 * 32, L"6:�ı�3");
	outtextxy(32, 9 * 32, L"7:�ı�4");
	
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
	/*��������*/
	LOGFONT font;
	gettextstyle(&font);
	wcscpy_s(font.lfFaceName, L"΢���ź�");
	font.lfQuality = DEFAULT_QUALITY;
	/*���Ʊ���*/
	font.lfHeight = 64;
	settextstyle(&font);
	settextcolor(BLACK);
	outtextxy(400, 50, L"����");
	outtextxy(400, 120, L"��Ϸ");


	/*���Ʒ�����ʱ��*/
	font.lfHeight = 32;
	settextstyle(&font);
	settextcolor(BLACK);

	wchar_t str[10];
	wsprintf(str, L"ʱ�䣺%u s", gameTime / 500);
	outtextxy(360, 200, str);
	wsprintf(str, L"������%u", score);
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

	outtextxy(200, 200, L"��Ϸ����!");

	settextcolor(BLACK);
	wchar_t str[10];
	font.lfHeight = 32;
	settextstyle(&font);
	wsprintf(str, L"������%u��!", score);
	outtextxy(200, 300, str);

	font.lfHeight = 28;
	settextstyle(&font);
	outtextxy(190, 350, L"����R�����¿�ʼ");
	outtextxy(200, 400, L"����ESC���˳�");

}
