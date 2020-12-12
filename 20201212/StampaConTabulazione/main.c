/*
	Esempio di printf tabulata. 
	Si calcolino i quadrati e i cubi dei numeri da 0 a 10. 
	Si stampi il risultato in forma tabellare.
*/

#include <stdio.h>

int Quadrato(int y);
int Cubo(int z);

int main()
{
	int i; /* Contatore */

	/* Stampa senza l'uso di una funzione */
	printf("%9s %9s %9s\n", "N", "Nquadro", "Ncubo");
	for (i = 0; i <= 10; i++)
		printf("%9d %9d %9d\n", i, i*i, i*i*i);

	/* Stampa con l'uso delle funzioni */
	printf("%9s %9s %9s\n", "N", "Nquadro", "Ncubo");
	for (i = 0; i <= 10; i++)
		printf("%9d %9d %9d\n", i, Quadrato(i), Cubo(i));

	return 0;
}

int Quadrato(int y)
{
	return y * y;
}

int Cubo(int z)
{
	return z * z * z;
}