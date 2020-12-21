/*
	Programma per la lettura di un file ad accesso sequenziale
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Dichiarazione delle variabili utili */
	int NumeroConto;
	char Nome[32];
	double Saldo;

	FILE* fp;

	/* Apro il file e successivamente valuto se l'apertura e' andata a buon fine o meno */
	fp = fopen("..\\clienti.dat", "r");

	if (fp != NULL)
	{
		/* La apertura del file e' andata a buon fine */
		printf("%20s%20s%20s\n", "Numero di conto", "Nome", "Saldo");
		fscanf(fp, "%d%s%lf", &NumeroConto, Nome, &Saldo);

		/* Ciclo finche' non inserisco l'end-of-file da tastiera */
		while (!feof(fp))
		{
			printf("%20d%20s%20.2f\n", NumeroConto, Nome, Saldo);
			fscanf(fp, "%d%s%lf", &NumeroConto, Nome, &Saldo);
		}

		fclose(fp);
	}
	else
		printf("Il file non puo' essere aperto/creato\n");

	return 0;

}