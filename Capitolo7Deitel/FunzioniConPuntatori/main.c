/*
	Programma per effettuare la somma di due numeri usando un puntatore
	Si codifica anche una funzione per effettuare le quattro operazioni
*/
#include <stdio.h>

enum ErrorType {OK, DIVISIONE_PER_ZERO};

/* Somma riceve in input due numeri interi e un indirizzo di variabile intera */
void somma(int x, int y, int* z);
int operazioni(float op1, float op2, float* s, float* diff, float* pr, float* div);

int main()
{
	int u = 10;
	int v = 0;
	int z;
	float z1, z2, z3, z4;
	int status;

	/* Richiamo somma passando il valore di u, il valore di v e il valore dell'indirizzo di z */
	somma(u, v, &z);

	printf("Il valore di %d + %d e' %d\n", u, v, z);

	/* Utilizzo adesso una sola funzione per effettuare le quattro operazioni */
	status = operazioni((float)u, (float)v, &z1, &z2, &z3, &z4);
	
	printf("Somma: %.2f\nDifferenza: %.2f\nProdotto: %.2f\n", z1, z2, z3);
	
	if (status == DIVISIONE_PER_ZERO)
		printf("Non e' possibile dividere per zero\n");
	else
		printf("Divisione: % .2f\n", z4);
	
}

void somma(int x, int y, int* k)
{
	*k = x + y;
}

/* 
	Osservare l'utilizzo di un numero intero per tenere traccia di eventuali errori 
		0 - OK
		1 - DIVISIONE_PER_ZERO
*/

int operazioni(float op1, float op2, float* s, float* diff, float* pr, float* div)
{
	*s = op1 + op2; /* il risultato della somma viene scritto nel valore puntato da s*/
	*diff = op1 - op2; /* il risultato della differenza viene scritto nel valore puntato da diff*/
	*pr = op1 * op2; /* il risultato del prodotto viene scritto nel valore puntato da pr*/
	if (op2 != 0)
	{
		*div = op1 / op2; /* il risultato della divisione viene scritto nel valore puntato da div*/
		return OK;
	}
	else
		return DIVISIONE_PER_ZERO;
}