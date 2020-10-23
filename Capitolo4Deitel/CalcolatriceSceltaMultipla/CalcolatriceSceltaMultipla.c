/*
	OBIETTIVO:
	Programma che implementa una semplice calcolatrice, chiedendo all'utente gli operandi e l'operazione.

	PSEUDOCODICE:
	Dichiaro due operandi di tipo float
	Dichiaro una variabile per la scelta
	Dichiaro una variabile per il risultato

	Stampa delle scelte possibili (operazioni)
	
	Fai	
		Richiedi i valori all'utente
		Effettua un'operazione in base alla scelta
	Finché l'utente non sceglie una opzione ammissibile
*/

#include <stdio.h>

int main()
{
	/* Dichiarazione delle variabili */
	float op1, op2; /* operandi */
	float ris;
	int scelta;
	int operandi_inizializzati = 0; /* 0 vuol dire che gli operandi non sono inizializzati */

	printf("Calcolatrice con scelta multipla\n\n");

	/* Stampa delle scelte possibili */
	printf("Premere 0 per inserire gli operandi\n");
	printf("Premere 1 per la somma\n");
	printf("Premere 2 per la differenza\n");
	printf("Premere 3 per il prodotto\n");
	printf("Premere 4 per la divisione\n");
	printf("Premere -1 per terminare\n\n");

	do
	{
		printf("Scelta: ");
		scanf_s("%d", &scelta);

		switch (scelta)
		{
			case 0:
				printf("Inserisci operando 1: ");
				scanf_s("%f", &op1);
				printf("Inserisci operando 2: ");
				scanf_s("%f", &op2);
				
				/* Una volta inizializzati gli operandi posso aggiornare la variabile sentinella operandi_inizializzati */
				operandi_inizializzati = 1;
				break;
			case 1:
				if (operandi_inizializzati)
				{
					ris = op1 + op2;
					printf("Il risultato di %.2f + %.2f = %.2f\n", op1, op2, ris);
				}
				else
					printf("Operandi non inizializzati, prego inizializzare.\n");
				break;
			case 2:
				if (operandi_inizializzati)
				{
					ris = op1 - op2;
					printf("Il risultato di %.2f - %.2f = %.2f\n", op1, op2, ris);
				}
				else
					printf("Operandi non inizializzati, prego inizializzare.\n");
				break;
			case 3:
				if (operandi_inizializzati)
				{
					ris = op1 * op2;
					printf("Il risultato di %.2f * %.2f = %.2f\n", op1, op2, ris);
				}
				else
					printf("Operandi non inizializzati, prego inizializzare.\n");
				break;
			case 4:
				if (operandi_inizializzati && op2 != 0)
				{
					ris = op1 / op2;
					printf("Il risultato di %.2f / %.2f = %.2f\n", op1, op2, ris);
				}
				else
					printf("Operandi non inizializzati oppure divisione per zero, prego inizializzare.\n");
				break;
			default:
				break; /* In tutti gli altri casi non fare niente. */
		}

	} while (scelta != -1);

	return 0;
}