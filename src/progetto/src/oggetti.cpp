/*
 * oggetti.cpp
 *
 *  Qui ci sono le classi del protagonista, dei nemici
 *  e degli oggetti bonus del gioco
 */
#include"oggetti.h"

// Funzioni classe Personaggio

	Personaggio::Personaggio(int v, int p[], int a, char r, bool s){
		max_vita = v;
		vita = v;
		posizione[0] = p[0];
		posizione[1] = p[1];
		attacco = a;
		rappresentazione = r;
		scudo = s;
	}

	void Personaggio::muovi(int movX, int movY, int altezza_schermo, int larghezza_schermo){
		if(posizione[0] + movX < larghezza_schermo && posizione[0] + movX > 0) posizione[0] += movX;
		if(posizione[1] + movY < altezza_schermo && posizione[1] + movY > 0) posizione[1] += movY;
	}

	void Personaggio::ferito(int danno) {
		if (scudo) {
			scudo = false;
		} else {
			if (vita - danno > 0) vita -= danno;
			else vita = 0;
		}
	}

	void Personaggio::recupero(int punti_vita) {
		if (vita + punti_vita > max_vita) vita = max_vita;
		else vita += punti_vita;
	}

	int Personaggio::ritorna_attacco() {
		return attacco;
	}

	void Personaggio::attiva_scudo() {
		scudo = true;
	}

	bool Personaggio::ritorna_scudo() {
		return scudo ;
	}

	int Personaggio::ritorna_vita() {
		return vita ;
	}

	void Personaggio::ritorna_posizione(int pos[]) {
		pos[0]=posizione[0] ;
		pos[1]=posizione[1] ;
	}

	char Personaggio::ritorna_aspetto() {
		return rappresentazione;
	}

// Funzioni classe Oggetto

	Oggetto::Oggetto(char r) {
		rappresentazione = r;
	}

	char Oggetto::ritorna_aspetto() {
		return rappresentazione;
	}

// Funzioni classe Cuore

	Cuore::Cuore(int v, char r):Oggetto(r) {
		vita = v;
	}

	int Cuore::punti_vita () {
		return vita;
	}

// Funzioni classe Scudo

	Scudo::Scudo(char r):Oggetto(r) {

	}





