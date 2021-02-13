#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define K 5

enum TipoScelta {USCITA, AFFINITA, SALVATAGGIO, STAT};

void CaricaProfili(int T[], int G[]);
void CaricaUtente(int* Tip, int* Gen);
void StampaMenu();
int Affinita(const int T[], const int G[], int * QT, int * QG, int * StessaTip, int * StessoGen, int * Match);
void Salvataggio(int QT, int QG, int StessaTip, int StessoGen, int Match);

int main()
{
	int TipologiaVett[K];
	int GenereVett[K];
	int scelta;
	int contatoreAffinita = 0;
	int QueryTipologia, QueryGenere;
	int ContStessaTip, ContStessoGen, IndexMatch;

	CaricaProfili(TipologiaVett, GenereVett);

	do
	{
		StampaMenu();
		scanf("%d", &scelta);

		switch (scelta)
		{
		case AFFINITA:
			contatoreAffinita = Affinita(TipologiaVett, GenereVett, &QueryTipologia, &QueryGenere, &ContStessaTip, &ContStessoGen, &IndexMatch);
			break;
		case SALVATAGGIO:
			Salvataggio(QueryTipologia, QueryGenere, ContStessaTip, ContStessoGen, IndexMatch);
			break;
		case STAT:
			printf("La funzione affinita' e' stata richiamata %d volte\n", contatoreAffinita);
			break;
		}
	} while (scelta != USCITA);

	return 0;
}

void CaricaProfili(int T[], int G[])
{
	int i;

	for (i = 0; i < K; i++)
	{
		printf("Caricamento utente ID %d\n", i);
		CaricaUtente(&T[i], &G[i]);
	}

}

void StampaMenu()
{
	printf("--------------------\n");
	printf("[1] Verifica affinita' tra profili\n");
	printf("[2] Salvataggio su file\n");
	printf("[3] Visualizzazione statistica\n");
	printf("\n");
	printf("[0] Uscita\n");
	printf("--------------------\n");
}

void CaricaUtente(int * Tip, int * Gen)
{
	printf("Inserire [0] per Film o [1] per Serie TV: ");
	do
		scanf("%d", Tip);
	while (*Tip != 0 && *Tip != 1);

	printf("Inserire [1] per Fantascienza, [2] per Storico, [3] per Azione, [4] per Commedia: ");
	do
		scanf("%d", Gen);
	while (*Gen < 1 || *Gen > 4);
}

int Affinita(const int T[], const int G[], int* QT, int* QG, int* StessaTip, int* StessoGen, int* Match)
{
	static int contatore = 0;
	int i;

	printf("Caricamento profilo query\n");
	CaricaUtente(QT, QG);

	*StessaTip = 0;
	*StessoGen = 0;
	*Match = -1;

	for (i = 0; i < K; i++)
	{
		if (T[i] == *QT)
			(*StessaTip)++;
		if (G[i] == *QG)
			(*StessoGen)++;
		if (T[i] == *QT && G[i] == *QG)
			*Match = i;
	}

	contatore++;
	return contatore;
}

void Salvataggio(int QT, int QG, int StessaTip, int StessoGen, int Match)
{
	FILE* out;
	out = fopen("Output.txt", "w");

	if (out != NULL)
	{
		fprintf(out, "Riepilogo ultima query effettuata\n");
		fprintf(out, "Query: Tipologia %d - Genere %d\n", QT, QG);
		fprintf(out, "Num profili con stessa preferenza tipologia: %d\n", StessaTip);
		fprintf(out, "Num profili con stessa preferenza genere: %d\n", StessoGen);
		fprintf(out, "Match: ");
		if(Match == -1)
			fprintf(out, "no match\n");
		else
			fprintf(out, "%d\n", Match);

		fclose(out);
	}
	else
		printf("Errore nell'apertura del file di output.\n");
}