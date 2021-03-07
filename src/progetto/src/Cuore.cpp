/*
 * Cuore.cpp
 *
 *  Created on: 7 mar 2021
 *      Author: Andrea
 */

#include "Cuore.h"

Cuore::Cuore(int v, char r, char t):Oggetto(r, t) {
	vita = v;
}

int Cuore::punti_vita () {
	return vita;
}
