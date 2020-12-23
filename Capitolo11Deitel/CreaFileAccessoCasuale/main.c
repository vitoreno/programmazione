/*
	Programma per la creazione di un file ad accesso casuale
	Scrittura di un numero intero nel file e valutazione del risultato.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE * fpO, * fpI; /* Puntatori a file (fpO per output, fpI per input) */
	int i; /* Contatore */
	int num = 1234567; /* Numero intero da scrivere sul file e da leggere */
	unsigned char* pNum; /* Puntatore per leggere i singoli byte */
	unsigned char ByteNum[4]; /* Array di 4 byte in cui leggere l'intero da file, byte per byte */

	/* Apertura di EsempioBin in modalita' scrittura binaria 
		Osservazione: non e' stata specificata alcuna estensione di file.
	*/
	fpO = fopen("..\\EsempioBin", "wb");
	
	if (fpO != NULL)
	{
		/* Deposito la quantita' di byte con cui e' rappresentato un intero [sizeof(int)] 
			per una sola volta [1]
			leggendo a partire dall'indirizzo di num [&num]
			e scrivendo utilizzando il puntatore fpO
		*/
		fwrite(&num, sizeof(int), 1, fpO);
		fclose(fpO);
	}

	printf("Numero scritto in decimale: %d\n", num);
	printf("Byte scritti: ");

	pNum = &num; /* Inizializzo pNum con l'indirizzo di num */
	i = 4;
	while (i--)
		printf("%02x ", *pNum++); /* Stampo il valore dereferenziato di pNum [*pNum] con due cifre esadecimali e incremento il puntatore pNum */
	printf("\n");


	/* A questo punto e' possibile gia' aprire il file EsempioBin con un editor di testo.
		Si osserva di non aver ottenuto una rappresentazione leggibile in questo formato, come ci si aspettava.
		Aprendo lo stesso file con un altro editor (ad es. HxD - https://mh-nexus.de/en/hxd/ ) si puo' leggere la codifica in byte attesa.
	*/

	
	fpI = fopen("..\\EsempioBin", "rb");

	if (fpI != NULL)
	{
		fread(ByteNum, sizeof(unsigned char), 4, fpI);
		printf("Prima lettura\n");
		for (i = 0; i < 4; i++)
			printf("Byte %2d - %4d - %02x\n", i, ByteNum[i], ByteNum[i]);
		printf("\n");

		fseek(fpI, 0, SEEK_SET); /* Torno all'inizio del file */
		
		fread(ByteNum, sizeof(int), 1, fpI);
		printf("Seconda lettura\n");
		for (i = 0; i < 4; i++)
			printf("Byte %2d - %4d - %02x\n", i, ByteNum[i], ByteNum[i]);
		printf("\n");
		fclose(fpI);
	}

	/* Per esercizio leggere i 4 byte direttamente in una variabile intera per verificare che il numero sia quello atteso */

	return 0;
}