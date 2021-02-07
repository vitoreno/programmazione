#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N_INTERVISTATI 100
#define N_DOMANDE 10

enum TipiRisp { NON_RISP, SICURAMENTE_NO, NO, SI, SICURAMENTE_SI };
enum TipiScelta {ESCI, RISP_FREQ, STAT_RISP, STAT_PART};
enum TipiRitorno { OK, KO };

int CaricaDati(int R[N_INTERVISTATI][N_DOMANDE]);
void StampaMenu();
int RisposteFrequenti(const int R[N_INTERVISTATI][N_DOMANDE], int MT[N_DOMANDE], int M[N_DOMANDE]);
int StatisticheRisposte(const int R[N_INTERVISTATI][N_DOMANDE], int* TotR, int* TotRND);
int StatistichePartecipanti(const int R[N_INTERVISTATI][N_DOMANDE], int* NumP, int* NumPT, int* NumPNM);
char* ScriviRisposta(int risp);

int main()
{
	int Risposte[N_INTERVISTATI][N_DOMANDE];
	int scelta, risultato;
	int ModaTot[N_DOMANDE] = { 0 };
	int Moda[N_DOMANDE] = { 0 };
	int i;
	int TotRisposte = 0, TotRisposteNonDate = 0;
	int NumP, NumPTutte, NumPNM;

	memset(Risposte, 0xff, N_INTERVISTATI * N_DOMANDE * sizeof(int));
	risultato = CaricaDati(Risposte);
	
	if (risultato == KO)
		return KO;
	else
	{
		do
		{
			StampaMenu();
			scanf("%d", &scelta);

			switch (scelta)
			{
			case RISP_FREQ:
				risultato = RisposteFrequenti(Risposte, ModaTot, Moda);
				printf("Eseguita funzione RisposteFrequenti\n");
				printf("Valore restituito: %d\n", risultato);
				printf("Risposte piu' frequenti:\n");
				for (i = 0; i < N_DOMANDE; i++)
					printf("Domanda: %d - Risposta %s\n", i, ScriviRisposta(ModaTot[i]));
				printf("Risposte piu' frequenti escludendo le non risposte:\n");
				for (i = 0; i < N_DOMANDE; i++)
					printf("Domanda: %d - Risposta %s\n", i, ScriviRisposta(Moda[i]));
				break;
			case STAT_RISP:
				risultato = StatisticheRisposte(Risposte, &TotRisposte, &TotRisposteNonDate);
				printf("Eseguita funzione StatisticheRisposte\n");
				printf("Valore restituito: %d\n", risultato);
				printf("Numero totale di risposte date dagli intervistati: %d\n", TotRisposte);
				printf("Numero totale di risposte non date dagli intervistati: %d\n", TotRisposteNonDate);
				break;
			case STAT_PART:
				risultato = StatistichePartecipanti(Risposte, &NumP, &NumPTutte, &NumPNM);
				printf("Eseguita funzione StatistichePartecipanti\n");
				printf("Valore restituito: %d\n", risultato);
				printf("Numero totale di partecipanti: %d\n", NumP);
				printf("Numero totale di partecipanti che hanno risposto a tutte le domande: %d\n", NumPTutte);
				printf("Numero totale di partecipanti che hanno risposto a un numero di domande comprese tra N e M: %d\n", NumPNM);
				break;
			}
		} while (scelta != ESCI);
	
		return OK;
	}
}

int StatisticheRisposte(const int R[N_INTERVISTATI][N_DOMANDE], int* TotR, int* TotRND)
{
	int i, j;

	*TotR = 0;
	*TotRND = 0;

	for (i = 0; i < N_INTERVISTATI; i++)
		for (j = 0; j < N_DOMANDE; j++)
			if (R[i][j] == NON_RISP)
				(*TotRND)++;
			else if(R[i][j] > 0)
				(*TotR)++;
	
	return OK;
}

int StatistichePartecipanti(const int R[N_INTERVISTATI][N_DOMANDE], int* NumP, int* NumPT, int* NumPNM)
{
	int i, j;
	int N, M;
	int cnt;
	*NumP = 0;
	*NumPT = 0;
	*NumPNM = 0;

	printf("Inserire il limite inferiore N: ");
	scanf("%d", &N);
	printf("Inserire il limite superiore M: ");
	scanf("%d", &M);

	for (i = 0; i < N_INTERVISTATI; i++)
	{
		if (R[i][0] != -1)
			(*NumP)++;
		
		cnt = 0;
		for (j = 0; j < N_DOMANDE; j++)
			if (R[i][j] > 0)
				cnt++;
		
		if (cnt == N_DOMANDE)
			(*NumPT)++;

		if (cnt >= N && cnt <= M)
			(*NumPNM)++;
	}

	return OK;
}

int CaricaDati(int R[N_INTERVISTATI][N_DOMANDE])
{
	FILE* fp;
	int i, j;

	fp = fopen("Intervista.txt", "r");
	if (fp == NULL)
		return KO;
	else
	{
		for (i = 0; i < N_INTERVISTATI && !feof(fp); i++)
			for (j = 0; j < N_DOMANDE && !feof(fp); j++)
				fscanf(fp, "%d", &R[i][j]);

		fclose(fp);
		return OK;
	}
}

void StampaMenu()
{
	printf("Premere un tasto per effettuare una scelta:\n");
	printf("--------------------------------\n");
	printf("[1] Risposte Frequenti\n");
	printf("[2] Statistiche sulle risposte\n");
	printf("[3] Statistiche sui partecipanti\n");
	printf("--------------------------------\n");
	printf("[0] Esci dal programma\n");
	printf("--------------------------------\n");
}

int RisposteFrequenti(const int R[N_INTERVISTATI][N_DOMANDE], int MT[N_DOMANDE], int M[N_DOMANDE])
{
	int Contatori[5][N_DOMANDE] = { 0 };
	int i, j;
	int risposta;
	int fermati = 0;
	int MaxVal, MaxIndex;

	for(i=0; i<N_INTERVISTATI && !fermati; i++)
		for (j = 0; j < N_DOMANDE && !fermati; j++)
		{
			risposta = R[i][j];
			
			if (risposta == -1)
				fermati = 1;
			else
				Contatori[risposta][j]++;
		}
	
	for (j = 0; j < N_DOMANDE; j++)
	{
		MaxVal = Contatori[1][j];
		MaxIndex = 1;
		for (i = 2; i < 5; i++)
		{
			if (Contatori[i][j] > MaxVal)
			{
				MaxVal = Contatori[i][j];
				MaxIndex = i;
			}
		}

		M[j] = MaxIndex;
		if(Contatori[0][j] > MaxVal)
			MT[j] = 0;
		else
			MT[j] = MaxIndex;
	}

	return OK;
}

char* ScriviRisposta(int risp)
{
	switch (risp)
	{
	case NON_RISP:
		return "Non risposta";
	case SICURAMENTE_NO:
		return "Sicuramente NO";
	case NO:
		return "NO";
	case SI:
		return "SI";
	case SICURAMENTE_SI:
		return "Sicuramente SI";
	default:
		return "Risposta non valida";
	}
}