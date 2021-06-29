#include "Funzioni.h"

int num_random(int max){
	srand( time(0) );
	int n = (rand() % max);
	return n;
}

int numerocifre(int intero){
	if (intero==0) return 1;
	else {
		int n=0;
		while(intero>0){
    		intero=intero/10;
    		n=n+1;
		}
		return n;
	}
}

LPCSTR INTTOLPCSTR(int intero){
	int ncifre = numerocifre(intero);         //numero delle cifre della stringa
	char stringa[ncifre];
	int resto;
	int c = ncifre-1;
	int i=0;
	while (i<ncifre){
		stringa[i]='0';
		i=i+1;
	}
	stringa[ncifre]='\0';
	while (intero>0){
		resto=intero%10;
		intero=intero/10;
		switch (resto){
		case 0:
			stringa[c]='0';
			break;
		case 1:
			stringa[c]='1';
			break;
		case 2:
			stringa[c]='2';
			break;
		case 3:
			stringa[c]='3';
			break;
		case 4:
			stringa[c]='4';
			break;
		case 5:
			stringa[c]='5';
			break;
		case 6:
			stringa[c]='6';
			break;
		case 7:
			stringa[c]='7';
			break;
		case 8:
			stringa[c]='8';
			break;
		case 9:
			stringa[c]='9';
			break;
		default:
			break;
		}
		c=c-1;
	}
	LPCSTR ciaooo = stringa;
	return ciaooo;
}