#include "Initialization.h"

void keyInit() {
	for (int i = 0; i < 26; i++) {
		key[i].letter = 'A' + i;
		key[i].x = keyX('A' + i);
		key[i].y = keyY('A' + i);
		key[i].press = false;
	}
}
int keyX(char k) {
	switch (k) {
	case 'Q': return Q_X;
	case 'W': return Q_X + SIZE_OF_KEY;
	case 'E': return Q_X + 2 * SIZE_OF_KEY;
	case 'R': return Q_X + 3 * SIZE_OF_KEY;
	case 'T': return Q_X + 4 * SIZE_OF_KEY;
	case 'Y': return Q_X + 5 * SIZE_OF_KEY;
	case 'U': return Q_X + 6 * SIZE_OF_KEY;
	case 'I': return Q_X + 7 * SIZE_OF_KEY;
	case 'O': return Q_X + 8 * SIZE_OF_KEY;
	case 'P': return Q_X + 9 * SIZE_OF_KEY;
	case 'A': return Q_X + 0.25 * SIZE_OF_KEY;
	case 'S': return Q_X + 1.25 * SIZE_OF_KEY;
	case 'D': return Q_X + 2.25 * SIZE_OF_KEY;
	case 'F': return Q_X + 3.25 * SIZE_OF_KEY;
	case 'G': return Q_X + 4.25 * SIZE_OF_KEY;
	case 'H': return Q_X + 5.25 * SIZE_OF_KEY;
	case 'J': return Q_X + 6.25 * SIZE_OF_KEY;
	case 'K': return Q_X + 7.25 * SIZE_OF_KEY;
	case 'L': return Q_X + 8.25 * SIZE_OF_KEY;
	case 'Z': return Q_X + 0.75 * SIZE_OF_KEY;
	case 'X': return Q_X + 1.75 * SIZE_OF_KEY;
	case 'C': return Q_X + 2.75 * SIZE_OF_KEY;
	case 'V': return Q_X + 3.75 * SIZE_OF_KEY;
	case 'B': return Q_X + 4.75 * SIZE_OF_KEY;
	case 'N': return Q_X + 5.75 * SIZE_OF_KEY;
	case 'M': return Q_X + 6.75 * SIZE_OF_KEY;
	}
}

int keyY(char k) {
	switch (k) {
	case 'Q': case 'W':case 'E': case 'R':case 'T': case 'Y':case 'U': case 'I':case 'O': case 'P':
		return Q_Y;
	case 'A':case 'S':case 'D':case 'F':case 'G':case 'H':case 'J':case 'K': case 'L':
		return Q_Y + SIZE_OF_KEY;
	case 'Z':case 'X':case 'C':case 'V':case 'B':case 'N': case 'M':
		return Q_Y + 2 * SIZE_OF_KEY;
	}
}

void blockInit() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			block[i][j].exist = true;
			block[i][j].xgrid = i + 1;
			block[i][j].ygrid = j + 6;
		}
	}
}

void clearData() {
	sizeCurrent = 0;
	sizeSaved = 0;
	score = 0;
	gameTime = 0;
}