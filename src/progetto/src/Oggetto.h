/*
 * oggetti.h
 *
 *  Created on: 26 feb 2021
 *      Author: Andrea
 */
#include <iostream>


class Oggetto {		// La classe oggetto genera direttamente gli Scudi, mentre la classe figlia cuore genera i cuori
protected:
	int vita;
	int posizione[2];
	char tipo;
	char rappresentazione;

public:
	Oggetto(int, int [], char, char) ;

	char ritorna_aspetto() ;
	char ritorna_tipo() ;

	void ritorna_posizione(int []);

	int ritorna_vita();

	void mod_vita(int);
	void mod_aspetto(char);
	void mod_tipo(char);
	void mod_posizione(int []);
};
