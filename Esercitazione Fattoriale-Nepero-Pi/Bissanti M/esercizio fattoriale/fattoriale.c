/*
programma che calcola il fattoriale di un numero n inserito da tastiera
*/

#include <stdio.h>

int main() {
	int fattoriale = 1;
	int input = 0;
	//inizializzo a meno uno per far scattare il controllo
	int n=-1;

	//controllo sull'input dell'utente
	while (n<0) {
		printf("Inserire il numero per calcolare il fattoriale (non deve essere negativo): ");
		scanf_s("%d", &n);
	}

	//salvo il valore per utilizzarlo dopo
	input = n;

	//calcolo il fattoriale
	while (n != 0) {
		fattoriale = fattoriale * n;
		n = n - 1;
	}

	printf("Il fattoriale di %d ammonta a %d", input, fattoriale);

	return 0;
}