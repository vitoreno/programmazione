/*
	Briscola in C
*/

#include "brislib.h"

int main()
{
	int mazzo[N_CARTE] = { 0 };
	int manoG1[3] = { -1, -1, -1 }, manoG2[3] = { -1, -1, -1 };
	int puntiG1 = 0, puntiG2 = 0;
	int paloBriscola;
	int idxG1, idxG2, idxPresa, idxGiocatoreDiMano;

	MescolaMazzo(mazzo);
	paloBriscola = mazzo[N_CARTE - 1] / 10;
	idxGiocatoreDiMano = 1;

	PescaCarta(mazzo, manoG1);
	PescaCarta(mazzo, manoG2);

	do
	{
		if (idxGiocatoreDiMano == 1)
		{
			PescaCarta(mazzo, manoG1);
			PescaCarta(mazzo, manoG2);
		}
		else
		{
			PescaCarta(mazzo, manoG2);
			PescaCarta(mazzo, manoG1);
		}

		printf("La briscola e' ");
		StampaCarta(mazzo[N_CARTE - 1]);
		printf("\n\n");

		StampaMano(manoG1, 1);
		StampaMano(manoG2, 2);

		if (idxGiocatoreDiMano == 1)
		{
			printf("Il giocatore 1 gioca: ");
			scanf_s("%d", &idxG1);
			printf("\t");
			StampaCarta(manoG1[idxG1]);
			printf("\n");

			printf("Il giocatore 2 gioca: ");
			scanf_s("%d", &idxG2);
			printf("\t");
			StampaCarta(manoG2[idxG2]);
			printf("\n");
		}
		else
		{
			printf("Il giocatore 2 gioca: ");
			scanf_s("%d", &idxG2);
			printf("\t");
			printf("\t");
			StampaCarta(manoG2[idxG2]);
			printf("\n");

			printf("Il giocatore 1 gioca: ");
			scanf_s("%d", &idxG1);
			printf("\t");
			StampaCarta(manoG1[idxG1]);
			printf("\n");
		}

		idxPresa = VerificaPresa(manoG1[idxG1], manoG2[idxG2], idxGiocatoreDiMano, paloBriscola);

		if (idxPresa == 1)
		{
			printf("Prende il giocatore 1!\n\n");
			puntiG1 += CalcolaPunti(manoG1[idxG1]);
			puntiG1 += CalcolaPunti(manoG2[idxG2]);
		}
		else
		{
			printf("Prende il giocatore 2!\n\n");
			puntiG2 += CalcolaPunti(manoG1[idxG1]);
			puntiG2 += CalcolaPunti(manoG2[idxG2]);
		}
		
		idxGiocatoreDiMano = idxPresa;

		manoG1[idxG1] = -1;
		manoG2[idxG2] = -1;
	} while (SiGioca(manoG1) && SiGioca(manoG2));

	printf("La partita e' terminata");
	if (puntiG1 == puntiG2)
		printf(" in pareggio.\n");
	else
		printf(". Vince il giocatore %d con %d punti.\n", puntiG1 > puntiG2 ? 1 : 2, puntiG1 > puntiG2 ? puntiG1 : puntiG2);
	return 0;
}