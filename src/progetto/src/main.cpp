//============================================================================
// Name        : progetto.cpp
// Author      : Bianchi Andrea, Giannone Simone, Leccabue Matteo, Svelti Elena
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "keyboard.h"
#include "schermo.h"
using namespace std;

//void popola(char, int);

int main() {
	cout << "Hello World!" << endl; // prints Hello World!
	return 0;

}


/*void popola(char figura, int d) {
	int offset = 0;
	if (d < 5) offset = 5-d;

	int altezza = num_random(x) + offset;
	int ordinata = num_random(y);

	while ((schermo[altezza-1][ordinata] != '=') || (ordinata == 0 || ordinata == 1) || (schermo[altezza][ordinata] != '*')) {
	    altezza = num_random(x) + offset;
	    ordinata = num_random(y);
	}
	schermo[altezza][ordinata] = figura;
}*/
