/*
programma che calcola la costante e secondo il numero di iterazioni stabilite dall'utente
*/

#include <stdio.h>

int main() {
	//inizializzo a meno uno per far scattare il controllo
	int iterazioni=-1;
	int n = 1;
	float fatt = 1;
	float e = 1;
	int i = 1;


	//controllo sull'input dell'utente
	while (iterazioni < 0) {
		printf("Quante iterazioni deve fare il programma? ");
		scanf_s("%d", &iterazioni);
	}

	while (i != iterazioni) {
		n = i;
		while (n != 0) {
			fatt = fatt * n;
			n = n - 1;
		}

		e = e + 1 / fatt;
		i = i + 1;
		fatt = 1;
	}

	printf("La costante e dopo %d iterazioni ammonta a %f", iterazioni, e);

	return 0;
}