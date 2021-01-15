#include<stdio.h>
#include<stdlib.h>

int main()
{	/// posti occupati che saranno modificati con un menu a scelta
	int tratte[7][2] = { {0, 0}, {0, 458}, {0, 266}, {0, 881}, {0, 226}, {0, 573}, {0, 772} };
	float costoTratte[7] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	int sceltaTratta;
	float totale;
	int sceltaMenuIniziale; // variabile per il menu delle varie opzioni
	int cntSconto = 0; //contatore sconti applicati raggiunti i 5 sconti non e piu possiile applicarne altri
	int numCasuale;
	float totaleIncassi = 0;
	int i = 0;

	srand(time(NULL));

	// ciclo per il calcolo del costo di ciascuna tratta
	// 0,07 euro per km per i primi 200 km i successivi invece 0.05 euro per km
	for (i = 1; i < 7; i++) {
		costoTratte[i] = (tratte[i][1] - 200) * 0.05 + (200 * 0.07);
	}
	// menu proncipale del programma
	printf("0 - Termina programma\n");
	printf("1 - Acquisto biglietto\n");
	printf("2 - Modifica posti occupati\n");
	printf("3 - Biglietti venduti e contatore bonus sconto\n");
	do {
		printf("Effettuare la scelta:\t");
		scanf_s("%u", &sceltaMenuIniziale);
	} while (sceltaMenuIniziale >= 4);

	while (sceltaMenuIniziale != 0) {
		if (sceltaMenuIniziale == 1) { // sezione per l'acquisto del bigliotto per una tratta
			printf("\n\nAcquisto biglietto:\n");
			printf("1 - Bari - Roma 458 km\n");
			printf("2 - Bari - Napoli 266 km\n");
			printf("3 - Bari - Milano 881 km\n");
			printf("4 - Roma - Napoli 226 km\n");
			printf("5 - Roma - Milano 573 km\n");
			printf("6 - Napoli - Milano 772 km\n");
			do {
				printf("Effettuare la propria scelta:\t");
				scanf_s("%u", &sceltaTratta);
			} while (sceltaTratta == 0 || sceltaTratta >= 7);

			if (tratte[sceltaTratta][0] != 25) { // se la tratta non supera le 25 persone (cioe' posti non disponibili) stampa il biglietto
				tratte[sceltaTratta][0]++;	// incremeta i posti occupati per una determinata tratta

				// stampa della biglietto
				printf("\n\n");
				printf("Partenza: ");
				if (sceltaTratta == 1) {
					printf("Bari\nArrivo: Roma\n");
				}
				if (sceltaTratta == 2) {
					printf("Bari\nArrivo: Napoli\n");
				}
				if (sceltaTratta == 3) {
					printf("Bari\nArrivo: Milano\n");
				}
				if (sceltaTratta == 4) {
					printf("Roma\nArrivo: Napoli\n");
				}
				if (sceltaTratta == 5) {
					printf("Roma\nArrivo: Milano\n");
				}
				if (sceltaTratta == 6) {
					printf("Napoli\nArrivo: Milano\n");
				}
				printf("Chilometri da percorrere: %d km\n", tratte[sceltaTratta][1]);
				printf("Costo biglietto: %.2f\n", costoTratte[sceltaTratta]);
				totale = costoTratte[sceltaTratta];
				printf("Applicazione bonus (-2 percento sul costo del biglietto): ");
				if (cntSconto = rand() % 5 != 5) {	// controlla quanti sconti sono stati applicati
					if (numCasuale = rand() % 100 == 5) {	// applicazione di uno sconto se il numero casuale e' uguale a 5
						totale = costoTratte[sceltaTratta] - ((totale * 2) / 100);
						totaleIncassi += totale;
						printf("Hai vinto il bonus!\n");	// stampa del totale con lo sconto vinto
						printf("TOTALE COMPLESSIVO: %.2f", totale);
						cntSconto++;
					}
					else {	// stampa del totale senza alcun sconto vinto
						printf("Non hai vinto il bonus!\n");
						printf("TOTALE COMPLESSIVO: %.2f", costoTratte[sceltaTratta]);
						totaleIncassi += costoTratte[sceltaTratta];
					}
				}
				printf("\n\n");
			}
			else
				printf("\nImpossibile acquistare il posto per quella tratta. Posti non disponibili.\n");
		}
		else if (sceltaMenuIniziale == 2) {	// permette di rimuovere o aggiungere persone
			printf("Modifica posti occupati:\n");
			for (i = 1; i < 7; i++) {
				if (i == 1) {
					do {
						printf("Bari - Roma\t");
						scanf_s("%d", &tratte[i][0]);
					} while (tratte[sceltaTratta][0] >= 26 && tratte[sceltaTratta][0] <= -1);
				}
				if (i == 2) {
					do {
						printf("Bari - Napoli\t");
						scanf_s("%d", &tratte[i][0]);
					} while (tratte[sceltaTratta][0] >= 26 && tratte[sceltaTratta][0] <= -1);
				}
				if (i == 3) {
					do {
						printf("Bari - Milano\t");
						scanf_s("%d", &tratte[i][0]);
					} while (tratte[sceltaTratta][0] >= 26 && tratte[sceltaTratta][0] <= -1);
				}
				if (i == 4) {
					do {
						printf("Roma - Napoli\t");
						scanf_s("%d", &tratte[i][0]);
					} while (tratte[sceltaTratta][0] >= 26 && tratte[sceltaTratta][0] <= -1);
				}
				if (i == 5) {
					do {
						printf("Roma - Milano\t");
						scanf_s("%d", &tratte[i][0]);
					} while (tratte[sceltaTratta][0] >= 26 && tratte[sceltaTratta][0] <= -1);
				}
				if (i == 6) {
					do {
						printf("Napoli - Milano\t");
						scanf_s("%d", &tratte[i][0]);
					} while (tratte[sceltaTratta][0] >= 26 && tratte[sceltaTratta][0] <= -1);
				}
			}
		}
		else if (sceltaMenuIniziale == 3) {
			// stampa che visualizza i biglietti venduti per ciascuna tratta e visualizza il contatore degli sconti applicati
			printf("Biglietti venduti e contatore bonus sconto\n");
			printf("1 - Bari - Roma 458 km\t\t%d\n", tratte[1][0]);
			printf("2 - Bari - Napoli 266 km\t%d\n", tratte[2][0]);
			printf("3 - Bari - Milano 881 km\t%d\n", tratte[3][0]);
			printf("4 - Roma - Napoli 226 km\t%d\n", tratte[4][0]);
			printf("5 - Roma - Milano 573 km\t%d\n", tratte[5][0]);
			printf("6 - Napoli - Milano 772 km\t%d\n", tratte[6][0]);
			printf("\nContatore bonus sconto:\t%u sconti applicati\n", cntSconto);
		}
		printf("\n\n0 - Termina programma\n");
		printf("1 - Acquisto biglietto\n");
		printf("2 - Modifica posti occupati\n");
		printf("3 - Biglietti venduti e contatore bonus sconto\n");
		do {
			printf("Effettuare la scelta:\t");
			scanf_s("%u", &sceltaMenuIniziale);
		} while (sceltaMenuIniziale >= 4);
	}
	return 0;
}
