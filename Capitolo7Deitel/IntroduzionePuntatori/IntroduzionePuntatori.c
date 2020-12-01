/* Programma per visualizzare gli indirizzi di memoria di variabili e array */
#include <stdio.h>

int main()
{
	/* Dichiarazione di variabili char: occupano 1 byte, l'indirizzo invece e' di 8 byte */
	char carattere;
	char secondoCarattere;

	/* Dichiarazione di variabile intera: occupa 4 byte, l'indirizzo invece e' di 8 byte */
	int variabile;

	/* Dichiaro una variabile puntatore a intero. Occupa 8 byte */
	int* pVar;

	/* Dichiaro array di interi, double e char, mono o multi dimensionali */
	int vettore[5] = { 1, 2, 3, 4, 5 };
	double vD[3] = { 0 };
	char vC[5] = { 0 };

	int matrice[3][3] = { 0 };

	variabile = 5;
	pVar = &variabile;

	/* Inserisci il commento */
	printf("L'indirizzo di carattere e':\t%p\n", &carattere);
	printf("L'indirizzo di secondoCarattere e':\t%p\n", &secondoCarattere);

	printf("\n");

	/* Inserisci il commento */
	printf("L'indirizzo di vC:\t%p\n", vC);
	for (int i = 0; i < 5; i++)
		printf("L'indirizzo di vC[%d] e':\t\t%p\n", i, &vC[i]);

	printf("\n");

	/* Inserisci il commento */
	printf("L'indirizzo di variabile e':\t%p\n", &variabile);
	printf("Il valore di pVar e':\t\t%p\n", pVar);

	printf("\n");
	
	/* Inserisci il commento */
	printf("L'indirizzo di vettore e':\t%p\n", vettore);
	for (int i = 0; i < 5; i++)
		printf("L'indirizzo di vettore[%d] e':\t%p\n", i, &vettore[i]);

	printf("\n");
	
	/* Inserisci il commento */
	printf("L'indirizzo di vD e':\t\t%p\n", vD);
	for (int i = 0; i < 3; i++)
		printf("L'indirizzo di vD[%d] e':\t%p\n", i, &vD[i]);

	printf("\n");

	/* Inserisci il commento */
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			printf("L'indirizzo di matrice[%d][%d] e':\t%p\n", i, j, &matrice[i][j]);

	return 0;
}