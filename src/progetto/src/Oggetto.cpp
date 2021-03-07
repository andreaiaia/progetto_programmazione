/*
 * oggetti.cpp
 *
 *  Qui ci sono le classi del protagonista, dei nemici
 *  e degli oggetti bonus del gioco
 */
#include"Oggetto.h"

Oggetto::Oggetto(char r, char t) {
	rappresentazione = r;
	tipo = t;
}

char Oggetto::ritorna_aspetto() {
	return rappresentazione;
}

char Oggetto::ritorna_tipo() {
	return tipo;
}
