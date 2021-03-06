/*
 * mappa.h
 *
 *  Created on: 6 mar 2021
 *      Author: Simone
 */

#include <iostream>
using namespace std ;

struct scena {
		char colonna[10] ;
		scena*prev ;
		scena*next ;
	};
