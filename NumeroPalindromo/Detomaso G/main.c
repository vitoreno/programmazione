/**
 * Obiettivo: preso in input un numero intero da 5 cifre controllare se si tratta di un numero palindromo.
 * 
 * Un numero palindromo è un numero che rimane invariato letto al contrario
*/

#include <stdio.h>
#include <math.h>

/**
 * Metodo per stabilire se un numero e' palindromo 
 * PARAMETRI: 
 *      n : numero da testare (input)
 *      nCifre : numero di cifre di n
 *      inverso : valore di ritorno (numero invertito)
*/

int invertiNumero(int n, int nCifre); // prototipo
int main()
{
    int nPal; // numero palindroo
    int numCifre;

    printf("Inserire un numero da 5 cifre: ");
    scanf("%d", &nPal);

    numCifre = floor(log10(nPal) + 1);

    /* Controllo sul numero di cifre inserite*/

    while (numCifre > 5)
    {
        printf("\nERRORE - Inserire un numero da 5 cifre: ");
        scanf("%d", &nPal);

        numCifre = floor(log10(nPal) + 1);
    }

    /*Converte il numero negativo in numero positivo per il calcolo*/

    if (nPal < 0)
        nPal *= -1;

    /*Confronto usando un operatore ternario per stabile se il numero e' palindromo*/

    nPal == invertiNumero(nPal, numCifre) ? printf("Il numero %d e' palindromo ", nPal) : printf("Il numero %d non e' palindromo ", nPal);
}

int invertiNumero(int n, int nCifre)
{
    int i;              // contatore ciclo
    int inverso, cifra; // numero letto al contrario

    inverso = 0;
    i = 0;

    do
    {
        cifra = n % 10;                 // calcola l'ultiima cifra come resto della divisione per 1'
        inverso = (inverso * 10) + cifra; // procedura per invertire il numero
        n /= 10;                        // divisione di n per 10
        i++;
    } while (i < nCifre);

    return inverso; // ritorno del numero inverso
}