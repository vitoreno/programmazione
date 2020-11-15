/*
	Gestore Prenotazioni Hotel
	Esercizio di preparazione al I Esonero di Programmazione (A - L)
	A.A. 2020/2021
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_DOPPIE 5
#define NUM_TRIPLE 3
#define NUM_QUADRUPLE 2

enum TipiScelta {ESCI, PRENOTA, VISUALIZZA};
enum TipiPasti {NO_PASTI, COLAZIONE, MEZZA_PENSIONE, PENSIONE_COMPLETA};
enum TipiCamere {DOPPIA, TRIPLA, QUADRUPLA};

void InizializzaCamere(int C[], int NumCamere);
float CalcolaCostoCamera(int NumOspiti, int NumNotti);
float CalcolaCostoPasti(int TipoPasto, int NumPersone, int NumNotti, int ServizioInCamera);
void StampaMenu(void);
void StampaTipiPasti(void);
int ContaDisponibili(const int C[], int NumCamere);
int VerificaDisponibilita(const int C[], int NumCamere);

int main()
{
	int scelta;
	int CamereDoppie[NUM_DOPPIE] = { 0 };
	int CamereTriple[NUM_TRIPLE] = { 0 };
	int CamereQuadruple[NUM_QUADRUPLE] = { 1, 1 };
	int NumeroOspiti, CameraDisponibile, TipoCamera, NumeroNotti, PastoScelto, ServizioInCamera;
	float TotaleCamera;

	
	srand(42);
	InizializzaCamere(CamereDoppie, NUM_DOPPIE);
	InizializzaCamere(CamereTriple, NUM_TRIPLE);
	InizializzaCamere(CamereQuadruple, NUM_QUADRUPLE);
	

	StampaMenu();

	do
	{
		printf("Prego effettuare una scelta: ");
		scanf_s("%d", &scelta);

		switch (scelta)
		{
		case PRENOTA:
			NumeroOspiti = 0;
			printf("Prego inserire il numero di ospiti: ");
			scanf_s("%d", &NumeroOspiti);
			
			switch (NumeroOspiti)
			{
			case 1:
			case 2:
				CameraDisponibile = VerificaDisponibilita(CamereDoppie, NUM_DOPPIE);
				if (CameraDisponibile >= 0)
				{
					TipoCamera = DOPPIA;
					break;
				}
			case 3:
				CameraDisponibile = VerificaDisponibilita(CamereTriple, NUM_TRIPLE);
				if (CameraDisponibile >= 0)
				{
					TipoCamera = TRIPLA;
					break;
				}
			case 4:
				CameraDisponibile = VerificaDisponibilita(CamereQuadruple, NUM_QUADRUPLE);
				if (CameraDisponibile >= 0)
				{
					TipoCamera = QUADRUPLA;
					break;
				}
			default:
				CameraDisponibile = -1;
			}

			
			if (CameraDisponibile != -1)
			{
				printf("Inserire il numero di notti richieste: ");
				scanf_s("%d", &NumeroNotti);
				printf("La camera e' disponibile. Prego selezionare una opzione per i pasti\n");
				StampaTipiPasti();
				do
				{
					scanf_s("%d", &PastoScelto);
				} while (PastoScelto < 0 || PastoScelto > 3);
				
				printf("Si desidera il servizio in camera? (0: No, 1: Si): ");
				scanf_s("%d", &ServizioInCamera);

				TotaleCamera = CalcolaCostoCamera(NumeroOspiti, NumeroNotti);
				TotaleCamera += CalcolaCostoPasti(PastoScelto, NumeroOspiti, NumeroNotti, ServizioInCamera);
				
				if (NumeroNotti >= 2)
					TotaleCamera /= 1.02;
				if(TotaleCamera > 100.0)
					TotaleCamera /= 1.02;

				printf("Il totale dei servizi richiesti e': %.2f Euro\n\n", TotaleCamera);

				switch (TipoCamera)
				{
				case DOPPIA:
					CamereDoppie[CameraDisponibile] = 0;
					break;
				case TRIPLA:
					CamereTriple[CameraDisponibile] = 0;
					break;
				case QUADRUPLA:
					CamereQuadruple[CameraDisponibile] = 0;
					break;
				}

				StampaMenu();
			}
			else
				printf("Siamo spiacenti, ma non vi sono camere disponibili per soddisfare la richiesta.\n");

			break;
		case VISUALIZZA:
			printf("Disponibilita' camere doppie (anche uso singola): %d\n", ContaDisponibili(CamereDoppie, NUM_DOPPIE));
			printf("Disponibilita' camere triple: %d\n", ContaDisponibili(CamereTriple, NUM_TRIPLE));
			printf("Disponibilita' camere quadruple: %d\n", ContaDisponibili(CamereQuadruple, NUM_QUADRUPLE));
			break;
		default:
			printf("Scelta non valida.\n");
			break;
		}
	} while (scelta != ESCI);

	return 0;
}

void InizializzaCamere(int C[], int NumCamere)
{
	int idx;
	for (idx = 0; idx < NumCamere; idx++)
		C[idx] = rand() % 5;
}

void StampaMenu(void)
{
	printf("******************************\n");
	
	printf("1. Effettua una prenotazione\n");
	printf("2. Visualizza disponibilita'\n");
	printf("0. Esci\n");

	printf("******************************\n\n");
}

void StampaTipiPasti()
{
	printf("******************************\n");

	printf("0. No pasti\n");
	printf("1. Solo colazione\n");
	printf("2. Mezza pensione\n");
	printf("3. Pensione completa\n");

	printf("******************************\n\n");
}

int ContaDisponibili(const int C[], int NumCamere)
{
	int idx;
	int disponibili = 0;

	for (idx = 0; idx < NumCamere; idx++)
		if (C[idx] != 0)
			disponibili++;
	
	return disponibili;
}

float CalcolaCostoCamera(int NumOspiti, int NumNotti)
{
	switch (NumOspiti)
	{
	case 1:
		return 30.0 * NumNotti;
	case 2:
		return 40.0 * NumNotti;
	case 3:
		return 60.0 * NumNotti;
	case 4:
		return 70.0 * NumNotti;
	default:
		return 0.0;
	}
}

float CalcolaCostoPasti(int TipoPasto, int NumPersone, int NumNotti, int ServizioInCamera)
{
	float percentuale = 1.0;
	if (ServizioInCamera)
		percentuale = 1.05;

	switch (TipoPasto)
	{
	case NO_PASTI:
		return 0.0;
	case COLAZIONE:
		return 10.0 * NumPersone * NumNotti * percentuale;
	case MEZZA_PENSIONE:
		return 25.0 * NumPersone * NumNotti * percentuale;
	case PENSIONE_COMPLETA:
		return 35.0 * NumPersone * NumNotti * percentuale;
	}
}

int VerificaDisponibilita(const int C[], int NumCamere)
{
	int idx;

	for (idx = 0; idx < NumCamere; idx++)
		if (C[idx] != 0)
			return idx;

	return -1;
}