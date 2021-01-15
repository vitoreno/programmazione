// Seconda data dell'esonero
// Programma per la gestione di una gara di ballo
#include<stdio.h>

int main ()
{
	unsigned int x;
	unsigned int y;
	float professionisti [10][3];	//inizializza ad un valore a caso per controllare se sono stati inseriti i voti dai giudici
	for (x = 0; x < 10; x++)
		for (y = 0; y < 3; y++)
			professionisti [x][y] = -1;
			
	float senior [18][3];	//inizializza ad un valore a caso per controllare se sono stati inseriti i voti dai giudici
	for (x = 0; x < 18; x++)
		for (y = 0; y < 3; y++)
			senior [x][y] = -1;
			
	float junior [7][3];	//inizializza ad un valore a caso per controllare se sono stati inseriti i voti dai giudici
	for (x = 0; x < 7; x++)
		for (y = 0; y < 3; y++)
			junior [x][y] = -1;
			
	float mediaVoti [35][2];	//inizializza ad un valore a caso per separare i voti effettivi dal resto che non verra considerato
	for (x = 0; x < 35; x++)
		for (y = 0; y < 2; y++)
			mediaVoti [x][y] = -1;
			
	unsigned int q = 0; // contatore di controllo che permette di sapere se sono stati inseriti i voti dall'utente
	unsigned int i;
	unsigned int j;
	unsigned int sceltaMenuIniziale;
	unsigned int cntProfessionisti = 0;	// contatore per non registrare piu' coppie in una categoria
	unsigned int cntSenior = 0;	// contatore per non registrare piu' coppie in una categoria
	unsigned int cntJunior = 0;	// contatore per non registrare piu' coppie in una categoria
	unsigned int sceltaIscrizione;
	float incassoProfessionisti = 0;
	float incassoSenior = 0;
	float incassoJunior = 0;
	unsigned int somma = 0; // somma per la media
	float media = 0;
	float holdNumero;	// variabile temporanea per salvare il numero in gara di una coppia dell'array mediaVoti per ordinarlo e stampare la classifica
	float holdMedia;	// variabile temporanea per salvare il media dei voti di una coppia dell'array mediaVoti per ordinarlo e stampare la classifica
	
	// stampa menu iniziale
	printf("0 - Termina programma\n");
	printf("1 - Iscrizione gara\n");
	printf("2 - Assegnazione dei voti\n");
	printf("3 - Numero di coppie in gara\n");
	printf("4 - Classifica della gara\n");
	printf("5 - Incasso della serata\n");
	do {
		printf("Effettuare una scelta:\t");
		scanf("%u", &sceltaMenuIniziale);
	} while (sceltaMenuIniziale >= 6);
	
	while (sceltaMenuIniziale != 0) {
		if (sceltaMenuIniziale == 1) {
			// menu per l'iscrizione in gara 
			printf("\n\nIscrizione gara\n");
			printf("0 - Termina iscrizione\n");
			printf("1 - Partecipanti professionisti\n");
			printf("2 - Partecipanti senior\n");
			printf("3 - Partecipanti junior\n");
			do {
				printf("Effettuare una scelta:\t");
				scanf("%u", &sceltaIscrizione);
			} while (sceltaIscrizione >= 4);
			
			while (sceltaIscrizione != 0) {	
			
				if (sceltaIscrizione == 1) {
					if (cntProfessionisti != 10) {
						// stampa delle informazioni sulla partecipazione di una coppia
						cntProfessionisti++;
						printf("\nPartecipazione effettuata con successo:\n");
						printf("Classe: professionisti\n");
						printf("Costo: 25 euro a coppia\n");
						printf("Numero di gara: %d", cntProfessionisti);
						incassoProfessionisti += 25;	
					}
				}
				if (sceltaIscrizione == 2) {
					if (cntSenior != 18) {
						cntSenior++;
						printf("\nPartecipazione effettuata con successo:\n");
						printf("Classe: senior\n");
						printf("Costo: 15 euro a coppia\n");
						printf("Numero di gara: %d", cntSenior+10);
						incassoSenior += 15;	
					}
				}
				if (sceltaIscrizione == 3) {
					if (cntJunior != 7) {
						cntJunior++;
						printf("\nPartecipazione effettuata con successo:\n");
						printf("Classe: junior\n");
						printf("Costo: 5 euro a coppia\n");
						printf("Numero di gara: %d", cntJunior+28);
						incassoJunior += 5;	
					}
				}
				printf("\n\nIscrizione gara\n");
				printf("0 - Termina iscrizione\n");
				printf("1 - Partecipanti professionisti\n");
				printf("2 - Partecipanti senior\n");
				printf("3 - Partecipanti junior\n");
				do {
					printf("Effettuare una scelta:\t");
					scanf("%u", &sceltaIscrizione);
				} while (sceltaIscrizione >= 4);
			}
		}
		if (sceltaMenuIniziale == 2) {
			// assegnazione dei voti a tutte le coppie in gara da parte dei giudici
			printf("\n\nAssegnazione dei voti\nCategoria professionisti\n(digitare 0 per astenersi dal voto)\n\n");
			for (i = 0; i < cntProfessionisti; i++) {
				for (j = 0; j < 3; j++) {
					do {
						printf("Giudice %u\tInserire voto coppia %u:\t", j+1, i+1);
						scanf("%f", &professionisti[i][j]);
					} while (professionisti[i][j] >= 11);
					somma += professionisti[i][j]; // somma i voti per la media
				}	
				printf("\n");
				mediaVoti[i][0] = i; // salva il numero della coppia
				mediaVoti[i][1] = (float) somma / 3;
				somma = 0;
			}
			printf("\n\nAssegnazione dei voti\nCategoria senior\n(digitare 0 per astenersi dal voto)\n\n");
			for (i = 0; i < cntSenior; i++) {
				for (j = 0; j < 3; j++) {
					do {
						printf("Giudice %u\tInserire voto coppia %u:\t", j+1, i + 10);
						scanf("%f", &senior[i][j]);
					} while (senior[i][j] >= 11);
					somma += senior[i][j];	// somma i voti per la media
				}	
				printf("\n");
				mediaVoti[i+10][0] = i+10;	// salva il numero della coppia
				mediaVoti[i+10][1] = (float) somma / 3;
				somma = 0;
			}
			printf("\n\nAssegnazione dei voti\nCategoria junior\n(digitare 0 per astenersi dal voto)\n\n");
			for (i = 0; i < cntJunior; i++) {
				for (j = 0; j < 3; j++) {
					do {
						printf("Giudice %u\tInserire voto coppia %u:\t", j+1, i + 28);
						scanf("%f", &junior[i][j]);
					} while (junior[i][j] >= 11);
					somma += junior[i][j];	// somma i voti per la media
				}	
				printf("\n");
				mediaVoti[i + 28][0] = i+28;	// salva il numero della coppia
				mediaVoti[i+28][1] = (float) somma / 3;
				somma = 0;
			}	
		}
		if (sceltaMenuIniziale == 3) {
			// riepilogo delle coppie iscritte alla gara
			printf("\n\nNumero di coppie in gara\n");
			printf("Categoria professionisti: %u\n", cntProfessionisti);
			printf("Categoria senior: %u\n", cntSenior);
			printf("Categoria junior: %u\n", cntJunior);
		}
		if (sceltaMenuIniziale == 4) {
			// stampa la classifica e definisce il podio dei vincitori della gara con annesso la media
			printf("\n\nClassifica della gara\n");
			
			for(j = 0; j < 35; j++) {
				for(i = 0; i < 2; i++) {
					if (mediaVoti[i][j] == -1) {
						q++;
					}
				}
			}
			if(q != 70) {
				for(j = 1; j < 35; j++) {
					for(i = 0; i < 34; i++) {
						if (mediaVoti[i][1] < mediaVoti[i + 1][1]) {
							holdNumero = mediaVoti[i][0];
							holdMedia = mediaVoti[i][1];
							mediaVoti[i][0] = mediaVoti[i + 1][0];
							mediaVoti[i][1] = mediaVoti[i + 1][1];
							mediaVoti[i + 1][0] = holdNumero;
							mediaVoti[i + 1][1] = holdMedia;
						}
					}
				}
				printf("Posizione      Coppia      Punteggio\n");
				for(i = 0; i < 34; i++) {
					if (mediaVoti[i][1] != -1){
						printf("#%8u%12.0f%15.2f\n", i + 1, mediaVoti[i][0] + 1, mediaVoti[i][1]);
					}
					if (i == 2) {
						printf("\n");
					}
				}
			} else
				printf("\nClassifica non disponibile. Assegnare i voti ai partecipanti\n");
		}
		
		if (sceltaMenuIniziale == 5) {
			// stampa l'incasso totale per ciascuna categoria e l'incasso totale della serata
			printf("\n\nIncasso della serata\n");
			printf("Incasso partecipanti categoria professionisti: %.2f euro\n", incassoProfessionisti);
			printf("Incasso partecipanti categoria senior: %.2f euro\n", incassoSenior);
			printf("Incasso partecipanti categoria junior: %.2f euro\n", incassoJunior);
			printf("Incasso totale: %.2f euro\n\n", incassoProfessionisti + incassoSenior + incassoJunior);
		}
		// ripete il ciclo finche non si digita 0 per terminare il programma
		printf("\n\n0 - Termina programma\n");
		printf("1 - Iscrizione gara\n");
		printf("2 - Assegnazione dei voti\n");
		printf("3 - Numero di coppie in gara\n");
		printf("4 - Classifica della gara\n");
		printf("5 - Incasso della serata\n");
		do {
			printf("Effettuare una scelta:\t");
			scanf("%u", &sceltaMenuIniziale);
		} while (sceltaMenuIniziale >= 6);	
	}
	return 0;	
}
