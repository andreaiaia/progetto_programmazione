/*
 * oggetti.h
 *
 *  Created on: 26 feb 2021
 *      Author: Andrea
 */
#include <iostream>
using namespace std;

class Personaggio {
protected:
	int max_vita;
	int vita;
	int posizione[2];	// posizione[0] è la x, posizione[1] è y
	int attacco;
	char rappresentazione;
	bool scudo;

public:
	Personaggio(int v, int p[], int a, char r, bool s) ;

	void muovi(int movX, int movY, int altezza_schermo, int larghezza_schermo) ;

	void ferito(int danno) ;

	void recupero(int punti_vita) ;

	int ritorna_attacco() ;

	void attiva_scudo() ;

	bool ritorna_scudo() ;

	int ritorna_vita() ;

	void ritorna_posizione( int pos[]) ;

	char ritorna_aspetto() ;
};

class Oggetto {
protected:
	char rappresentazione;

public:
	Oggetto(char r) ;

	char ritorna_aspetto() ;
};

class Cuore:public Oggetto {
protected:
	int vita;
public:
	Cuore(int v, char r) ;

	int punti_vita () ;
};

class Scudo:public Oggetto {
public:
	Scudo(char r) ;
};
