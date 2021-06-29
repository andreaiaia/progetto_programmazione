#include <iostream>
#include <Windows.h>
#include "Funzioni.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Personaggio {
protected:
	int posX;
	int posY;
	int vita;
	int score;
	bool scudo;

public:
	Personaggio (int pX, int pY);

	void incrementascore(HWND hwnd, HRGN punteggio);

	void muovi (int mov, HWND hwnd, HRGN casachiocciolino);

	void nuova_posizione (int nX, int nY);

	int ritorna_x ();

	int ritorna_y ();

	int lvita();

	int lscore();

	int lscudo();

	LPCSTR svita();

	LPCSTR sscore();

	LPCSTR sscudo();
};