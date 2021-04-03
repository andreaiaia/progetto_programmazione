/*
 * mappa.cpp
 *
 *  Created on: 6 mar 2021
 *      Author: Simone
 */

#include "Mappa.h"

Mappa::Mappa() {
	head = new scena ;
	char col[y] = "        "; // 9 spazi bianchi
	head->prev = NULL ;
	for (int i = 0; i < x; i++) {
		// nuovo_schermo
		strcpy(head->schermo[i], col) ;
	}
	head->next = NULL ;
}

scena* Mappa::nuovo_schermo(scena* head) {
	scena*p=head ;
	for(int j=0; j<x; j++) {
		for(int i=0; i<y; i++) {
			p->schermo[j][i]=' ' ;
		}
	}
	int num_piatt = num_random(2)+2 ;
	int h_prec=0 ;
	int o_prec=0 ;
	for(int i=1; i<num_piatt; i++) {
		int h=num_random(3)+2+h_prec ;
		int origine=num_random(y-5)+o_prec;
		if(h<x) genera_piattaforma(p->schermo, h, origine) ;
		h_prec=h ;
		o_prec=origine ;
	}
	return head ;
}

void Mappa::genera_piattaforma(char output[x][y], int altezza, int o) {
	  int origine=o ;
	  int lunghezza=num_random(3)+1 ;
	  if (origine + lunghezza > y-1) lunghezza = y-1-origine;
	  output[altezza][origine]='╔' ;
	  for(int j=origine+1; j<origine+lunghezza; j++) {
	    output[altezza][j]='═' ;
	  }
	  output[altezza][origine+lunghezza]='╗' ;
}

int Mappa::num_random(int max) {
	srand( time(0) ) ;
	int n = (rand() % max+1) ;
	return n ;
}

// ╔ ═ ╗ ¤ ♥
