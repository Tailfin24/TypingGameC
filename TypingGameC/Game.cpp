#include "Game.h"

char* readText(int n) {
	char* p = text1;
	switch (n) {
	case 1: p = text1; break;
	case 2: p = text2; break;
	case 3: p = text3; break;
	case 4: p = text4; break;
	case 5: p = text5; break;
	case 6: p = text6; break;
	case 7: p = text7; break;
	default: p = text1;
	}
	return p;
}
void toSaved(char* s) {
	char c;
	int j = 0;
	for (int i = 0; s[i] != 0; i++) {
		if (isalpha(c = s[i])) {
			if (c >= 'a') {
				c -= 32;
			}
			letterSaved[i].letter = c;
			letterSaved[i].xgrid = random(1, 10);
			letterSaved[i].y = GRID;
			sizeSaved++;
			j++;
		}
	}
}

void createLetter() {
	letterCurrent[sizeCurrent].letter = letterSaved[0].letter;
	letterCurrent[sizeCurrent].xgrid = letterSaved[0].xgrid;
	letterCurrent[sizeCurrent].y = letterSaved[0].y;
	clearLetter(letterSaved, 0, sizeSaved);
	sizeCurrent++;
}

void getKey() {
	for (int currentKey = 'A'; currentKey <= 'Z'; currentKey++) {
		if (GetAsyncKeyState(currentKey)) {
			key[currentKey - 'A'].press = true;
			if (sizeCurrent > 0 && isCmpKey(currentKey)) {
				clearLetter(letterCurrent, 0, sizeCurrent);
				score += 1;
			}
		}
		else {
			key[currentKey - 'A'].press = false;
		}
	}
}

bool isCollision(Block& b, Letter& l) {
	return (b.exist && b.ygrid * GRID <= l.y + GRID);
} 

bool isCmpKey(char k) {
	return (k == letterCurrent[0].letter);
} 

void moveLetter() {
	for (int i = 0; i < sizeCurrent; i++) {
		letterCurrent[i].y += SPEED;
	}
} 

void clearLetter(Letter* l,unsigned start, int& size) {
	if (size > 1) {
		for (int i = start; i < size - 1; i++) {
			l[i].letter = l[i + 1].letter;
			l[i].xgrid = l[i + 1].xgrid;
			l[i].y = l[i + 1].y;
		}
	}
	size--;
}

bool gameEnd() {
	return (sizeCurrent > 0 && letterCurrent[0].y >= 9 * GRID + 6);
}
