/*Obiettivo: valutare il valore della costante numerica e (numero di nepero) */

#include <stdio.h>

int main() {
	int n; // numero di iterazioni
	int fattoriale;
	int i, j; // contatore
	float nepero; // variabile che conterrà l'approssimazione del numero di nepero

	/*Inizializzazione variabili spiegazione:
	- Si decide di inizializzare a 1 il numero di nepero dato che la formula è 1 + 1/n! + ....
	- Si decide di inizializzare a 1 il fattoriale dato che può essere calcolato per numeri >= 1
	- Si decide di inizializzare a 1 i contatori perchè dato che il calcolo del fattoriale parte da 
	  valori >= di 1*/

	fattoriale = 1; 
	nepero = 1; 

	i = 1; 
	j = 1;
 
	printf("Inserire un numero compreso tra 1 e 8: ");
	scanf_s("%d", &n);	

	/* 
	Controllo della correttezza dell'input inserito dall'utente 
	(con l'utilizzo dell'operatore logico or || si potrebbe anche inserire il controllo relativo 
	ai numeri negativi.
	*/

	while (n > 8) {
		printf("Inserire un numero inferiore o uguale a 8: ");
		scanf_s("%d", &n);
	}

	while (i <= n)
	{
		/*Calcolo del fattoriale*/

		while (j < i)
		{
			if (j == 1)
				fattoriale = i * (i - j);
			else
				fattoriale *= (i - j);

			j++;

		}

		/*Stampa dei fattoriali calcolati*/
		
		printf("Fattoriale: %d -> %d \n", i, fattoriale);

		/*Calcolo del numero di nepero con la formula (nepero è già inizializzato a 1)*/

		nepero += (float) 1 / fattoriale;

		i++;
		j = 1; // riportare j a 1 a ogni ripetizione
	}

	/*Stampa del numero di nepero calcolato*/

	printf("Il numero di nepero e': %f", nepero);


}