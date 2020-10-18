/*
programma che calcola la formula di leibniz con iterazioni scelte dall'utente
*/

#include <stdio.h>

int main() {
	//inizializzo a meno uno per far scattare il controllo
	int iterazioni = -1;
	int n = 0;
	float formula = 0;

	//controllo sull'input dell'utente
	while (iterazioni < 0) {
		printf("Quante iterazioni deve fare il programma? ");
		scanf_s("%d", &iterazioni);
	}

	while (n != iterazioni) {
		//dichiaro una varibile che mi serve solo in questo ciclo
		int uno = 0;
		//controllo se il numero uno deve essere positivo o negativo
		if (n % 2 == 0) {
			uno = 1;
		}
		else {
			uno = -1;
		}
		
		formula = formula + (float)uno / (2 * n + 1);
		n = n + 1;
	}

	printf("La formula di leibniz dopo %d iterazioni ammonta a %.10f", iterazioni, formula);
	return 0;
}