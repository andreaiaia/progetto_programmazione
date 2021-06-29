#include "Personaggio.h"

Personaggio::Personaggio(int pX, int pY){
	posX = pX;
	posY = pY;
	vita = 100;
	score = 10000;
	scudo = false;
}

void Personaggio::incrementascore(HWND hwnd, HRGN punteggio){
	score = score-1;
	InvalidateRgn(hwnd, punteggio, false);         //se score minore di zero agigustaer
}

void Personaggio::muovi(int mov, HWND hwnd, HRGN casachiocciolino){
	if (mov==0){
		posY=posY-47;
	}
	if (mov==1){
		posX=posX+26;
	}
	if (mov==2){
		posY=posY+47;
	}
	if (mov==3){
		posX=posX-26;
	}
	InvalidateRgn(hwnd, casachiocciolino, false);
}

void Personaggio::nuova_posizione(int nX, int nY) {        //aggiustare con la nuova posizione
	posX = nX;
	posY = nY;
}

int Personaggio::ritorna_x() {
	return posX;
}

int Personaggio::ritorna_y() {
	return posY;
}

int Personaggio::lvita() {
	int lunghezzavita = to_string(vita).length();
	return lunghezzavita;
}

int Personaggio::lscore() {
	int lunghezzascore = to_string(score).length();
	return lunghezzascore;
}

int Personaggio::lscudo() {
	int lunghezzascudo;
	if (scudo){
		lunghezzascudo = 2;
	}
	else {
		lunghezzascudo = 3;
	}
	return lunghezzascudo;
}

LPCSTR Personaggio::svita() {
	LPCSTR stringavita = INTTOLPCSTR(vita);
	return stringavita;
}

LPCSTR Personaggio::sscore() {
	LPCSTR stringascore = INTTOLPCSTR(score);
	return stringascore;
}

LPCSTR Personaggio::sscudo() {
	LPCSTR stringascudo;
	if (scudo){
		stringascudo = "ON";
	}
	else {
		stringascudo = "OFF";
	}
	return stringascudo;
}