#ifndef RUBIK
#define RUBIK

#include <cstdlib>
#include <iostream>
using namespace std;

static int random(int min = 0, int max = 2) {
	return rand() / ((double)RAND_MAX+1.0) * (max-min+1) + min;
}

struct Polje {
	int polje[3][3];

	Polje()
	{
		for(int i = 0; i < 3; i++) for(int j = 0; j < 3;) polje[i][j++] = 0;
		int b = random(2, 6);
		for(int i = 0; i < b; i++) polje[random()][random()] = random(1, 2);
	}

	friend bool operator==(const Polje&, const Polje&);
	friend bool operator!=(const Polje&, const Polje&);

	friend ostream& operator<<(ostream&, const Polje&);
};

class Rubik : public Polje {
	int potez;

	Rubik() {}
public:
	Rubik(const Polje& p) : potez(0)
	{
		for(int i = 0; i < 3; i++) for(int j = 0; j < 3;) polje[i][j] = p.polje[i][j++];
		while(*this == p) for(int i = 0; i < 10; i++, potez--)
			switch(random(1, 4)) {
			case 1:	Gore(); break;
			case 2:	Levo(); break;
			case 3:	OkreniL(); break;
			case 4:	OkreniD();
		}
	}

	int BrPoteza()
	{ return potez; }

	void Gore();
	void Dole();
	void Levo();
	void Desno();
	void OkreniL();
	void OkreniD();
};

#endif