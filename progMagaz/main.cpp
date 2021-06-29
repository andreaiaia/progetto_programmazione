#include <iostream>
#include <windows.h>
#include "Mappa.h"
#include "Oggetto.h"
#include "Personaggio.h"
#include "funzioni.h"
using namespace std;

struct lista_nemici {
	Personaggio nemico = Personaggio(6, 2, 0, 2, 'N', false);
	lista_nemici * next;
	lista_nemici * prev;
};

struct lista_scudi {
	Oggetto scudo = Oggetto(0, 2, 0, 'S', true);
	lista_scudi * next;
	lista_scudi * prev;
};

struct lista_cuori {
	Oggetto cuore = Oggetto(3, 2, 0, 'C', false);
	lista_cuori * next;
	lista_cuori * prev;
};

struct lista_mappe {
	Mappa schermata;
	lista_nemici * head_nemici;
	lista_scudi * head_scudi;
	lista_cuori * head_cuori;
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
	head->head_scudi->next = NULL;
	head->head_scudi->prev = NULL;
	head->head_cuori->next = NULL;
    head->head_cuori->prev = NULL;

	// TODO: Visualizzare la mappa iniziale a schermo

	Personaggio protagonista = Personaggio(10, 1, 0, 2, 'P', false);  // Creato il personaggio giocante

	while(protagonista.ritorna_vita>0){                // START - loop del game
	// TODO: Visualizzare a schermo il protagonista
	/* 
		while gioco in esecuzione:
			visualizza personaggio nella sua posizione
			Genera nemici ed oggetti
			aspetta input dall'utente / gestisci i nemici
			se andato a limite schermo, porta in nuova schermata
	*/

	// Genera i nemici:
	lista_nemici * pNemici = head->head_nemici;
	for (int diff=difficolta; diff > 0; diff--) {
		int output[2];
		popola(head, difficolta, output); // serve schermo per testare
		(pNemici->nemico).nuova_posizione(output[0], output[1]);
		if (diff>1) {
			pNemici->next = new lista_nemici;
			pNemici->next->prev = pNemici;
			pNemici = pNemici->next;
		}
		pNemici->next = NULL;
	}

	// Aggiunta/aggiornamento delle posizioni dei nemici nella mappa
	aggiorna_mappa(head);


	//genera scudi
	lista_scudi *pScudi = head->head_scudi;
	for (int diff = num_random(3); diff > 0; diff--)  // da rivedere la quantit�
	{
		int output[2];
		popola(head, diff, output); // serve schermo per testare
		(pScudi->scudo).mod_posizione(output[0], output[1]);
		if (diff > 1)
		{
			pScudi->next = new lista_scudi;
			pScudi->next->prev = pScudi;
			pScudi = pScudi->next;
		}
		pScudi->next = NULL;
	}

	// Aggiunta/aggiornamento delle posizioni degli scudi nella mappa
	aggiorna_mappa(head);

	//genera cuori
		lista_cuori *pCuori = head->head_cuori;
		for (int diff = num_random(3); diff > 0; diff--)  // da rivedere la quantit�
		{
			int output[2];
			popola(head, diff, output); // serve schermo per testare
			(pCuori->cuore).mod_posizione(output[0], output[1]);
			if (diff > 1)
			{
				pCuori->next = new lista_cuori;
				pCuori->next->prev = pCuori;
				pCuori = pCuori->next;
			}
			pCuori->next = NULL;
		}

		// Aggiunta/aggiornamento delle posizioni dei cuori nella mappa
		aggiorna_mappa(head);



	// TODO Input dell'utente e movimento dei personaggi non giocanti (i nemici insomma)



	// quando protagonista arriva a bordo schermo, passa a nuova schermata

	if (protagonista.bordo_schermo==1 && head->next == NULL)
	{
		head->next = new lista_mappe;
		head->next->prev = head;
		head = head->next;
		head->next = NULL;
		protagonista.nuova_posizione(1, 0);
		difficolta = difficolta+1;
	}
	else if (protagonista.bordo_schermo==-1 && head->prev != NULL)	{
		head = head->prev;
		protagonista.nuova_posizione(1, y);
	} else if (protagonista.bordo_schermo==1){
		head = head->next;
		protagonista.nuova_posizione(1, 0);
	}

	}                                                                    // END - loop del game

	return 0;
	}

void popola(lista_mappe * p, int d, int output[]) {        // perch� abbiamo messo come argomento p?
	int offset = 0;
	if (d < 5) offset = 5-d;

	int altezza = num_random(x) + offset;
	int ordinata = num_random(y);
	while ((Mappa::contenuto(altezza-1, ordinata) != '=') ||  // la funzione contenuto ritorna un char
					(ordinata == 0 || ordinata == 1) || 
					(contenuto(altezza, ordinata) != ' ')) {
	    altezza = num_random(x) + offset;
	    ordinata = num_random(y);
	}
	output[0] = altezza;
	output[1] = ordinata;
}

void aggiorna_mappa(lista_mappe * head) {              // forse meglio separare nemici da oggetti
	lista_nemici * pNemici = head->head_nemici;
	while (pNemici->next != NULL) {
		int px = (pNemici->nemico).ritorna_x();
		int py = (pNemici->nemico).ritorna_y();
		char r = (pNemici->nemico).ritorna_aspetto();
		(head->schermata).aggiungi_elemento(py, px, r);
		pNemici = pNemici->next;
	}

	lista_scudi *pScudi = head->head_scudi;
	while (pScudi->next != NULL)
	{
		int px = (pScudi->scudo).ritorna_x();
		int py = (pScudi->scudo).ritorna_y();
		char r = (pScudi->scudo).ritorna_aspetto();
		(head->schermata).aggiungi_elemento(px, py, r);
		pScudi = pScudi->next;
	}

	lista_cuori *pCuori = head->head_cuori;
	while (pCuori->next != NULL)
	{
		int px = (pCuori->cuore).ritorna_x();
		int py = (pCuori->cuore).ritorna_y();
		char r = (pCuori->cuore).ritorna_aspetto();
		(head->schermata).aggiungi_elemento(px, py, r);
		pCuori = pCuori->next;
	}
}
