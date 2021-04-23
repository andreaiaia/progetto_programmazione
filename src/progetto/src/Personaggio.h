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
	int max_vita;
	int vita;
	int posizione[2];	// posizione[0] � la x, posizione[1] � y
	int attacco;
	char rappresentazione;
	bool scudo;

public:
	Personaggio(int v, int p[], int a, char r, bool s) ;

	void nuova_posizione(int, int);

	void muovi(int movX, int movY) ;

	void ferito(int danno) ;

	void recupero(int punti_vita) ;

	int ritorna_attacco() ;

	void attiva_scudo() ;

	bool ritorna_scudo() ;

	int ritorna_vita() ;

	void ritorna_posizione( int pos[]) ;

	char ritorna_aspetto() ;
};


