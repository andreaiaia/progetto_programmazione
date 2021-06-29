#include "Mappa.h"

int difficolta=0;

Mappa::Mappa() {
	//difficolta=difficolta+1;
	for(int j=0; j<x; j++) {
		for(int i=0; i<y; i++) {
			if(j==1)schermo[j][i]="=" ;
			if(j!=1)schermo[j][i]=" " ;
		}
	}
	piattaforme();
}

void Mappa::piattaforme() {
	int num_piatt = num_random(x/5)+2 ;                       // num_piatt= 2 o 3 (con x minimo 12 e y minimo 40)
	int h_prec=0 ;
	int o_prec=1 ;
	int l_prec ;
	for(int i=1; i<=num_piatt; i++){
	    if(h_prec<x-3){
			int altezza = h_prec + num_random(2)+3;
			while (altezza >= x-2) {
				altezza = h_prec + num_random(3)+2;
			}
			int origine=num_random(y)+2;
			int lunghezza=num_random(y/8)+6;

			while ( origine + lunghezza > y-3 ){
		        origine=num_random(y/2)+y/2 ;
		    }

			genera_piattaforma(altezza, origine, lunghezza);
	    	l_prec=lunghezza;
			h_prec=altezza ;
			o_prec=origine ;
	    }
	}
}

void Mappa::genera_piattaforma(int h, int o, int l) {
	int altezza=h ;
	int origine=o ;
	int lunghezza=l ;
	schermo[altezza][origine] = "("; //inizio
	for(int j=origine+1; j<origine+lunghezza; j++) {
		schermo[altezza][j] = "="; //centro
	}
	schermo[altezza][origine+lunghezza]=")"; //fine
}

void Mappa::aggiungi_elemento(int posY, int posX, LPCSTR r) {
	schermo[posY][posX] = r;
}

LPCSTR Mappa::contenuto(int a, int b) {
	if (a > x) a = x;
	else if (a < 0) a = 1;
	if (b > y) b = y;
	else if (b < 0) b = 0;

	return schermo[a][b];
}

void Mappa::disegnamappa(HDC hdc){
	int colonna=26;
	int riga=64;
	for (int q = x-1; q > 0; q--) {
    	for (int p = 0; p < y; p++) {
			TextOutA(hdc, colonna, riga, schermo[q][p], 1);
			colonna=colonna+26;
    	}
		colonna=26;
    	riga=riga+47; //cambio riga
	}
	TextOutA(hdc, 150, 150, INTTOLPCSTR(difficolta), 1);
}