/*
	Esempio di utilizzo del comando for
*/

#include <stdio.h>

int main()
{
	int i;

	/*
		Far variare la var di controllo da 1 a 5
		in incrementi di 1
	*/

	/* Caso 1: incremento postfisso */
	for (i = 1; i <= 5; i++)
		printf("%d\n", i);

	/* Equivalenza con il while */
	i = 1;
	while (i <= 5)
	{
		printf("%d\n", i);
		i++;
	}

	/* Caso 2: incremento prefisso */
	for (i = 1; i <= 5; ++i)
		printf("%d\n", i);


	printf("\nCaso 3\n");
	/* Caso 3: si cambiano le condizioni all'interno */
	for(i = 1; i<=5; i=i+1)
		printf("%d\n", i);

	return 0;
}