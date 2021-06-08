/*
 * Personaggio.cpp
 *
 *  Created on: 7 mar 2021
 *      Author: Andrea
 */

#include "Personaggio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numerocifre(int intero){
	if(intero==0) return 1;
	else{
	int n=0;
	while(intero>0){
    intero=intero/10;
    n=n+1;
	}
	return n;
	}
}

LPCSTR INTTOLPCSTR(int intero){
	int ncifre = numerocifre(intero);
	LPCSTR stringa[ncifre];
	int resto;
	int c = ncifre-1;
	int i=0;
	while (i<ncifre){
    stringa[i]="0";
    i=i+1;
	}
	stringa[ncifre]="\0";
	while (intero>0){
		resto=intero%10;
		intero=intero/10;
		switch (resto){
		case 0:
			stringa[c]="0";
			break;
		case 1:
			stringa[c]="1";
			break;
		case 2:
			stringa[c]="2";
			break;
		case 3:
			stringa[c]="3";
			break;
		case 4:
			stringa[c]="4";
			break;
		case 5:
			stringa[c]="5";
			break;
		case 6:
			stringa[c]="6";
			break;
		case 7:
			stringa[c]="7";
			break;
		case 8:
			stringa[c]="8";
			break;
		case 9:
			stringa[c]="9";
			break;
		default:
			break;
		}
		c=c-1;
	}
	return stringa[];
}

Personaggio::Personaggio(int pX, int pY){
	posX = pX;
	posY = pY;
	vita = 100;
	score = 0;
	scudo = false;
}

void Personaggio::muovi(int mov){
	if (mov==0){
		posY=posY-1;
	}
	if (mov==1){
		posX=posX+1;
	}
	if (mov==2){
		posY=posY+1;
	}
	if (mov==3){
		posX=posX-1;
	}
}

void Personaggio::nuova_posizione(int nX, int nY) {
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

