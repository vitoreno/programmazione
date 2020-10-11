/* Programma per la moltiplicazione di due numeri interi */
/* #define _CRT_SECURE_NO_WARNINGS */ /* Utilizzare questa direttiva se non si vuole utilizzare la scanf_s */
#include <stdio.h>

int main()
{
	int x; /*Primo numero*/
	int y; /*Secondo numero*/
	int prodotto; /*Variabile per contenere il prodotto*/

	printf("Inserire il valore di x: ");
	scanf_s("%d", &x);
	
	printf("Inserire il valore di y: ");
	scanf_s("%d", &y);

	prodotto = x * y;

	printf("Il prodotto di %d per %d e': %d", x, y, prodotto);

	return 0;
}