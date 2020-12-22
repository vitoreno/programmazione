# Scrittura di un file .obj
Programma per la creazione di un file obj contenente i punti appartenenti a una retta nello spazio 3D.

## Breve (brevissima) panoramica sul formato obj
Il file obj e' un file di testo in cui:
- ogni riga che incomincia con # viene ignorata (commento)
- ogni vertice puo' essere rappresentato su una riga formattata nel seguente modo **v <x:float> <y:float> <z:float>**

Si utilizza l'equazione parametrica della retta 3D al variare del parametro t tra -100 e 100
https://www.youmath.it/lezioni/algebra-lineare/geometria-dello-spazio/677-formule-per-le-equazioni-parametriche-della-retta.html

## Per aprire i file obj...
...e' possibile utilizzare, tra gli altri, il software Meshlab disponibile al sito: https://www.meshlab.net/#download

## Approfondimenti
E' possibile specificare una terna R G B per ogni vertice, in modo tale da colorarlo esplicitamente.
Scrivete una variante del codice proposto in modo tale da: 
* colorare la retta di un colore specificato dall'utente 
* colorare ogni punto con un colore estratto casualmente (tramite apposita funzione EstraiColore() )
* spostare la scrittura del file .obj in una o piu' funzioni

## Snippet di codice su cui ragionare

```c
#include <stdio.h>

/* 
	Suggerimenti:
	0. Usiamo direttamente 3 variabili diverse
	1. Usiamo un array per codificare il colore
	2. Usiamo una struct per codificare il colore
	
	Cosa deve restituire la funzione? Cosa cambia nei vari casi?
	Se la funzione deve restituire qualcosa, deve restituire la struct
	Oppure la funzione deve restituire void e modificare direttamente i campi della struct/le variabili

*/

typedef struct Colore_
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
} Colore;

void EstraiColoreVar(unsigned char * R, unsigned char * G, unsigned char * B);
void EstraiColoreArray(unsigned char * RGB);
void EstraiColoreStruct(Colore * RGB);
Colore EstraiColoreStruct2();

int main()
{
	Colore Col;
	EstraiColoreVar(&Col.R, &Col.G, &Col.B);
	/* Completare */
	return 0;
}

/* Definire le funzioni! */
```