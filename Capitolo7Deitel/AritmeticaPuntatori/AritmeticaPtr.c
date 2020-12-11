/*
	Variazione sul tema rispetto all'esercizio 7.20
	Dimostrazione dell'utilizzo della aritmetica dei puntatori
*/

#include <stdio.h>

int main()
{
	int vett[10] = { -1, 7, 4, 0, 9, 5, 0, 10, 42, 0 }; /* Dichiaro un vettore */
	int* pV1; /* Dichiaro alcuni puntatori */
	int* pV2;

	pV1 = &vett[1];
	pV2 = vett + 1;

	printf("Indirizzo pV1 %p\nIndirizzo pV2 %p\n", pV1, pV2);

	/* Stampa di alcuni valori intermedi del vettore utilizzando la notazione puntatore/offset */
	printf("\n");
	for (int spiazzamento = 0; spiazzamento < 3; spiazzamento++)
		printf("Indirizzo %p, valore puntato %4d\n", pV2 + spiazzamento , *(pV2 + spiazzamento));

	/* Assegniamo a pV2 l'indirizzo dell'ultimo elemento del vettore vett
		e cicliamo finche' pV2 e' diverso dall'indirizzo iniziale del vettore
		Ad ogni iterazione DECREMENTIAMO il puntatore */
	printf("\n");
	pV2 = &vett[9];
	while (pV2 >= vett)
	{
		printf("Indirizzo %p, valore puntato %4d\n", pV2, *pV2);
		pV2 = pV2 - 1;
	}

	printf("\n");
	for(pV2 = &vett[9]; pV2 >= vett; pV2--)
		printf("Indirizzo %p, valore puntato %4d\n", pV2, *pV2);
	
	/* Assegniamo a pV1 l'indirizzo di vett
	e cicliamo finche' pV2 e' minore o uguale all'indirizzo dell'ultimo elemento di vett
	Ad ogni iterazione INCREMENTIAMO il puntatore */
	printf("\n");
	for (pV1 = vett; pV1 <= &vett[9]; pV1++)
		printf("Indirizzo %p, valore puntato %4d\n", pV1, *pV1);


	return 0;
}