#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Funzioni.h"
#include <Windows.h>

#define x 11
#define y 28

class Mappa {
protected:

	LPCSTR schermo[x][y];
	int difficolta;

public:

	Mappa();

	void piattaforme();
	
	void genera_piattaforma(int, int, int);

	void aggiungi_elemento(int, int, LPCSTR);

	LPCSTR contenuto(int, int);

	void disegnamappa(HDC);
};