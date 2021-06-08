/*
 * Personaggio.h
 *
 *  Created on: 7 mar 2021
 *      Author: Andrea
 */
#include <iostream>
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

	void muovi (int mov);

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