/*
 * mappa.cpp
 *
 *  Created on: 6 mar 2021
 *      Author: Simone
 */

#include "Mappa.h"

Mappa::Mappa() {
	head = nuovo_schermo() ;
	head->prev = NULL ;
	head->next = NULL ;
}

scena* Mappa::nuovo_schermo() {
	scena*p= new scena ;
	for(int j=0; j<x; j++) {
				for(int i=0; i<y; i++) {
					if(j==1)p->schermo[j][i]='=' ;
					if(j!=1)p->schermo[j][i]=' ' ;
				}
			}
	int num_piatt = num_random(x/5)+2 ;                       // num_piatt= 2 o 3 (con x minimo 12 e y minimo 40)
		int h_prec=1 ;
		int o_prec=1 ;
		int l_prec ;
		for(int i=1; i<=num_piatt; i++) {                     // genera n piattaforme
			if(h_prec<x-3) {
			int altezza=3+h_prec ;                            // altezza minima=3
			int origine=num_random(y/5)+2;                    // origine minima=1
			int lunghezza=num_random(y/8)+6;
			while ((origine>=o_prec-2 && origine<=o_prec+l_prec+2) || origine + lunghezza > y-3 || (origine+lunghezza>=o_prec-2 && origine+lunghezza<=o_prec+l_prec+2))
				  {
				  origine=num_random(y/2)+y/2 ;               // cambia origine se necessario
				  }

			genera_piattaforma(p->schermo, altezza, origine, lunghezza) ;
			l_prec=lunghezza ;
			h_prec=altezza ;
			o_prec=origine ;
			}
		}
	return *p ;
}

void Mappa::genera_piattaforma(char output[][y], int h, int o, int l) {
	int altezza=h ;
	int origine=o ;
	int lunghezza=l ;
	output[altezza][origine]='('; //inizio
	for(int j=origine+1; j<origine+lunghezza; j++) {
		output[altezza][j]='='; //centro
	  	  }
	  	  output[altezza][origine+lunghezza]=')'; //fine
	}

int Mappa::num_random(int max) {
	srand( time(0) ) ;
	int n = (rand() % max) ;
	return n ;
}

// ╔ ═ ╗ ¤ ♥
