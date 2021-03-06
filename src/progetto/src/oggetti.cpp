/*
 * oggetti.cpp
 *
 *  Qui ci sono le classi del protagonista, dei nemici
 *  e degli oggetti bonus del gioco
 */

#include <iostream>
using namespace std;

class personaggio {
protected:
	int max_vita;
	int vita;
	int posizione[2];	// posizione[0] è la x, posizione[1] è y
	int attacco;
	char rappresentazione;
	bool scudo;

public:
	personaggio(int v, int p[], int a, char r, bool s){
		max_vita = v;
		vita = v;
		posizione[0] = p[0];
		posizione[1] = p[1];
		attacco = a;
		rappresentazione = r;
		scudo = s;
	}

	void muovi(int movX, int movY){		// TODO: check per quando si va fuori schermo
		posizione[0] += movX;
		posizione[1] += movY;
	}
/*

	void muovi(int movX, int movY, int altezza_schermo, int larghezza_schermo){
		if(posizione[0] + movX < larghezza_schermo) posizione[0] += movX;
		if(posizione[1] + movY < altezza_schermo) posizione[1] += movY;
	}

*/
	void ferito(int danno) {
		if (scudo) {
			scudo = false;
		} else {
			if (vita - danno > 0) vita -= danno;
			else vita = 0;
		}
	}

	void recupero(int punti_vita) {
		if (vita + punti_vita > max_vita) vita = max_vita;
		else vita += punti_vita;
	}

	int colpisci() {
		return attacco;
	}

	void attiva_scudo() {
		scudo = true;
	}

	char aspetto() {
		return rappresentazione;
	}
};

class oggetto {
protected:
	char rappresentazione;

public:
	oggetto(char r) {
		rappresentazione = r;
	}

	char aspetto() {
		return rappresentazione;
	}
};

class cuore:public oggetto {
protected:
	int vita;
public:
	cuore(int v, char r):oggetto(r) {
		vita = v;
	}

	int punti_vita () {
		return vita;
	}
};

class scudo:public oggetto {
public:
	scudo(char r):oggetto(r) {

	}
};





