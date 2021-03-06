// CrypTop Windows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const int displayX = 20;
const int displayY = 10;
const string space = ("  ");
const string star = ("* ");

int i, j, ui, uj;
int display[displayY][displayX];
bool running = false;
bool buffer_changed = false;

void write_buffer_to_display() {
	for (i = 0; i < displayY; i++) {
		for (j = 0; j < displayX; j++) {
			if (display[i][j] == 0) cout << space;
			else cout << star;
		}
		cout << "\n";
	}
}

void keyinput_callback() {
	if ((GetKeyState(0x51) & 0x8000) || (GetKeyState(VK_ESCAPE) & 0x8000)) {			// press q or esc to quit
		running = false;
	}
	else running = true;
	if ((GetKeyState(VK_UP) & 0x8000) && (ui > 0)) {
		display[ui][uj] = 0;
		ui = ui - 1;
		display[ui][uj] = 1;
		buffer_changed = true;
	}
	if ((GetKeyState(VK_DOWN) & 0x8000) && (ui < displayY - 1)) {
		display[ui][uj] = 0;
		ui = ui + 1;
		display[ui][uj] = 1;
		buffer_changed = true;
	}
	if ((GetKeyState(VK_LEFT) & 0x8000) && (uj > 0)) {
		display[ui][uj] = 0;
		uj = uj - 1;
		display[ui][uj] = 1;
		buffer_changed = true;
	}
	if ((GetKeyState(VK_RIGHT) & 0x8000) && (uj < displayX - 1)) {
		display[ui][uj] = 0;
		uj = uj + 1;
		display[ui][uj] = 1;
		buffer_changed = true;
	}
}


int main()
{
	for (i = 0; i < displayY; i++) {
		for (j = 0; j < displayX; j++) {
			display[i][j] = 0;
		}
	}

	ui = uj = 0;
	display[ui][uj] = 1;
	buffer_changed = true;

	do {
		keyinput_callback();
		if (buffer_changed) {
			system("cls");
			write_buffer_to_display();
			buffer_changed = false;
		}
	} while (running);

	return 0;
}

