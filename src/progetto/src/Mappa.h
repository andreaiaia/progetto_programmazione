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

class Mappa {
protected:
	char schermo[x][y] ;

public:
	Mappa();

	void piattaforme();
	int num_random(int) ;
	void genera_piattaforma(int, int, int) ;
	char contenuto(int, int);
};
