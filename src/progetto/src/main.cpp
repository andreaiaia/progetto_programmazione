//============================================================================
// Name        : progetto.cpp
// Author      : Bianchi Andrea, Giannone Simone, Leccabue Matteo, Svelti Elena
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
#include <windows.h>
//#include "keyboard.h"
//#include "schermo.h"
#include "Mappa.h"
#include "Oggetto.h"
#include "Personaggio.h"
#include "funzioni.h"
using namespace std;

struct lista_nemici {
	Personaggio nemico(6, [2, 0], 2, "N", false); 
	lista_nemici * next;
	lista_nemici * prev;
};

struct lista_oggetti {
	Oggetto oggetto();
	lista_oggetti * next;
	lista_oggetti * prev;
};

struct lista_mappe {
	Mappa schermata();
	lista_nemici * head_nemici;
	lista_oggetti * head_oggetti;
	lista_mappe * next;
	lista_mappe * prev;
};

void popola(lista_mappe *, int, int []);
void aggiorna_mappa(lista_mappe *);

int main() {

	int difficolta = 6;

	lista_mappe * head = new lista_mappe;
	head->prev = NULL;
	head->next = NULL;
	head->head_nemici->next = NULL;
	head->head_nemici->prev = NULL;
	head->head_oggetti->next = NULL;
	head->head_oggetti->prev = NULL;

	// TODO: Visualizzare la mappa iniziale a schermo

	Personaggio protagonista(10, [1,0], 2, 'P', false);  // Creato il personaggio giocante

	// START - loop del game (while ancora da inserire)
	// TODO: Visualizzare a schermo il protagonista
	/* 
		while gioco in esecuzione:
			visualizza personaggio nella sua posizione
			Genera nemici ed oggetti
			aspetta input dall'utente / gestisci i nemici
			se andato a limite schermo, porta in nuova schermata
	*/

	// Genera i nemici
	lista_nemici * pNemici = head->head_nemici;
	for (int diff=difficolta; diff > 0; diff--) {
		int output[2];
		popola(head, difficolta, output); // serve schermo per testare
		(pNemici->nemico)::nuova_posizione(output[0], output[1]);
		if (diff>1) {
			pNemici->next = new lista_nemici;
			pNemici->next->prev = pNemici;
			pNemici = pNemici->next;
		}
		pNemici->next = NULL;
	}

	// Aggiunta/aggiornamento delle posizioni dei nemici nella mappa
	aggiorna_mappa(head);

	lista_oggetti *pOggetti = head->head_oggetti;
	for (int diff = num_random(3); diff > 0; diff--)
	{
		int output[2];
		popola(head, diff, output); // serve schermo per testare
		(pOggetti->oggetto)::mod_posizione(output[0], output[1]);
		if (diff > 1)
		{
			pOggetti->next = new lista_oggetti;
			pOggetti->next->prev = pOggetti;
			pOggetti = pOggetti->next;
		}
		pOggetti->next = NULL;
	}

	// Aggiunta/aggiornamento delle posizioni dei nemici nella mappa
	aggiorna_mappa(head);

	// TODO Input dell'utente e movimento dei personaggi non giocanti (i nemici insomma)

	// quando protagonista arriva a bordo schermo, passa a nuova schermata

	if (/*come cacchio si vede che è a bordo schermo destro*/ && head->next == NULL)
	{
		head->next = new lista_mappe;
		head->next->prev = head;
		head = head->next;
		head->next = NULL;
		protagonista::nuova_posizione(1, 0);
	}
	else if (/* bordo schermo sinistro */ && head->prev != NULL)	{
		head = head->prev;
		protagonista::nuova_posizione(1, y);
	} else if (/* se si trova a destra e va a destra della destra*/){
		head = head->next;
		protagonista::nuova_posizione(1, 0);
	}

	// END - loop del game 

	return 0;
	}

void popola(lista_mappe * p, int d, int output[]) {
	int offset = 0;
	if (d < 5) offset = 5-d;

	int altezza = num_random(x) + offset;
	int ordinata = num_random(y);

	while ((Mappa::contenuto(altezza-1, ordinata) != '=') || 
					(ordinata == 0 || ordinata == 1) || 
					(contenuto(altezza, ordinata) != ' ')) {
	    altezza = num_random(x) + offset;
	    ordinata = num_random(y);
	}
	output[0] = altezza;
	output[1] = ordinata;
}

void aggiorna_mappa(lista_mappe * head) {
	lista_nemici * pNemici = head->head_nemici;
	while (pNemici->next != NULL) {
		int pos[2];
		(pNemici->nemico)::ritorna_posizione(pos);
		char r = (pNemici->nemico)::ritorna_aspetto;
		(head->schermata)::aggiungi_elemento(pos, r);
		pNemici = pNemici->next;
	}

	lista_oggetti *pOggetti = head->head_oggetti;
	while (pOggetti->next != NULL)
	{
		int pos[2];
		(pOggetti->oggetto)::ritorna_posizione(pos);
		char r = (pOggetti->oggetto)::ritorna_aspetto;
		(head->schermata)::aggiungi_elemento(pos, r);
		pOggetti = pOggetti->next;
	}
}