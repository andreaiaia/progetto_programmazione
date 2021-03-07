/*
 * oggetti.h
 *
 *  Created on: 26 feb 2021
 *      Author: Andrea
 */
#include <iostream>
using namespace std;

class Oggetto {		// La classe oggetto genera direttamente gli Scudi, mentre la classe figlia cuore genera i cuori
protected:
	char tipo;
	char rappresentazione;

public:
	Oggetto(char r, char t) ;

	char ritorna_aspetto() ;

	char ritorna_tipo() ;
};
