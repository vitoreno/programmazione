#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define K 5

enum TipoScelta { USCITA, AFFINITA, SALVATAGGIO, STAT };

typedef struct
{
	int Tipologia;
	int Genere;
} SProf;

typedef struct
{
	SProf ProfiloQuery;
	int StessaTip, StessoGen, Match;
} SQuery;

void CaricaProfili(SProf P[]);
void CaricaUtente(SProf * Tmp);
void StampaMenu();
int Affinita(const SProf P[], SQuery* Query);
void Salvataggio(const SQuery Query);

int main()
{
	SProf Profili[K];
	int scelta;
	int contatoreAffinita = 0;
	SQuery Query;

	CaricaProfili(Profili);

	do
	{
		StampaMenu();
		scanf("%d", &scelta);

		switch (scelta)
		{
		case AFFINITA:
			contatoreAffinita = Affinita(Profili, &Query);
			break;
		case SALVATAGGIO:
			Salvataggio(Query);
			break;
		case STAT:
			printf("La funzione affinita' e' stata richiamata %d volte\n", contatoreAffinita);
			break;
		}
	} while (scelta != USCITA);

	return 0;
}

void CaricaProfili(SProf P[])
{
	int i;

	for (i = 0; i < K; i++)
	{
		printf("Caricamento utente ID %d\n", i);
		CaricaUtente(&P[i]);
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

void CaricaUtente(SProf* Tmp)
{
	printf("Inserire [0] per Film o [1] per Serie TV: ");
	do
		scanf("%d", &Tmp->Tipologia);
	while (Tmp->Tipologia != 0 && Tmp->Tipologia != 1);

	printf("Inserire [1] per Fantascienza, [2] per Storico, [3] per Azione, [4] per Commedia: ");
	do
		scanf("%d", &Tmp->Genere);
	while (Tmp->Genere < 1 || Tmp->Genere > 4);
}

int Affinita(const SProf P[], SQuery* Query)
{
	static int contatore = 0;
	int i;

	printf("Caricamento profilo query\n");
	CaricaUtente(&Query->ProfiloQuery);

	Query->StessaTip = 0;
	Query->StessoGen = 0;
	Query->Match = -1;

	for (i = 0; i < K; i++)
	{
		if (P[i].Tipologia == Query->ProfiloQuery.Tipologia)
			Query->StessaTip++;
		if (P[i].Genere == Query->ProfiloQuery.Genere)
			Query->StessoGen++;
		if (P[i].Tipologia == Query->ProfiloQuery.Tipologia && P[i].Genere == Query->ProfiloQuery.Genere)
			Query->Match = i;
	}

	contatore++;
	return contatore;
}

void Salvataggio(const SQuery Query)
{
	FILE* out;
	out = fopen("Output.txt", "w");

	if (out != NULL)
	{
		fprintf(out, "Riepilogo ultima query effettuata\n");
		fprintf(out, "Query: Tipologia %d - Genere %d\n", Query.ProfiloQuery.Tipologia, Query.ProfiloQuery.Genere);
		fprintf(out, "Num profili con stessa preferenza tipologia: %d\n", Query.StessaTip);
		fprintf(out, "Num profili con stessa preferenza genere: %d\n", Query.StessoGen);
		fprintf(out, "Match: ");
		if (Query.Match == -1)
			fprintf(out, "no match\n");
		else
			fprintf(out, "%d\n", Query.Match);

		fclose(out);
	}
	else
		printf("Errore nell'apertura del file di output.\n");
}