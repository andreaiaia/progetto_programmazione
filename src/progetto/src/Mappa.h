/*
 * mappa.h
 *
 *  Created on: 6 mar 2021
 *      Author: Simone
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Oggetto.h"
#include "Cuore.h"

using namespace std ;

#define x 10
#define y 10

struct scena {
	char schermo[x][y] ;
	scena * prev ;
	scena * next ;
};

class Mappa {
protected:
	scena * head ;

	int difficolta = 6;
/*
	// Variabili per tenere traccia della map generation
	int nuova_piattaforma = 4;
	int altitudine = 0;
*/

public:
	Mappa();

	scena* nuovo_schermo(scena* head);
	int num_random(int max) ;
	void genera_piattaforma(char output[x][y], int altezza, int o) ;

/*
 * facciamo una bilista al cui interno memorizziamo tutte le "colonne" che compongono la mappa,
 * implementiamo metodi per randomizzare un numero 0 o 1 per decidere se fare iniziare una piattaforma o no
 * uno per decidere quanti oggetti fare apparire e uno per decidere la lunghezza delle piattaforme
 * si deve anche decidere se tenere in considerazione l'altezza di queste piattaforme rispetto al personaggio
 * e decidere se impedire al personaggio di raggiungere piattaforme troppo alte
 * in caso potremmo anche fare apparire piattaforme in base all'altezza delle precedenti, mettendole
 * sempre più a salire.
 */


};
