/*
	*** OBIETTIVO ***

	Programma per la stampa di un messaggio diverso in base al voto conseguito ad un esame.

	Pseudocodice e spiegazione dell'approccio TOP DOWN

	*** FASI GENERICHE DI OGNI PROGRAMMA C ***

	1) Dichiarazione delle variabili
	2) Inizializzazione
	3) Processing
	4) Restituzione dei risultati

	*** PRIMA STESURA PSEUDOCODICE ***

	Leggi la valutazione

	se la valutazione è maggiore di 30
		stampa Lode
	se la valutazione è maggiore di 27
		stampa Ottimo
	se la valutazione è maggiore di 18
		stampa Promosso
	se la valutazione è inferiore a 18
		stampa Ritenta sarai più fortunato

	*** SECONDA STESURA PSEUDOCODICE ***

	Dichiara una variabile voto
	Chiedi all'utente di inserire il voto

	se la valutazione è maggiore di 30
		stampa Lode
	se la valutazione è maggiore o uguale di 27
		stampa Ottimo
	se la valutazione è maggiore o uguale a 18
		stampa Promosso
	se la valutazione è inferiore a 18
		stampa Ritenta sarai più fortunato
*/

#include <stdio.h>

int main() /* START */
{
	int voto;
	
	printf("Inserisci il voto: ");
	scanf_s("%d", &voto);

	if (voto > 30)
		printf("Trenta e Lode!\n");
	else if(voto >= 27)
		printf("Ottima valutazione!\n");
	else if (voto >= 18)
		printf("Complimenti hai superato l'esame!\n");
	else if (voto < 18)
		printf("Ritenta\n");
	
	return 0; /* STOP */
}