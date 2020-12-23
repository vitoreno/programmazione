/*
Programma per la scrittura di un file immagine .pgm binario

Questo programma si propone di dimostrare come sia possibile scrivere un'immagine utilizzando un file binario (raw).
L'immagine viene scritta in formato .pgm, maggiori dettagli al sito: https://en.wikipedia.org/wiki/Netpbm
*/

#define _CRT_SECURE_NO_WARNINGS /* Per utilizzo di fopen etc... senza obbligo di usare le versioni _s */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp; /* Dichiarazione del puntatore a FILE */
	unsigned char image[50][50] = { 0 }; /* L'immagine e' rappresentata da un array bidimensionale */
	const unsigned char MAXVAL = 255; /* Valore massimo rappresentante il colore bianco */
	int i, j; /* Contatori */
	char Buf[512]; /* Buffer */

	/* Assegno dei numeri casuali a ogni pixel dell'immagine */
	for (i = 0; i < 50; i++)
		for (j = 0; j < 50; j++)
			image[i][j] = rand() % MAXVAL;

	/* Apro il file in scrittura */
	fp = fopen("SaltPepperBin.pgm", "wb");

	/* Scrivo l'header del formato .pgm */
	strcpy(Buf, "P5 50 50 255\n"); /* Copio l'header all'interno di Buf */
	
	/* Scrivo nel file puntato da fp
		una quantita' di byte pari a: 
		Dimensione di un char [sizeof(char)] moltiplicato per la lunghezza effettiva di Buf [strlen(Buf)] 
		leggendo questi byte a partire dall'indirizzo del primo elemento di Buf [Buf]
		*/
	fwrite(Buf, sizeof(char), strlen(Buf), fp);

	/* Scrivo il payload */
	fwrite(image, sizeof(unsigned char), 50 * 50, fp);

	/* Chiusura del file */
	fclose(fp);

	return 0;
}