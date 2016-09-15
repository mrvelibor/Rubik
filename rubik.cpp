#include "rubik.h"
#include <Windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void Rubik::Gore()
{
	potez++;
	int niz[3];
	for(int j = 0; j < 3; j++) niz[j] = polje[0][j];
	for(int i = 0; i < 2; i++) for(int j = 0; j < 3; j++) polje[i][j] = polje[i+1][j];
	for(int j = 0; j < 3; j++) polje[2][j] = niz[j];
}
void Rubik::Dole()
{ Gore(); potez--; Gore(); }

void Rubik::Levo()
{
	potez++;
	int niz[3];
	for(int i = 0; i < 3; i++) niz[i] = polje[i][0];
	for(int j = 0; j < 2; j++) for(int i = 0; i < 3; i++) polje[i][j] = polje[i][j+1];
	for(int i = 0; i < 3; i++) polje[i][2] = niz[i];
}
void Rubik::Desno()
{ Levo(); potez--; Levo(); }

void Rubik::OkreniL()
{
	potez++;
	int n = polje[0][0];
	polje[0][0] = polje[0][1];
	polje[0][1] = polje[0][2];
	polje[0][2] = polje[1][2];
	polje[1][2] = polje[2][2];
	polje[2][2] = polje[2][1];
	polje[2][1] = polje[2][0];
	polje[2][0] = polje[1][0];
	polje[1][0] = n;
}
void Rubik::OkreniD()
{
	potez++;
	int n = polje[0][0];
	polje[0][0] = polje[1][0];
	polje[1][0] = polje[2][0];
	polje[2][0] = polje[2][1];
	polje[2][1] = polje[2][2];
	polje[2][2] = polje[1][2];
	polje[1][2] = polje[0][2];
	polje[0][2] = polje[0][1];
	polje[0][1] = n;
}

bool operator==(const Polje& a, const Polje& b)
{
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(a.polje[i][j] != b.polje[i][j]) return false;
	return true;
}
bool operator!=(const Polje& a, const Polje& b)
{
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(a.polje[i][j] != b.polje[i][j]) return true;
	return false;
}

ostream& operator<<(ostream& it, const Polje& p)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	char c[15] = " ############";

	it << "\n ";
	for(int i = 0; i < 3; i++) {
		for(int k = 0; k++ < 8; it << "\n ")
			for(int j = 0; j < 3; j++)
				switch(p.polje[i][j]) {
				case 1:	SetConsoleTextAttribute (h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); it << c;
						break;
				case 2:	SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_INTENSITY); it << c;
						break;
				case 0:	SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); it << c;
		}
		it << "\n ";
	}
	SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return it;
}