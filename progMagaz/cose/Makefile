prova4: prova4.o Mappa.o Personaggio.o Funzioni.o -lgdi32
	g++ -o prova4 prova4.o Mappa.o Personaggio.o Funzioni.o -lgdi32

prova4.o: prova4.cpp 
	g++ -c prova4.cpp

Mappa.o: Mappa.cpp Mappa.h
	g++ -c Mappa.cpp

Personaggio.o: Personaggio.cpp Personaggio.h
	g++ -c Personaggio.cpp

Funzioni.o: Funzioni.cpp Funzioni.h
	g++ -c Funzioni.cpp
//g++ Mappa.h Mappa.cpp Funzioni.h Funzioni.cpp prova4.cpp -o prova4.exe -lgdi32