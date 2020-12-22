/*
Programma per la scrittura di un file immagine .pgm ascii

Questo programma si propone di dimostrare come sia possibile scrivere un'immagine utilizzando un file di testo (ASCII).
L'immagine viene scritta in formato .pgm, maggiori dettagli al sito: https://en.wikipedia.org/wiki/Netpbm
*/

#define _CRT_SECURE_NO_WARNINGS /* Per utilizzo di fopen etc... senza obbligo di usare le versioni _s */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp; /* Dichiarazione del puntatore a FILE */
	unsigned char image[50][50] = { 0 }; /* L'immagine e' rappresentata da un array bidimensionale */
	const unsigned char MAXVAL = 255; /* Valore massimo rappresentante il colore bianco */
	int i, j; /* Contatori */

	/* Assegno dei numeri casuali a ogni pixel dell'immagine */
	for (i = 0; i < 50; i++)
		for (j = 0; j < 50; j++)
			image[i][j] = rand() % MAXVAL;

	/* Apro il file in scrittura */
	fp = fopen("SaltPepper.pgm", "w");

	/* Scrivo l'header del formato .pgm */
	fprintf(fp, "P2\n"); /* P2 indica che sto riportando un'immagine in scala di grigi in un file di testo (ASCII)*/
	fprintf(fp, "# Esempio di file pgm contenente rumore sale e pepe\n"); /* Commento anche nel file .pgm */
	fprintf(fp, "50 50\n"); /* Dimensioni dell'immagine */
	fprintf(fp, "255\n"); /* Massimo valore numerico */

	/* Scrittura del payload, ovvero dell'immagine */
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
			fprintf(fp, "%-4d", image[i][j]);
		fprintf(fp, "\n");
	}

	/* Chiusura del file */
	fclose(fp);

	return 0;
}