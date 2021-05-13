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
#include "funzioni.h"


#define x 10
#define y 10

class Mappa {
protected:
	char schermo[x][y] ;

public:
	Mappa();

	void piattaforme();
	void genera_piattaforma(int, int, int) ;
	void aggiungi_elemento(int [], char);
	char contenuto(int, int);
};
