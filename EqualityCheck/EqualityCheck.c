/* 
	EqualityCheck.c
	Programma per osservare il comportamento di un programma
	nel momento in cui si utilizza un operatore di assegnamento (=)
	al posto dell'operatore di uguaglianza (==) in una condizione
	
	NOTA: Prima di compilare ed eseguire il programma, scrivere quali saranno gli output su carta.
	Successivamente, verificare che il comportamento del programma sia coerente con quanto ipotizzato.
*/
#include <stdio.h>

int main()
{
	int variabile = 3;

	printf("Inizio del programma\n");	
	printf("Variabile vale %d\n", variabile);
	
	if(variabile = 100)
		printf("Sono entrato nel ramo dell'if\n");
	else
		printf("Sono entrato nel ramo dell'else\n");
	
	printf("Dopo il primo if/else variabile vale %d\n", variabile);
	
	if(variabile = 0)
		printf("Sono entrato nel ramo dell'if\n");
	else
		printf("Sono entrato nel ramo dell'else\n");

	printf("Dopo il secondo if/else variabile vale %d\n", variabile);
	
	if(variabile == 100)
		printf("Sono entrato nel ramo dell'if\n");
	else
		printf("Sono entrato nel ramo dell'else\n");
	
	printf("Dopo il terzo if/else variabile vale %d\n", variabile);		
	printf("Fine del programma\n");
	
	return 0;
}