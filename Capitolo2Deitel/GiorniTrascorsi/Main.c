/* Programma per il calcolo del numero di giorni a partire da un numero di ore */
/* #define _CRT_SECURE_NO_WARNINGS */ /* Utilizzare questa direttiva se non si vuole utilizzare la scanf_s */
#include <stdio.h>

int main()
{
	int oreTotali; /*Primo numero*/
	int giorni; /*Secondo numero*/
	int oreResidue; /*Variabile per contenere il prodotto*/

	printf("Inserire il numero di ore: ");
	scanf_s("%d", &oreTotali);

	giorni = oreTotali / 24;
	oreResidue = oreTotali % 24;

	printf("Numero totale di ore inserite: %d\n\n", oreTotali);
	printf("Numero di giorni corrispondenti: %d\n", giorni);
	printf("Numero di ore residue: %d\n", oreResidue);

	return 0;
}