#define _WIN32_WINNT 0x0500

#include "igra.h"
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	HWND console = GetConsoleWindow();
	RECT r; GetWindowRect(console, &r);
	COORD coord; coord.X = 42; coord.Y = 40;
	SetConsoleTitle("C++ Rubik");
	MoveWindow(console, r.left, r.top, 1, 1, TRUE);
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);

	cout << "\n Dobrodosli u C++ Rubik\n\n\n Cilj igre je da dobijete trazeno polje\n okretanjem i pomeranjem datog polja.\n\n Za igranje koristite:\n\n    W A S D - gore/dole/levo/desno\n      Q E   - okreni ulevo/udesno\n     SPACE  - prikazi resenje\n       N    - nova igra\n\n\n Unesite svoje ime: ";
	cin >> ime; cin.ignore(100, '\n'); if(ciga()) return 0;
	do {
		cout.put(7); cekaj();
		int* i = igraj(); if(!i) break;
		cout << "\n            BRAVO, " << ime << "!\n\n  Trebalo ti je " << setw(2) << i[0] << " sekundi i " << setw(2) << i[1] << " poteza.\n\n\n  Pritisni SPACE da zapocnes novu igru,\n  ili bilo koje drugo dugme da izadjes.";
		delete []i;
	} while(getch() == ' ' && !cg);
	return 0;
}