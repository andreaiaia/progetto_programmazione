#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Funzioni.h"


#define x 13
#define y 40

class Mappa {
protected:

	char schermo[x][y];

public:

	Mappa();

	void piattaforme();
	
	void genera_piattaforma(int, int, int);

	void aggiungi_elemento(int, int, char);

	char contenuto(int, int);

	void disegnamappa();
};