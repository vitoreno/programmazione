
/*IMPLEMENTAZIONE DI UNA SLOT MACHINE. VITO BAVARO */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll(); //prototipo funzione generazione numeri random da 1 a 7

int main() {

	srand(time(NULL)); 

	int money=0; //variabile dei "soldi" da inserire
	int continua = 1; //variabile per riprovare il gioco
	int menu; //variabile per il menu di gioco
	printf("$$ SLOT MACHINE $$\n");
	puts("");
	printf("-[BENVENUTO]-\n");
    puts("");
	do { 
		printf("-[MENU DI GIOCO]-\n");
		puts("");
		printf("Il tuo CREDITO attuale e' di [%d] Euro\n", money); //visualizzazione credito attuale
		puts("");
		printf("-[0]:Carica Credito\n-[1]:Inizia a Giocare\n-[2]:Esci dal Gioco\n\nRisposta: "); //opzioni del menu di gioco
		scanf_s("%d", &menu); //inserire l'opzione del menu scelta
		system("cls"); //pulizia console
		switch (menu) { //ciclo per le varie opzioni di menu
		case 0: //caso per la ricarica del credito
			puts("");
			printf("-[RICARICA CREDITO]-\n");
			puts("");
			printf("Insersci quanti Soldi vuoi Caricare. (1 Giro = 1 Euro): ");
			scanf_s("%d", &money); //inserire la cifra da ricaricare sul conto 
			puts("");
			printf("Transazione avvenuta con successo...\n");
			puts("");
			system("PAUSE"); 
			system("cls"); //pulizia console
			break; //uscita dal ciclo
		case 1: //caso per l'inizio della partita 
			if (money != 0) { //se il credito è diverso da 0 allora si puo iniziare a giocare 
				do {
					money--; //viene sottratto un "euro" dal conto dell'utente pari al costo di un giro 
					puts("");
					printf("-[GIOCO AVVIATO]-\n");
					puts("");
					printf("Prelevo credito...\n");
					puts("");
					printf("Il tuo CREDITO ora e' di: [%d] Euro\n", money); //viene visulizzato nuovamente il conto dell'utente dopo il prelevo del costo 
					puts("");
					printf("$$ BUONA FORTUNA $$\n");
					int a = 1 + (rand() % 7); //generazione di un numero random da 1 a 7
					int b = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int c = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int d = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int e = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int f = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int g = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int h = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					int j = 1 + (rand() % 7);//generazione di un numero random da 1 a 7
					system("PAUSE");

					for (int i = 1; i <= 50; i++) { //ciclo puramente estetico per simulare una slot machine 
						printf("_______________\n");
						printf("||$$RESULTS$$||\n");
						printf("||%3s%3s%3s  ||\n", "+", "+", "+");
						printf("||%3d|%2d|%2d  ||\n", roll(), roll(), roll());
						printf("||%3d|%2d|%2d  ||\n", roll(), roll(), roll());
						printf("||%3d|%2d|%2d  ||\n", roll(), roll(), roll());
						printf("||===========||\n");
						system("cls");
					}
					printf("_______________\n"); //stampa dell griglia dove verranno visualizzati i  numeri random generati
					printf("||$$RESULTS$$||\n");
					printf("||%3s%3s%3s  ||\n", "+", "+", "+");
					printf("||%3d|%2d|%2d  ||\n", a, b, c);
					printf("||%3d|%2d|%2d  ||\n", d, e, f);
					printf("||%3d|%2d|%2d  ||\n", g, h, j);
					printf("||===========||\n");

					if (d == e && e == f) { //caso in cui tutti i numeri della riga centrale siano uguali
						if (d == 7) { //se i numeri sono uguali a 7 allora si è fatto jackpot
							puts("");
							printf("$$ JACKPOT $$\n");
							printf("$$$$$$$$$$$$$\n");
							puts("");
							money = money * 4; //i soldi vengono quadruplicati 
							printf("Il tuo CREDITO ora e di: [%d] Euro\n", money); //stampa del conto attuale
							puts("");
							printf("VUOI RIPROVARE?\n-[1]Si\n-[0]No\nRisposta: "); //viene chiesto se si vuole giocare ancora
							scanf_s("%d", &continua); //risposta dell'utente 
						}
						else { //se i numeri sono uguali ma diversi da 7
							puts("");
							printf("$$ HAI VINTO $$\n");
							printf("Combo Riga Centrale\n");
							puts("");
							money = money * 2; //i soldi vengono raddoppiati 
							printf("Il tuo CREDITO ora e di: [%d] Euro\n", money);//stampa del conto attuale
							puts("");
							printf("VUOI RIPROVARE?\n-[1]Si\n-[0]No\nRisposta: ");//viene chiesto se si vuole giocare ancora
							scanf_s("%d", &continua);//risposta dell'utente 
						}
					}
					else if (b == e && e == h) { //caso in cui i numeri della colonna centrale siano tutti uguali
						puts("");
						printf("$$ HAI VINTO $$\n");
						printf("Combo Colonna Centrale\n");
						puts("");
						money = money * 2;//i soldi vengono raddoppiati 
						printf("Il tuo CREDITO ora e di: [%d] Euro\n", money);//stampa del conto attuale
						puts("");
						printf("VUOI RIPROVARE?\n-[1]Si\n-[0]No\nRisposta: ");//viene chiesto se si vuole giocare ancora
						scanf_s("%d", &continua);//risposta dell'utente
					}
					else if (a == e && e == j) {//caso in cui i numeri della diagonale di sinistra siano tutti uguali
						puts("");
						printf("$$ HAI VINTO $$\n");
						printf("Combo Diagonale Sinistra\n");
						puts("");
						money = money++;//il costo della giocata viene rimborsato
						printf("Il tuo CREDITO ora e di: [%d] Euro\n", money);//stampa del conto attuale
						puts("");
						printf("VUOI RIPROVARE?\n-[1]Si\n-[0]No\nRisposta: ");//viene chiesto se si vuole giocare ancora
						scanf_s("%d", &continua);//risposta dell'utente
					}
					else if (c == e && e == g) {//caso in cui i numeri della diagonale di destra siano tutti uguali
						puts("");
						printf("$$ HAI VINTO $$\n");
						printf("Combo Diagonale Destra\n");
						puts("");
						money = money++; // il costo della giocata viene rimborsato
						printf("Il tuo CREDITO ora e di: [%d] Euro\n", money);//stampa del conto attuale
						puts("");
						printf("VUOI RIPROVARE?\n-[1]Si\n-[0]No\nRisposta: ");//viene chiesto se si vuole giocare ancora
						scanf_s("%d", &continua);//risposta dell'utente
					}
					else { //caso in cui non e presente nessuna combo precedente
						puts("");
						printf("$$ HAI PERSO $$\n");
						puts("");
						puts("");
						printf("Credito rimanente: [%d] Euro.\n\nVUOI RIPROVARE?\n-[1]Si\n-[0]No\nRisposta: ", money);//viene chiesto se si vuole giocare ancora
						scanf_s("%d", &continua);//risposta dell'utente
					}

					system("cls");//pulizia della console


				} while (money != 0 && continua != 0);//ripete finchè il credito è sufficente o si sceglie di voler giocare ancora
				if (money == 0) { //se il credito è uguale a 0
					puts("");
					puts("");
					printf("Credito Terminato.\n"); //scrivere che il credito è terminato
					puts("");
				}
				else break; //uscita dal ciclo
				
			}
			else {//se il credito è pari a zero e si tenta di iniziare una partitia
				puts("");
				puts("");
				printf("-Credito INSUFFICENTE o NON INSERITO\n Prego inserire credito.\n"); //scrive che non c'è abbastanza credito
				puts(""); 
				puts("");
			}
			system("PAUSE");
			system("cls"); //pulizia console
			break;

		case 2: //caso in cui si voglia uscire dal gioco
			break;//uscita dal ciclo

		default://caso generale in cui venga inserita una opzione del menu non valida
			puts(""); 
			puts("");
			printf("-Opzione non valida. Prego riprovare\n"); //stampa che l'opzione non è valida
			puts("");
			puts("");
			system("PAUSE");
			system("cls"); //pulizia dellla console
			break;//uscita dal ciclo

		}
	}while (menu != 2); //ripete finchè l'opzione del menu scelta è diversa da 2
	
	puts("");
	puts("");
	printf("$$ CONGRATUALZIONI HAI VINTO %d EURO $$\n", money); //stampa finale del programma con la somma vinta 
	puts("");
	printf("  Grazie di aver Giocato\n  BUONA GIORNATA\n");
	puts("");
	puts("");
	system("PAUSE");
	return 0;
}

	

int roll(void) { //funzione per la generazione dei numeri da 1 a 7 
	int a = 1 + (rand() % 7);
	return a;
}




