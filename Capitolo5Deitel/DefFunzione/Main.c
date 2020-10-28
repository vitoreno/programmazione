/*
	Programma che definisce una funzione custom
*/

#include <stdio.h>

/* Prototipi delle funzioni */
int quadrato(int q);

int main()
{
	int numero;
	int risultato;

	printf("Inserisci un numero: ");
	scanf_s("%d", &numero);
	printf("%d al quadrato fa %d\n", numero, quadrato(numero));

	for (numero = 1; numero <= 10; numero++)
	{
		risultato = quadrato(numero);
		printf("%d al quadrato fa %d\n", numero, risultato);
	}

	return 0;
}

/* Definizione delle funzioni */
int quadrato(int q)
{
	return q * q;
}