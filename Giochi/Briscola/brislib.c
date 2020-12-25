#include "brislib.h"

void MescolaMazzo(int mazzo[])
{
	int idx;
	int carta;
	int carteEstratte[N_CARTE] = { 0 };
	//srand(time(NULL));
	srand(0);
	for (idx = 0; idx < N_CARTE; idx++)
	{
		do
		{
			carta = rand() % N_CARTE;
		} while (carteEstratte[carta] != 0);
		
		carteEstratte[carta] = 1;
		mazzo[idx] = carta;
	}
}

void PescaCarta(int mazzo[], int mano[])
{
	static int idxDaEstrarre = 0;
	int i;

	if(idxDaEstrarre < N_CARTE)
		for (i = 0; i < 3; i++)
			if(mano[i] == -1)
				mano[i] = mazzo[idxDaEstrarre++];
}

int SiGioca(int mano[])
{
	if (mano[0] == mano[1] && mano[1] == mano[2])
		return 0;
	else
		return 1;
}

char* StampaPalo(int carta)
{
	switch (carta / 10)
	{
		case DENARI:
			return "DENARI";
		case SPADE:
			return "SPADE";
		case COPPE:
			return "COPPE";
		case BASTONI:
			return "BASTONI";
		default:
			return "ERROR";
	}
}

int ValoreCarta(int carta)
{
	int valoreCarta = carta % 10;
	if (valoreCarta == 0)
		valoreCarta = 10;
	
	return valoreCarta;
}

void StampaCarta(int carta)
{
	printf("%d di %s", ValoreCarta(carta), StampaPalo(carta));
}

int CalcolaPunteggioInterno(int carta, int paloDiRiferimento, int paloBriscola)
{
	int punteggioInterno;
	
	if (carta / 10 == paloDiRiferimento || carta / 10 == paloBriscola)
	{
		punteggioInterno = ValoreCarta(carta);

		if (punteggioInterno == 1)
			punteggioInterno = 12;
		else if (punteggioInterno == 3)
			punteggioInterno = 11;
		if (carta / 10 == paloBriscola)
			punteggioInterno += 11;
	}
	else
		punteggioInterno = 0;
	
	return punteggioInterno;
}

int VerificaPresa(int carta1, int carta2, int idxGiocatoreDiMano, int paloBriscola)
{
	int paloDiRiferimento;
	int tmpG1, tmpG2;
	
	if (idxGiocatoreDiMano == 1)
		paloDiRiferimento = carta1 / 10;
	else
		paloDiRiferimento = carta2 / 10;

	tmpG1 = CalcolaPunteggioInterno(carta1, paloDiRiferimento, paloBriscola);
	tmpG2 = CalcolaPunteggioInterno(carta2, paloDiRiferimento, paloBriscola);
	
	if (tmpG1 > tmpG2)
		return 1;
	else
		return 2;
}

int CalcolaPunti(int carta)
{
	int punteggio = ValoreCarta(carta);
	switch (punteggio)
	{
	case ASSO:
		punteggio = 11;
		break;
	case 3:
		punteggio = 10;
		break;
	case RE:
		punteggio = 4;
		break;
	case CAVALLO:
		punteggio = 3;
		break;
	case FANTE:
		punteggio = 2;
		break;
	default:
		punteggio = 0;
		break;
	}
	return punteggio;
}

void StampaMano(int mano[], int idxGiocatore)
{
	int i;

	printf("Il giocatore %d ha in mano: ", idxGiocatore);
	for (i = 0; i < 3; i++)
	{
		if (mano[i] != -1)
		{
			printf("%d) ", i);
			StampaCarta(mano[i]);
			printf(" ");
		}
	}
	printf("\n");
}