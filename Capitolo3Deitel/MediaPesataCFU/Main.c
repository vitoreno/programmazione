/*
Obiettivo: Calcolo della media pesata della valutazione della carriera universitaria
			utilizzando come pesi i CFU corrispondenti ad ogni esame
*/

#include <stdio.h>

int main()
{
	int voto;
	int totaleVotiPesati;
	int CFU;
	int totaleCFU;
	float mediaPesata;

	totaleVotiPesati = 0;
	totaleCFU = 0;

	printf("Inserire un voto (-1 per terminare): ");
	scanf_s("%d", &voto);

	while (voto != -1)
	{
		printf("Inserire il numero di CFU: ");
		scanf_s("%d", &CFU);

		totaleVotiPesati += (voto * CFU); /* Le parentesi sono necessarie??? */
		totaleCFU += CFU; /* Equivalente a totaleCFU = totaleCFU + CFU; */
		
		printf("Inserire un voto (-1 per terminare): ");
		scanf_s("%d", &voto);
	}

	if (totaleCFU != 0) 
	{
		/* Notare la presenza delle parentesi graffe poiché il blocco presenta più di una istruzione*/
		mediaPesata = (float)totaleVotiPesati / totaleCFU;

		printf("La media pesata e': %.2f\n", mediaPesata);
		printf("Calcolata su un numero di CFU pari a: %d\n", totaleCFU);
	}
	else
		printf("Non e' stato possibile calcolare la media pesata.\n");
	

	return 0;
}