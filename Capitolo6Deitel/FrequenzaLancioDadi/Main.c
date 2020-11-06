/*
	Lanciare un dado a sei facce per 6000 volte
	e verificare la frequenza dei sei numeri estraibili

	Variabili necessarie:
		faccia -> int
		contatoreLanci -> int
		estrazioni -> array di int di almeno 6 posizioni

	Necessito di un generatore di numeri pseudocasuali
	Il vettore estrazioni va inizializzato a zero

	Per contatoreLanci che va da 1 a 6000
		Effettuo un lancio
		Accumulo il risultato nel vettore estrazioni

	Per faccia che va da 1 a 6
		Stampo il valore corrispondente alla frequenza delal faccia
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int faccia; /* variabile per l'estrazione del singolo lancio */
	int contatoreLanci;
	int estrazioni[7]; /* Array per accumulare le frequenze */
	int i;

	srand(time(NULL));
	
	for (i = 0; i < 7; i++)
		estrazioni[i] = 0;

	for (contatoreLanci = 1; contatoreLanci <= 6000; contatoreLanci++)
	{
		faccia = rand() % 6 + 1;
		estrazioni[faccia]++;
	}

	for (i = 1; i <= 6; i++)
		printf("Faccia %d:%d estrazioni\n", i, estrazioni[i]);

	return 0;
}