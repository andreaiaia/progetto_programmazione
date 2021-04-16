/*
 * funzioni.cpp
 *
 *  Created on: 16 apr 2021
 *      Author: Simone
 */

#include "funzioni.h"

int num_random(int max) {
	srand( time(0) ) ;
	int n = (rand() % max) ;
	return n ;
}
