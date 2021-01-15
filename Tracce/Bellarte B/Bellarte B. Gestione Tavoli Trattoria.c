// Prima data dell'esonero
// Programma per la gestione di una trattoria

#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int tavolo4Persone; // tavoli da 4 persone occupati
	unsigned int tavolo6Persone; // tavoli da 6 persone occupati
	unsigned int persone;
	unsigned int tavolo;
	unsigned int bambini;
	unsigned int sceltaMenu;
	int menu[3] = { 15, 25, 30 };
	unsigned int sceltaExtra = 1;
	float extra[5] = {0.0, 1.5, 3.00, 4.00, 5.00 };
	int menuBambino[2] = { 10, 0 };
	float totaleExtra = 0;
	unsigned int sceltaMenuBambino;

	// disponibilita dei tavoli
	tavolo4Persone = rand() % 10;
	tavolo6Persone = rand() % 8;
	printf("Disponibilita' tavoli\n- Tavoli da 4 persone(max 10): %d\n- Tavoli da 6 persone(max 8): %d\n\n", tavolo4Persone, tavolo6Persone);

	// fase di prenotazione
	do {
		printf("Inserire il numero delle persone:\t");
		scanf_s("%u", &persone);
		printf("Inserire il numero dei bambini per il seggiolone:\t");
		scanf_s("%u", &bambini);
		if (persone + bambini >= 7) {
			printf("Errore in un tavolo possono sedere massimo 6 persone (dividere il gruppo in piu' prenotazioni)\n");
		}
	} while (persone + bambini >= 7);

	if (tavolo4Persone != 10 || tavolo6Persone != 8) {
		// prenotazione tavolo
		printf("1 - Tavolo con 4 posti a sedere\n2 - Tavoli con 6 posti a sedere\nEffettuare la propria scelta:\t");
		scanf_s("%u", &tavolo);
		if (tavolo == 1) {
			printf("Tavolo di 4 posti prenotato con successo\n");
			tavolo4Persone--;
		}
		if (tavolo == 2) {
			printf("Tavolo di 6 posti prenotato con successo\n");
			tavolo6Persone--;
		}
		// scelta menu bambini
		do {
			printf("Menu per i bambini?Euro 10/coperto\t1 - SI\t2 - NO\n");
			scanf_s("%u", &sceltaMenuBambino);
		} while (sceltaMenuBambino != 1 && sceltaMenuBambino != 2);
		// scelta menu adulti
		do {
			printf("MENU':\n");
			printf("1 - Antipasto + primo: Euro 15/coperto\n");
			printf("2 - Antipasto + primo + secondo: Euro 25/coperto\n");
			printf("3 - Antipasto + primo + secondo + dolce: Euro 30/coperto\n");
			scanf_s("%u", &sceltaMenu);
		} while (sceltaMenu >= 4);
		// scelta di prodotti extra
		while (sceltaExtra != 0) {
			do {
				printf("EXTRA':\n");
				printf("0 - No grazie!\n");
				printf("1 - Acqua\n");
				printf("2 - Birra\n");
				printf("3 - Vino della casa\n");
				printf("4 - Dolce\n");
				scanf_s("%u", &sceltaExtra);
				totaleExtra += extra[sceltaExtra];
			} while (sceltaExtra >= 5);
		}
		// calcolo del totale
		float totale = (menu[sceltaMenu - 1] * persone) + totaleExtra + (bambini * menu[sceltaMenuBambino - 1]);
		printf("Il totale complessivo e' di %.2f euro", totale);
	}
	else {
		printf("Siamo spiacenti non e' possibile prenotare alcun tavolo. Locale pieno!");
	}
	return 0;
}
