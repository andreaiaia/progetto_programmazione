/*
 * oggetti.cpp
 *
 *  Qui ci sono le classi del protagonista, dei nemici
 *  e degli oggetti bonus del gioco
 */
#include"Oggetto.h"

Oggetto::Oggetto(int v = 0, int pos[] = [2, 0], char r = '0', char t = '0') {
	vita = v;
	posizione[0] = pos[0];
	posizione[1] = pos[1];
	rappresentazione = r;
	tipo = t;
}

char Oggetto::ritorna_aspetto() {
	return rappresentazione;
}

char Oggetto::ritorna_tipo() {
	return tipo;
}

void Oggetto::ritorna_posizione(int output[])
{
	output[0] = posizione[0];
	output[1] = posizione[1];
}

int Oggetto::ritorna_vita()
{
	return vita;
}

void Oggetto::mod_vita(int v)
{
	vita = v;
}

void Oggetto::mod_aspetto(char r)
{
	rappresentazione = r;
}

void Oggetto::mod_tipo(char t)
{
	tipo = t;
}

void Oggetto::mod_posizione(int pos[]) {
	posizione[0] = pos[0];
	posizione[1] = pos[1];
}