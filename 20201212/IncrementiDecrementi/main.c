/*
	Esempi di utilizzo di incrementi e decrementi
*/

#include <stdio.h>

int main()
{
	int v1;
	int i;

	v1 = 0;

	/* Con il termine incremento intendiamo l'operazione con cui aumentiamo il valore di una variabile di una certa quantita' */
	printf("Valore iniziale di v1: %4d\n", v1);

	/* Metodo 1: 
		"Assegno a v1 il suo attuale valore incrementato di 10" 
		oppure equivalentemente "Sommo 10 al valore di v1 e sovrascrivo il suo valore" */
	v1 = v1 + 10;
	printf("Valore di v1 dopo il primo incremento: %4d\n", v1);

	/* Metodo 2:
		Scrittura piu' compatta del Metodo 1
		
		Quando si incontra la scrittura 
			[variabile] [operatore seguito da uguale] [valore]
		si ottiene il seguente comportamento 
			variabile = variabile [operatore] valore; */
	v1 += 10;
	printf("Valore di v1 dopo il secondo incremento: %4d\n", v1);

	/* Metodo 3:
		Nel caso in cui l'incremento sia unitario e' possibile utilizzare l'operatore ++
		in una delle sue due forme (postfisso o prefisso)
	*/
	v1++;
	printf("Valore di v1 dopo il terzo incremento: %4d\n", v1);

	++v1; 
	printf("Valore di v1 dopo il quarto incremento: %4d\n", v1);

	/*
		Osservazione sul comportamento dell'incremento postfisso o prefisso
	*/
	
	/* Nel caso di incremento postfisso PRIMA utilizzo la variabile e DOPO la incremento
		Questo significa che printf stampera' 22, 
		ma quando si passa all'istruzione successiva v1 sara' stata incrementata di 1, 
		quindi varra' 23
	*/
	printf("Valore di v1 dopo il quinto incremento: %4d\n", v1++);

	/* Nel caso di incremento prefisso PRIMA si incrementa la variabile e DOPO la si utilizza
		Questo significa che printf stampera' 24,
		perche' il valore iniziale di v1 sara' 23, ma l'incremento prefisso fa si' che 
		v1 assuma valore 24 prima della stampa
	*/
	printf("Valore di v1 dopo il sesto incremento: %4d\n", ++v1);

	/* 
		Utilizzo degli incrementi postfissi o prefissi nei cicli for 
		
		Si riportano due cicli for e i corrispondenti cicli while EQUIVALENTI
		Si vuole verificare il comportamento dell'operatore ++ in diverse situazioni
	*/

	for (i = 0; i <= 10; i++)
		printf("%d\n", i);

	i = 0;
	while (i <= 10)
	{
		printf("%d\n", i);

		i++;
	}

	for (i = 0; i <= 10; ++i)
		printf("%d\n", i);

	i = 0;
	while (i <= 10)
	{
		printf("%d\n", i);

		++i;
	}

	/* Variazioni sul tema */

	/* Variazione 1 */
	printf("\n\n\n");
	i = 0;
	while (i++ <= 10)
		printf("%d\n", i);
	printf("Valore di i in uscita dal ciclo %d\n", i);

	/* Variazione 2 */
	printf("\n\n\n");
	i = 0;
	while (++i <= 10)
		printf("%d\n", i);
	printf("Valore di i in uscita dal ciclo %d\n", i);

	/* Personalmente eviterei utilizzi di questo tipo, 
		ma didatticamente li ritengo utili a comprendere 
		il funzionamento dell'incremento e la opzionalita' dei campi del for
	*/

	/* Ciclo for equivalente alla Variazione 1 */
	for(i = 0; i++ <= 10; )
		printf("%d\n", i);
	printf("Valore di i in uscita dal ciclo %d\n", i);

	/* Ciclo for equivalente alla Variazione 2 */
	for (i = 0; ++i <= 10; )
		printf("%d\n", i);
	printf("Valore di i in uscita dal ciclo %d\n", i);

}