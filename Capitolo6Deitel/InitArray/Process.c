/*
	Inizializzazione di un array in molteplici modi
*/

#include <stdio.h>

int main()
{
	int numeri[10]; /* Dichiaro un vettore di 10 numeri interi */
	int idx; /* contatore, indice per scorrere l'array */
	int altriNumeri[] = { 1, 2, 3, 0, 9, 8, 4, 8, 1, 199 }; /* Osservare l'inizializzazione */

	/* Assegno valore 100 a ogni elemento del vettore numeri */
	for (idx = 0; idx < 10; idx++)
	{
		numeri[idx] = 100;
	}
	
	/* Il valore in posizione 4 del vettore numeri assume valore 2000 */
	numeri[4] = 2000;

	/* Stampo ogni elemento del vettore numeri e del vettore altriNumeri */
	for (idx = 0; idx < 10; idx++)
		printf("Valore in posizione %d di numeri: %d e di altriNumeri: %d\n", idx, numeri[idx], altriNumeri[idx]);

	return 0;
}