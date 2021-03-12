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
	int num_piatt = num_random(2)+1 ;
	for(int i=0; i<num_piatt; i++) {
		int altezza=num_random(3)+i ;
		if(altezza>=9) altezza=8 ;
		int origine=num_random(6)+1 ;
		int lunghezza=num_random(3)+2 ;
		p->schermo[origine][altezza]='╔' ;
		for(int j=origine+1; j<lunghezza-1; j++) {
			p->schermo[j][altezza]='═' ;
		}
		p->schermo[origine][altezza]='╗' ;
	}














	/*
	srand( time(0) ) ;
	char colonna[10] = "        " ; // 9 spazi

	if (nuova_piattaforma > 0) {
		if (nuova_piattaforma > 1) {
			// TODO: inserire generatore di nemici/oggetti su piattaforma

			colonna[altitudine] = '═';
		} else {
			colonna[altitudine] = '╗';
		}
	} else {
		int ostacolo = rand() % difficolta ; // genera un numero fra 0 e 4. 0,1,2,3 = non fa niente - 4,5,6 = genera piattaforma - 7 = genera oggetto, >8 genera nemico

		if (ostacolo >= 4 && ostacolo <= 6) {
			altitudine = (rand() % 2) + 2;
			nuova_piattaforma = (rand() % 4) + 2 ;

			colonna[altitudine] = '╔';

		} else if (ostacolo == 7) {
			int tipo_ogg = rand() % 2;

			if (tipo_ogg == 0) {

				// CUORE

			} else {
				// SCUDO
			}

		}


	}

	strcpy(output, colonna);
	*/
	return head ;
}

int Mappa::num_random(int max) {
	srand( time(0) ) ;
	int n = (rand() % max+1) ;
	return n ;
}

// ╔ ═ ╗ ¤ ♥
