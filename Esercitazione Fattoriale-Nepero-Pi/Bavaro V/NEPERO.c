/*CALCOLO NUMERO DI NEPERO CON APPROSSIMAZIONE AL NUMERO INSERITO DALL'UTENTE*/
/*BAVARO VITO A-L*/

#include<stdio.h>
int main() {
	int appro; /*NUMERO DI APPROSSIMAZIONI DA ESEGUIRE*/
	unsigned contatore;
	int fattoriale;
	float e;
	int n; /*NUMERO UTILE PER L'IMPLEMENTAZIONE DELLA FORMULA*/
	
	contatore = 0;
	fattoriale = 1;
	e = 1;
	n = 1;

	printf("CALCOLO DEL NUMERO DI NEPERO\n");
	printf("Inserisci il numero di approssimazioni da eseguire: ");
	scanf_s("%d", &appro); /*INSERISCI IL NUMERO DI APPROSSIMAZIONI DA ESEGUIRE*/
	
	while (contatore != appro) { /*CICLA FINCHE IL CONTATORE NON E' PARI AL NUMERO DI APPROSSIMAZIONI*/
		fattoriale = n * fattoriale; /*CACOLA IL FATTORIALE DA INSERIRE AL DENOMINATORE DELLA FORMULA*/
		n += 1; /*INCREMENTA N (INIZIALIZZATA A 1)*/
		e = e + (1 / (float)fattoriale); /*APPLICA LA FORMULA (CASTING)*/
		contatore += 1; /*INCREMENTA IL FATTORIALE*/
		printf("%f\n", e);
	}
	
	printf("Il numero di nepero approssimato e': ");
	printf("%f\n", e); /*STAMPA e (NUMERO DI NEPERO) APPROSSIMATO*/
	return 0;
}