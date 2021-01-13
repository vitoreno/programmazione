#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITTA 4
#define MAX_PASS 25

enum Citta { BARI, ROMA, NAPOLI, MILANO };
enum Scelta {USCITA, EMISSIONE_BIGLIETTO, OCCUPAZIONE_POSTI, TOTALE_VENDUTI, VISUALIZZA_SCONTI};
enum OpzioneSconto {APPLICA, VISUALIZZA};

void StampaMenu();
void StampaCitta(int IdxCitta);
float EmettiBiglietto(const int D[NUM_CITTA][NUM_CITTA], int Occ[NUM_CITTA][NUM_CITTA]);
void StampaOccupazionePosti(const int OccPosti[NUM_CITTA][NUM_CITTA]);
float CalcolaTariffa(float km);
float GestisciSconto(int opzione, float costo);
void StampaTotale(const int OccPosti[NUM_CITTA][NUM_CITTA], float TotaleBiglietti);

int main()
{
	int Distanze[NUM_CITTA][NUM_CITTA] = {	{0, 458, 266, 881},
											{ 458, 0, 226, 573 },
											{ 266, 226, 0, 772 },
											{ 881 ,573 ,772 ,0 } };

	int OccPosti[NUM_CITTA][NUM_CITTA] = { 0 };
	int SceltaUtente;
	float TotaleBiglietti = 0.0;

	printf("Sistema di bigliettazione\n");

	do
	{
		StampaMenu();
		scanf_s("%d", &SceltaUtente);

		switch (SceltaUtente)
		{
		case EMISSIONE_BIGLIETTO:
			TotaleBiglietti += EmettiBiglietto(Distanze, OccPosti);
			break;
		case OCCUPAZIONE_POSTI:
			StampaOccupazionePosti(OccPosti);
			break;
		case TOTALE_VENDUTI:
			StampaTotale(OccPosti, TotaleBiglietti);
			break;
		case VISUALIZZA_SCONTI:
			GestisciSconto(VISUALIZZA, 0.0);
			break;
		}
	} while (SceltaUtente != USCITA);

	return 0;
}

void StampaMenu()
{
	printf("---------------------\n");
	printf("1. Emissione biglietto\n");
	printf("2. Visualizza occupazione posti\n");
	printf("3. Riepilogo \n");
	printf("4. Visualizza sconti emessi\n");
	printf("0. Esci\n");
	printf("---------------------\n");
}

void StampaCitta(int IdxCitta)
{
	switch (IdxCitta)
	{
	case BARI:
		printf("Bari");
		break;
	case ROMA:
		printf("Roma");
		break;
	case NAPOLI:
		printf("Napoli");
		break;
	case MILANO:
		printf("Milano");
		break;
	}
}

float EmettiBiglietto(const int D[NUM_CITTA][NUM_CITTA], int Occ[NUM_CITTA][NUM_CITTA])
{
	int i;
	float costo = 0.0;
	int partenza, arrivo;
	printf("Selezionare citta' di partenza\n");
	for (int i = 0; i < NUM_CITTA; i++)
	{
		printf("%d. ", i);
		StampaCitta(i);
		printf("\n");
	}

	do
	{
		scanf_s("%d", &partenza);
	} while (partenza < 0 || partenza > NUM_CITTA - 1);

	printf("Selezionare citta' di arrivo\n");
	for (int i = 0; i < NUM_CITTA; i++)
	{
		printf("%d. ", i);
		StampaCitta(i);
		printf("\n");
	}

	do
	{
		scanf_s("%d", &arrivo);
	} while (arrivo < 0 || arrivo> NUM_CITTA - 1);

	if (partenza != arrivo)
		if (Occ[partenza][arrivo] < MAX_PASS)
		{
			costo = CalcolaTariffa(D[partenza][arrivo]);
			Occ[partenza][arrivo]++;
			costo = GestisciSconto(APPLICA, costo);
		}
		else
			printf("Errore. La tratta scelta e' al completo.\n");
	else
		printf("Errore. Citta' di partenza e di arrivo coincidenti.\n");

	return costo;
}

float GestisciSconto(int opzione, float costo)
{
	static int ScontiEmessi = 0;
	switch (opzione)
	{
	case APPLICA:
		if (ScontiEmessi <= 5)
		{
			if (rand() % 10 == 0)
			{
				costo /= 1.02;
				ScontiEmessi++;
			}
		}
		break;

	case VISUALIZZA:
		printf("Sono stati emessi %d sconti\n", ScontiEmessi);
		break;
	}

	return costo;
}

float CalcolaTariffa(float km)
{
	float tariffa;
	if (km <= 200)
		tariffa = km * 0.07;
	else
		tariffa = 200 * 0.07 + (km - 200) * 0.05;
	return tariffa;
}

void StampaOccupazionePosti(const int OccPosti[NUM_CITTA][NUM_CITTA])
{
	int i, j;
	printf("Stampa occupazione posti per tratta\n");
	for (i = 0; i < NUM_CITTA; i++)
	{
		for (j = 0; j < NUM_CITTA; j++)
		{
			printf("Tratta da "); 
			StampaCitta(i);
			printf(" a ");
			StampaCitta(j);
			printf(" - Posti occupati: %d\n", OccPosti[i][j]);
		}
	}
}

void StampaTotale(const int OccPosti[NUM_CITTA][NUM_CITTA], float TotaleBiglietti)
{
	int i, j;
	int ContaBiglietti = 0;

	for (i = 0; i < NUM_CITTA; i++)
		for (j = 0; j < NUM_CITTA; j++)
			ContaBiglietti += OccPosti[i][j];

	printf("Nella giornata odierna sono stati emessi %d biglietti. Totale incasso %.2f\n", ContaBiglietti, TotaleBiglietti);
}