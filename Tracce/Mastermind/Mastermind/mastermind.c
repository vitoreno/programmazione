#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L_CODICE 4
#define N_TENTATIVI 9

enum ErrorCodes {OK, KO, WRONG_INPUT};

int mastermind(int Stats[]);
int CaricaSequenza(int C[], const int ContaPartite);
int Gioca(const int T[], int* Vittoria, int* NumeroMosse);
int Statistiche(const int Giocate, const int Vinte, const int MinMosse);

int main()
{
	char username[64];
	int giocaAncora = 1;
	int ErrCode = OK;
	int Stats[2] = { 0, N_TENTATIVI + 1 };

	printf("MASTERMIND a riga di comando\n");
	printf("----------------------------\n");
	printf("Inserire username: ");
	scanf(" %s", username);

	while (giocaAncora)
	{
		ErrCode = mastermind(Stats);
		
		if (ErrCode != OK)
			return ErrCode;

		printf("Giocare un'altra partita? [1 SI / 0 NO]: ");
		scanf("%d", &giocaAncora);
	}

	return OK;
}

int mastermind(int Stats[])
{
	static int ContaPartite = 1;

	int ErrCode;
	int Codice[L_CODICE];

	ErrCode = CaricaSequenza(Codice, ContaPartite);
	ErrCode = Gioca(Codice, &Stats[0], &Stats[1]);
	ErrCode = Statistiche(ContaPartite, Stats[0], Stats[1]);

	ContaPartite++;
	return OK;
}

int CaricaSequenza(int C[], const int ContaPartite)
{

	FILE* fp;
	int fermati = 0;
	int i = 0;

	if (ContaPartite == 1)
	{
		fp = fopen("Sequenza.txt", "r");
	
		if (fp != NULL)
		{
			for (i = 0; i < L_CODICE && !fermati && !feof(fp); i++)
			{
				fscanf(fp, "%d", &C[i]);
				fermati = (C[i] < 0) || (C[i] > 9) ? WRONG_INPUT : OK;
			}

			fclose(fp);
		}
	}
	
	if (i != L_CODICE || fermati == WRONG_INPUT)
		for (i = 0; i < L_CODICE; i++)
			C[i] = rand() % 10;

	return OK;
}

int Gioca(const int CodiceRiferimento[], int* Vittoria, int* NumeroMosse)
{
	int CodiceUtente[L_CODICE];
	int ContaTentativi = 0;
	int i, j, ch;
	int status = WRONG_INPUT;
	int SiGioca = 1;
	*Vittoria = 0;
	int N, B;
	int VerificaCifre[10][2] = { 0 };

	while (SiGioca)
	{
		status = WRONG_INPUT;
		while (status != OK)
		{
			status = OK;
			printf("Inserire il codice di %d cifre comprese tra 0 e 9: ", L_CODICE);
			for (i = 0; i < L_CODICE && status == OK; i++)
			{
				scanf("%d", &CodiceUtente[i]);
				if (CodiceUtente[i] < 0 || CodiceUtente[i] > 9)
				{
					status = WRONG_INPUT;
					while ((ch = getchar()) != '\n' && ch != EOF);
				}
			}

			if (status == WRONG_INPUT)
				printf("E' stato inserito almeno un numero non compreso tra 0 e 9. L'operazione sara' ripetuta\n\n");
		}

		N = 0;
		B = 0;
		memset(VerificaCifre, 0, 20 * sizeof(int));
		for (i = 0; i < L_CODICE; i++)
		{
			VerificaCifre[CodiceRiferimento[i]][0]++;
			VerificaCifre[CodiceUtente[i]][1]++;
		}

		for (i = 0; i < L_CODICE; i++)
			if (CodiceUtente[i] == CodiceRiferimento[i])
			{
				VerificaCifre[CodiceRiferimento[i]][0]--;
				VerificaCifre[CodiceUtente[i]][1]--;
				N++;
			}

		for (i = 0; i < 10; i++)
			if (VerificaCifre[i][0] > 0 && VerificaCifre[i][1] > 0)
				B += VerificaCifre[i][1];

		printf("Ci sono %d cifre esatte al posto esatto e %d cifre esatte al posto sbagliato\n", N, B);

		if (++ContaTentativi == N_TENTATIVI)
			SiGioca = 0;
		
		if(N == L_CODICE)
		{
			*Vittoria = 1;
			*NumeroMosse = min(*NumeroMosse, ContaTentativi);
			SiGioca = 0;
		}
	}
	
	return OK;
}

int Statistiche(const int Giocate, const int Vinte, const int MinMosse)
{
	printf("Statistiche di Mastermind\n");
	printf("Numero di partite giocate: %d\n", Giocate);
	printf("Numero di partite vinte: %d\n", Vinte);
	if(Vinte > 0)
		printf("Numero minimo di mosse per la vittoria: %d\n", MinMosse);

	return OK;
}