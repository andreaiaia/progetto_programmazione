/*
 * mappa.cpp
 *
 *  Created on: 6 mar 2021
 *      Author: Simone
 */

#include "Mappa.h"

Mappa::Mappa() {
	for(int j=0; j<x; j++) {
		for(int i=0; i<y; i++) {
			if(j==1) schermo[j][i]='=' ;
			if(j!=1) schermo[j][i]=' ' ;
		}
	}
	piattaforme();
}

void Mappa::piattaforme() {
	int num_piatt = num_random(x/5)+2 ;                       // num_piatt= 2 o 3 (con x minimo 12 e y minimo 40)
	int h_prec=1 ;
	int o_prec=1 ;
	int l_prec ;
	for(int i=1; i<=num_piatt; i++) {                     // genera n piattaforme
		if(h_prec<x-3) {
			int altezza=3+h_prec ;                            // altezza minima=3
			int origine=num_random(y/5)+2;                    // origine minima=1
			int lunghezza=num_random(y/8)+6;
			while ((origine>=o_prec-2 && origine<=o_prec+l_prec+2) || origine + lunghezza > y-3
					|| (origine+lunghezza>=o_prec-2 && origine+lunghezza<=o_prec+l_prec+2)) {
				 origine=num_random(y/2)+y/2 ;               // cambia origine se necessario
			}
			genera_piattaforma(altezza, origine, lunghezza) ;
			l_prec=lunghezza ;
			h_prec=altezza ;
			o_prec=origine ;
		}
	}
}

void Mappa::genera_piattaforma(int h, int o, int l) {
	int altezza=h ;
	int origine=o ;
	int lunghezza=l ;
	schermo[altezza][origine] = '('; //inizio
	for(int j=origine+1; j<origine+lunghezza; j++) {
		schermo[altezza][j] = '='; //centro
	}
	schermo[altezza][origine+lunghezza]=')'; //fine
}

/*void Mappa::popola(char figura, int d) {
	int offset = 0;
	if (d < 5) offset = 5-d;

	int altezza = num_random(x) + offset;
	int ordinata = num_random(y);

	while ((schermo[altezza-1][ordinata] != '=') || (ordinata == 0 || ordinata == 1) || (schermo[altezza][ordinata] != '*')) {
	    altezza = num_random(x) + offset;
	    ordinata = num_random(y);
	}
	schermo[altezza][ordinata] = figura;

	// Va creata una variabile di tipo nemico/oggetto nella quale salvare le coordinate del suddetto nemico/oggetto
}*/

char Mappa::contenuto(int a, int b) {
	if (a > x) a = x;
	else if (a < 0) a = 1;
	if (b > y) b = y;
	else if (b < 0) b = 0;

	return schermo[a][b];
}
