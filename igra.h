#include "rubik.h"
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

char ime[30];
bool cg = false, mil = true;

int cekaj(double sec = 1) {
  clock_t end;

  end = clock() + sec*1000;
  while (clock() < end) if(kbhit()) if(getch() == 27) return 1;
  return 0;
}

int ciga() {
	if(!strcmp(ime, "ciga") || !strcmp(ime, "CIGA") || !strcmp(ime, "Ciga") || !strcmp(ime, "cigan") || !strcmp(ime, "Cigan") || !strcmp(ime, "CIGAN")) {
		cg = true;
		system("cls"); cout << "Bezi bre, cigane!\n";
		char odg[100]; cin.getline(odg, 100, '\n');
		if(!strcmp(odg, "a pusti me, molim te!") || !strcmp(odg, "a pusti me, bar jednu") || !strcmp(odg, "daj, ne budi cigan") || !strcmp(odg, "nemoj si cigan!") || !strcmp(odg, "samo jednu")) return 0;
		return 1;
	}
	return 0;
}

int* igraj() {
	Polje resenje;
	Rubik igra(resenje);

	system("cls"); cout << "\n                SPREMI SE!\n" << resenje;
	for(int i = 0; i < 2 ; i++) {
		cout.put(7);
		if(cekaj()) return NULL;
	}
	system("cls"); cout << "\n                  POCNI!\n" << igra << "    W A S D - gore/dole/levo/desno\n       Q E   - okreni ulevo/udesno\n      SPACE  - prikazi resenje\n        N    - nova igra\n       ESC   - izadji\n";
	
	int start = clock();
	while(igra != resenje) if(kbhit()) {
		int i = 0;
		switch(getch()) {
		case 'w':
		case 'W':	igra.Gore(); break;
		case 's':
		case 'S':	igra.Dole(); break;
		case 'a':
		case 'A':	igra.Levo(); break;
		case 'd':
		case 'D':	igra.Desno(); break;
		case 'q':
		case 'Q':	igra.OkreniL(); break;
		case 'e':
		case 'E':	igra.OkreniD(); break;
		case ' ':	system("cls"); cout << "\n               - RESENjE -\n" << resenje << "\n\n      SPACE  -  skloni resenje\n";
					while(char c = getch() != ' ') if(c == 27) return NULL;
					break;
		case 'n':
		case 'N':	if(cg) return NULL;
					cout << (char)7;
					if(cekaj()) return NULL;
					return igraj();
		case 27:	return NULL;
		default:	continue;
		}
		system("cls");
		cout << "\n   vreme: " << setfill('0') << setw(2) << (int)(difftime(clock(), start) / (60*CLOCKS_PER_SEC)) << ':' << setw(2) << (int)(difftime(clock(), start) / CLOCKS_PER_SEC) % 60 << "        broj poteza: " << setw(3) << igra.BrPoteza() << endl << igra << "    W A S D - gore/dole/levo/desno\n       Q E   - okreni ulevo/udesno\n      SPACE  - prikazi resenje\n        N    - nova igra\n       ESC   - izadji\n" << setfill(' ');
	}
	int *podaci = new int[2]; podaci[0] = difftime(clock(), start)/CLOCKS_PER_SEC; podaci[1] = igra.BrPoteza();
	system("cls"); cout << "\n                 POBEDA!\n" << resenje;
	for(int i = 0; i < 3; i++) {
		cout << (char)7; cekaj(0.3);
	}
	return podaci;
}