/*
	Esempio di programma per la lettura di parametri da un file di configurazione
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Parametri_
{
	int ID;
	char Note[32];
	float Val;
} Parametri;

enum Status {OK, KO};

Parametri LeggiFileCfg(const char * fn);
int LeggiFileCfgRif(const char* fn, Parametri* P);
void StampaParametri(const Parametri P);

int main()
{
	Parametri P1, P2;
	int err;

	P1 = LeggiFileCfg("params.cfg");
	StampaParametri(P1);

	printf("\n");

	err = LeggiFileCfgRif("params.cfg", &P2);
	if (err != OK)
		printf("Errore durante l'elaborazione del file di configurazione.\n");
	else
		StampaParametri(P2);

	return 0;
}

Parametri LeggiFileCfg(const char* fn)
{
	/* Funzione per la lettura di un file di configurazione 
		Il file deve essere un file di testo formattato secondo la seguente convenzione
		
		Riga di esempio:
			<NomeVariabile:Stringa> <TipoVariabile:Char> <ValoreVariabile>

		Input
			fn: nome del file di configurazione

		Output
			Struttura contenente i parametri
	*/

	Parametri TmpP = { 0 };
	FILE* fp = NULL;
	int err;
	char Key[64];
	char VarType;
	char FormatStr[8];


	err = fopen_s(&fp, fn, "r");
	if (!err)
	{
		while (!err && fscanf_s(fp, "%s %c", Key, _countof(Key), &VarType) != EOF) /* Osservare l'utilizzo dello spazio per facilitare il compito alla fscanf_s e l'utilizzo di _countof() */
		{
			/* In base al carattere indicante il tipo si prepara FormatStr di conseguenza 
				in caso di errore si fa in modo di uscire dal ciclo
			*/
			if (VarType == 'i')
				strcpy_s(FormatStr, _countof(FormatStr), "%d");
			else if (VarType == 'f')
				strcpy_s(FormatStr, _countof(FormatStr), "%f");
			else if (VarType == 's')
				strcpy_s(FormatStr, _countof(FormatStr), "%s");
			else
				err = KO;
			
			if (err != KO)
			{
				/* La fscanf_s successiva viene effettuata solo se la chiave (nome della variabile) e' riconosciuta */
				if (strcmp(Key, "ID") == 0)
					fscanf_s(fp, FormatStr, &TmpP.ID);
				else if (strcmp(Key, "Note") == 0)
					fscanf_s(fp, FormatStr, TmpP.Note, _countof(TmpP.Note));
				else if (strcmp(Key, "Val") == 0)
					fscanf_s(fp, FormatStr, &TmpP.Val);
			}
		}

		fclose(fp);
	}

	if (err != OK)
		printf("Errore durante l'elaborazione del file di configurazione.\n");

	return TmpP;
}

int LeggiFileCfgRif(const char* fn, Parametri* P)
{
	/* Funzione per la lettura di un file di configurazione
		Il file deve essere un file di testo formattato secondo la seguente convenzione

		Riga di esempio:
			<NomeVariabile:Stringa> <TipoVariabile:Char> <ValoreVariabile>

		Input
			fn: nome del file di configurazione
			P: indirizzo di una struttura "Parametri"

		Output
			Codice di errore come da enum Status
				0: OK
				1: KO
	*/
	FILE* fp = NULL;
	int err;
	char Key[64];
	char VarType;
	char FormatStr[8];

	err = fopen_s(&fp, fn, "r");
	if (!err)
	{
		while (fscanf_s(fp, "%s %c", Key, _countof(Key), &VarType) != EOF) /* Osservare l'utilizzo dello spazio per facilitare il compito alla fscanf_s e l'utilizzo di _countof() */
		{
			/* In base al carattere indicante il tipo si prepara FormatStr di conseguenza */
			if (VarType == 'i')
				strcpy_s(FormatStr, _countof(FormatStr), "%d");
			else if (VarType == 'f')
				strcpy_s(FormatStr, _countof(FormatStr), "%f");
			else if (VarType == 's')
				strcpy_s(FormatStr, _countof(FormatStr), "%s");
			else
				return KO; /* In questa funzione si fa restituire direttamente il valore KO in caso di errore. Non si utilizza quindi la variabile err */

			/* La fscanf_s successiva viene effettuata solo se la chiave (nome della variabile) e' riconosciuta 
				Osservare l'uso dell'operatore freccia (paragrafo 10.4 Deitel per approfondimenti)
				In breve, P->ID equivale a (*P).ID
			*/
			if (strcmp(Key, "ID") == 0)
				fscanf_s(fp, FormatStr, &P->ID);
			else if (strcmp(Key, "Note") == 0)
				fscanf_s(fp, FormatStr, P->Note, _countof(P->Note));
			else if (strcmp(Key, "Val") == 0)
				fscanf_s(fp, FormatStr, &P->Val);

		}

		fclose(fp);
	}
	else
		return KO;

	return OK;
}

void StampaParametri(const Parametri P)
{
	printf("%-20s%-20d\n", "ID", P.ID);
	printf("%-20s%-20s\n", "Note", P.Note);
	printf("%-20s%-20f\n", "Val", P.Val);
}