// CrypTop Windows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const int displayX = 10;
const int displayY = 5;
const string dash = ("` ");
const string star = ("* ");

int i, j, ui, uj;
int display[displayY][displayX];

void reset_display_buffer() {
	for (i = 0; i < displayY; i++) {
		for (j = 0; j < displayX; j++) {
			display[i][j] = 0;
		}
	}
}


int main()
{
	reset_display_buffer();

	cout << "\n Please input the x-coordinate: \n";
	cin >> uj;
	cout << "Please input the y-coordinate: \n";
	cin >> ui;

	display[ui - 1][uj - 1] = 1;

	for (i = 0; i < displayY; i++) {
		for (j = 0; j < displayX; j++) {
			if (display[i][j] == 0) cout << dash;
			else cout << star;
		}
		cout << "\n";
	}

	cin >> ui;

	return 0;
}

