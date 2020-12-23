/*
	Esempio di utilizzo di struct con i file binari.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NDATA 4096

typedef struct Record_
{
	unsigned int ID;
	char Etichetta[9];
	float Valore;
} Record;

Record GeneraRecord();
void StampaRecord(const Record * R, int idx);

int main()
{
	FILE* fpO, * fpI; /* Puntatori a file per I/O*/
	Record Data[NDATA]; /* I dati sono un array di Record */
	Record DataRead[NDATA]; /* Secondo array in cui leggere i contenuti depositati sul file */
	int i, idx; /* Contatori */

	/* Inizializzazione casuale dei dati */
	for (i = 0; i < NDATA; i++)
		Data[i] = GeneraRecord();
	
	fpO = fopen("..\\Data.rec", "wb");
	if (fpO != NULL)
	{
		fwrite(Data, sizeof(Record), NDATA, fpO);
		printf("Scritti %d byte sul file %s\n", sizeof(Record) * NDATA, "..\\Data.rec");
		fclose(fpO);
	}

	fpI = fopen("..\\Data.rec", "rb");
	if (fpI != NULL)
	{
		fread(DataRead, sizeof(Record), NDATA, fpI);
		printf("Letti %d byte dal file %s\n", sizeof(Record) * NDATA, "..\\Data.rec");
		fclose(fpI);
	}

	for (i = 0; i < NDATA; i++)
		if (Data[i].ID != DataRead[i].ID || strcmp(Data[i].Etichetta, DataRead[i].Etichetta) != 0 || Data[i].Valore != DataRead[i].Valore)
			printf("Trovato record %d-esimo non corrispondente!\n", i);

	for (i = 0; i < 10; i++)
		StampaRecord(Data, rand() % NDATA);

	return 0;
}

Record GeneraRecord()
{
	static int LastID = 100;
	const int COMBINAZIONI = 126 - 33 + 1;
	int i;
	Record rec;

	rec.ID = LastID++;
	/* da 33 a 126 */
	for (i = 0; i < 8; i++)
		rec.Etichetta[i] = (rand() % COMBINAZIONI)+33;
	rec.Etichetta[8] = '\0';

	rec.Valore = rand() / 10.0f;

	return rec;
}

void StampaRecord(const Record* R, int idx)
{
	printf("*****************\n");
	printf("Record %4d-esimo\n", idx);
	printf("%-15s - %4d\n", "ID", R[idx].ID);
	printf("%-15s - %s\n", "Etichetta", R[idx].Etichetta);
	printf("%-15s - %.2f\n", "Valore", R[idx].Valore);
	printf("*****************\n");
}