/*
 * Cuore.h
 *
 *  Created on: 7 mar 2021
 *      Author: Andrea
 */
#include "Oggetto.h"

#include <iostream>
using namespace std;


class Cuore:public Oggetto {
protected:
	int vita;
public:
	Cuore(int v, char r, char t) ;

	int punti_vita () ;
};
