/*
 * mappa.cpp
 *
 *  Created on: 6 mar 2021
 *      Author: Simone
 */

#include "Mappa.h"

Mappa::Mappa() {
	head = new scena ;
	char col[10] = "        "; // 9 spazi bianchi
	strcpy(head->colonna, col) ;
	head->prev = NULL ;
	scena * p = head ;
	int lunghezza_schermo = 3 ;
	for (int i = 0; i < lunghezza_schermo; i++) {
		p->next = new scena ;
		(p->next)->prev = p ;
		p = p->next ;
		char nuova_col[10] ;
		nuova_colonna(nuova_col) ;
		strcpy(head->colonna, col) ;
		p->next = NULL;
	}
}

void Mappa::nuova_colonna(char output[]) {
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
}

// ═╗ ¤ ♥
