/*
	Programma per la scrittura di un file ad accesso sequenziale
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

	/* Apro il file e successivamente valuto se l'apertura e' andata a buon fine o meno*/
	fp = fopen("..\\clienti.dat", "w");

	if (fp != NULL)
	{
		/* La creazione del fine e' andata a buon fine */
		printf("Inserire Numero di conto, Nome e Saldo\n");
		printf("? ");
		scanf("%d%s%lf", &NumeroConto, Nome, &Saldo);

		/* Ciclo finche' non inserisco l'end-of-file da tastiera */
		/*
			Osservazione. 
			Con Visual Studio bisogna inserire 3 volte EOF
				CTRL + Z <enter> 
				CTRL + Z <enter> 
				CTRL + Z <enter>
			per terminare

			https://developercommunity.visualstudio.com/content/problem/227927/ctrl-z-input-in-debug-console-doesnt-generate-eof.html

			https://social.msdn.microsoft.com/Forums/vstudio/en-US/3c07e114-0b8f-45e8-8082-bf42ac1409ca/a-question-about-how-scanf-works?forum=vcgeneral
		*/
		while (!feof(stdin))
		{
			fprintf(fp, "%d %s %.2f\n", NumeroConto, Nome, Saldo);
			printf("? ");
			scanf("%d%s%lf", &NumeroConto, Nome, &Saldo);
		}

		fclose(fp);
	}
	else
		printf("Il file non puo' essere aperto/creato\n");

	return 0;
}