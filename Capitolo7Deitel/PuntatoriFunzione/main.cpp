/*
	Programma per l'ordinamento di un vettore di struct
	utilizzando BubbleSort e puntatori a funzione
*/
#include <stdio.h>
#include <string.h>
#define N 4


/* Definizione della struttura persona_ */
struct persona_
{
	char Nome[32];
	char Cognome[32];
	int AnnoNascita;
};
typedef struct persona_ persona; /* Con la typedef si potra' scrivere semplicemente persona anziche' struct persona_ */


void StampaVettore(persona* vet, const int dim);
void BubbleSort(persona* vet, const int dim, int(*Compara)(persona p1, persona p2)); /* La funzione per comparare due persone viene passata come puntatore a funzione */
int OrdinaPerNome(persona p1, persona p2);
int OrdinaPerCognome(persona p1, persona p2);
int OrdinaPerAnno(persona p1, persona p2);

int main()
{
	/* Si definisce un array di "persona" denominato Utenti */
	persona Utenti[N] = { {"Vito", "Reno", 1988}, {"Mario", "Rossi", 1961}, {"Giovanna", "Bianchi", 1998}, {"Federica", "Verdi", 1993} };

	printf("Array Utenti partenza\n");
	StampaVettore(Utenti, N);
	
	/* Grazie al fatto che si e' utilizzato un puntatore a funzione, si può richiedere di ordinare l'array in piu' modi diversi */
	BubbleSort(Utenti, N, OrdinaPerNome); /* Il nome di una funzione e' un puntatore a funzione */
	
	printf("Array Utenti ordinati per nome\n");
	StampaVettore(Utenti, N);

	BubbleSort(Utenti, N, OrdinaPerCognome);
	
	printf("Array Utenti ordinati per cognome\n");
	StampaVettore(Utenti, N);

	BubbleSort(Utenti, N, OrdinaPerAnno);
	
	printf("Array Utenti ordinati per anno di nascita\n");
	StampaVettore(Utenti, N);

	return 0;
}

void StampaVettore(persona* vet, const int dim)
{
	/* Stampa ogni elemento dell'array */
	printf("\n");
	for (int i = 0; i < dim; i++)
	{
		printf("Utente %d\n", i);
		printf("Nome: %s\n", vet[i].Nome);
		printf("Cognome: %s\n", vet[i].Cognome);
		printf("Nato/a nel %d\n\n", vet[i].AnnoNascita);
	}
	printf("\n");
}

void BubbleSort(persona* vet, const int dim, int(*Compara)(persona p1, persona p2))
{
	/* Algoritmo di ordinamento dell'array 
		Osservare il fatto che l'operatore con cui comparare i due elementi dell'array volta per volta
		non e' piu' il ">" come avveniva negli esempi precedenti. In questo caso le due "persona" p1 e
		p2 vengono comparate con la funzione Compara, passata a BubbleSort come puntatore a funzione.

		Questo significa, all'atto pratico, che sara' possibile richiamare l'algoritmo di ordinamento
		specificando ogni volta una funzione diversa che possa decidere come effettuare l'ordinamento.

		In questo esempio si ordina l'array in tre modi diversi, ma richiamando sempre la stessa funzione
		BubbleSort.
	*/
	void Scambia(persona* pA, persona* pB);
	int passi, i;

	for (passi = 0; passi < dim - 1; passi++)
		for (i = 0; i < dim - 1; i++)
			if (Compara(vet[i], vet[i + 1]))
				Scambia(&vet[i], &vet[i + 1]);
}

void Scambia(persona* pA, persona* pB)
{
	persona tmp = *pA;
	*pA = *pB;
	*pB = tmp;
}

/* Le funzioni di ordinamento, da passare come puntatori a funzione a BubbleSort, 
	prendono in input due "persona" e restituiscono un intero.
	All'interno di ogni funzione si definsice un modo diverso per decidere se p1 e'
	maggiore di p2: una volta confrontando i nomi, un'altra volta confrontando i 
	cognomi e infine confrontando gli anni di nascita.
	Le funzioni restituiscono 1 se BubbleSort deve effettuare lo scambio.
	0 altrimenti.
*/
int OrdinaPerNome(persona p1, persona p2)
{
	if (strcmp(p1.Nome, p2.Nome) > 0)
		return 1;
	else
		return 0;
}

int OrdinaPerCognome(persona p1, persona p2)
{
	if (strcmp(p1.Cognome, p2.Cognome) > 0)
		return 1;
	else
		return 0;
}

int OrdinaPerAnno(persona p1, persona p2)
{
	if (p1.AnnoNascita > p2.AnnoNascita)
		return 1;
	else
		return 0;
}