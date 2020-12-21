/*
	Programma per valutare i vari modi di aprire un file
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Dichiarazione delle variabili utili */
	int i, j;
	int cnt;
	int found555;
	FILE* fpW, * fpR, * fpA;

	/* Apro il file in vari modi e valuto cosa succede */
	
	/* Inizio con la scrittura */
	fpW = fopen("..\\EsempioW.txt", "w");

	if (fpW != NULL)
	{
		for(i=0; i<2; i++)
			for(j=0;j<2;j++)
				fprintf(fpW, "%d %d\n", i, j);
		fclose(fpW);
	}
	else
		printf("Il file non puo' essere aperto\n");

	/* Leggo il file appena scritto, ma un intero alla volta */
	printf("ESEMPIO DI LETTURA ERRATA DA FILE\n");
	
	fpR = fopen("..\\EsempioW.txt", "r");
	if (fpR != NULL)
	{
		cnt = 0;
		while (!feof(fpR))
		{
			fscanf(fpR, "%d", &i);
			printf("Numero %d - %d\n", ++cnt, i);
		}
		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");
	
	/* Osservo che la printf ha stampato due volte l'ultimo numero 
		Questo e' dovuto all'ordine con cui sono state scritte le istruzioni
		e al comportamento della fscanf. Infatti, nell'ordine del blocco precedente,
		succede che l'ultima fscanf restituisce EOF lasciando inalterato il valore della
		variabile i, che viene stampata un'ultima volta dalla printf.

		In seguito si presentano due modi di ovviare al problema
	*/

	/* Modo 1: fscanf esplicita fuori dal ciclo e immediatamente prima del controllo della condizione di ciclo */
	printf("\nESEMPIO DI LETTURA CORRETTA. MODO 1.\n");
	fpR = fopen("..\\EsempioW.txt", "r");
	if (fpR != NULL)
	{
		cnt = 0;
		fscanf(fpR, "%d", &i);
		while (!feof(fpR))
		{
			printf("Numero %d - %d\n", ++cnt, i);
			fscanf(fpR, "%d", &i);
		}
		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");

	/* Modo 2: Verifica esplicita del valore di ritorno di fscanf */
	printf("\nESEMPIO DI LETTURA CORRETTA. MODO 2.\n");
	fpR = fopen("..\\EsempioW.txt", "r");
	if (fpR != NULL)
	{
		cnt = 0;
		while (fscanf(fpR, "%d", &i) != EOF)
			printf("Numero %d - %d\n", ++cnt, i);
			
		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");

	/* Riapro in scrittura. Questa modalita' distrugge il contenuto presente */
	fpW = fopen("..\\EsempioW.txt", "w");
	fclose(fpW);

	printf("\nLETTURA DEL FILE EsempioW.txt immediatamente dopo un'apertura in modalita' \"w\"\n");
	fpR = fopen("..\\EsempioW.txt", "r");
	if (fpR != NULL)
	{
		cnt = 0;
		while (fscanf(fpR, "%d", &i) != EOF)
			printf("Numero %d - %d\n", ++cnt, i);

		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");

	/* Apro un file in modalita' append */
	fpA = fopen("..\\EsempioA.txt", "a+");

	if (fpA != NULL)
	{
		for (i = 0; i < 10; i++)
			fprintf(fpA, "%d\n", i);
		fclose(fpA);
	}
	else
		printf("Il file non puo' essere aperto\n");

	/* Riapro una seconda volta il file in modalita' append */
	fpA = fopen("..\\EsempioA.txt", "a+");

	if (fpA != NULL)
	{
		for (i = 0; i < 10; i++)
			fprintf(fpA, "%d\n", i);
		fclose(fpA);
	}
	else
		printf("Il file non puo' essere aperto\n");

	printf("\nLETTURA DEL FILE EsempioA.txt\n");
	fpR = fopen("..\\EsempioA.txt", "a+");
	if (fpR != NULL)
	{
		cnt = 0;
		while (fscanf(fpR, "%d", &i) != EOF)
			printf("Numero %d - %d\n", ++cnt, i);

		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");

	/*
		http://www.cplusplus.com/reference/cstdio/fopen/

		For files open for update (those which include a "+" sign), on which both input and output 
		operations are allowed, the stream shall be flushed (fflush) or repositioned (fseek, fsetpos, 
		rewind) before a reading operation that follows a writing operation. The stream shall be 
		repositioned (fseek, fsetpos, rewind) before a writing operation that follows a reading operation 
		(whenever that operation did not reach the end-of-file).
	*/
	fpA = fopen("..\\EsempioA.txt", "a+");
	if (fpA != NULL)
	{
		fscanf(fpA, "%d %d", &i, &j);
		printf("Lettura dei numeri %d e %d dal file EsempioA.txt\n", i, j);
		fprintf(fpA, "\n555\n");
		fclose(fpA);
	}
	else
		printf("Il file non puo' essere aperto\n");

	printf("\nLETTURA DEL FILE EsempioA.txt alla ricerca di 555\n");
	fpR = fopen("..\\EsempioA.txt", "a+");
	if (fpR != NULL)
	{
		cnt = 0;
		found555 = 0;
		while (fscanf(fpR, "%d", &i) != EOF)
		{
			if (i == 555)
			{
				printf("Trovato il numero %d alla riga %d\n", i, cnt);
				found555 = 1;
			}
			cnt++;
		}
		if(!found555)
			printf("Numero 555 non trovato!\n");
		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");

	fpA = fopen("..\\EsempioA.txt", "a+");
	if (fpA != NULL)
	{
		fscanf(fpA, "%d %d", &i, &j);
		printf("Lettura dei numeri %d e %d dal file EsempioA.txt\n", i, j);
		/* The stream shall be repositioned (fseek, fsetpos, rewind) before a writing 
		operation that follows a reading operation (whenever that operation did not reach the end-of-file).*/
		fseek(fpA, 0, SEEK_END);
		fprintf(fpA, "\n555\n");
		fclose(fpA);
	}
	else
		printf("Il file non puo' essere aperto\n");

	printf("\nLETTURA DEL FILE EsempioA.txt alla ricerca di 555\n");
	fpR = fopen("..\\EsempioA.txt", "a+");
	if (fpR != NULL)
	{
		cnt = 0;
		found555 = 0;
		while (fscanf(fpR, "%d", &i) != EOF)
		{
			if (i == 555)
			{
				printf("Trovato il numero %d alla riga %d\n", i, cnt);
				found555 = 1;
			}
			cnt++;
		}
		if (!found555)
			printf("Numero 555 non trovato!\n");
		fclose(fpR);
	}
	else
		printf("Il file non puo' essere aperto\n");

	return 0;
}