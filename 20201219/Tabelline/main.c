/*
	Tabelline con array multidimensionali
	L'obiettivo di questa esercitazione e' quello di inizializzare un array bidimensionale contenente le tabelline
	e stampare i contenuti a schermo
*/

#include <stdio.h>

#define RIGHE 11
#define COLONNE 11

void CalcolaTabelline(int T[RIGHE][COLONNE]);
void StampaTabelline(const int T[RIGHE][COLONNE]);

int main()
{
	int Tabelline[RIGHE][COLONNE];

	CalcolaTabelline(Tabelline);
	StampaTabelline(Tabelline);

	return 0;
}

void CalcolaTabelline(int T[RIGHE][COLONNE])
{
	int r, c;
	for (r = 0; r < RIGHE; r++)
		for (c = 0; c < COLONNE; c++)
			T[r][c] = r * c;
}

void StampaTabelline(const int T[RIGHE][COLONNE])
{
	int r, c;
	printf("Stampa delle tabelline\n\n");

	for (r = 0; r < RIGHE; r++)
	{
		printf("%3d|", r);

		for (c = 0; c < COLONNE; c++)
			printf("%4d", T[r][c]);

		printf("\n");
	}
}
