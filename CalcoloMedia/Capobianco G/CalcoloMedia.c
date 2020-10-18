/* Autore: Giosuè Capobianco */

#include <stdio.h>
#include <stdlib.h>
/*Calcolare la media dei voti di una materia scolastica qualsiasi, per ogni studente richiesto dall'utente */
/*
1) Dichiarazione variabili
2) Inizializzazione
3) Elaborazione dati
4) Visualizzazione Output
*/
int main()
{
    //Dichiarazione e inizializzazione variabili
    int nStudenti, nVoti; //Numero di studenti e numero voti inseriti dall'utente
    int counterV=0, counterStud=0; //Contatori utilizzati nei Cicli
    int somma;  //variabile per "memorizzare" la somma dei voti per fare la media
    int voto;
    float media;

    printf("Di quanti studenti si vuole calcolare la media?\n");
    scanf("%d", &nStudenti);
    while(counterStud<nStudenti){
        printf("Di quanti voti si vuol fare la media?\n");
        scanf("%d", &nVoti);
        while(counterV<nVoti){
                printf("Inserire voto:");
                scanf("%d", &voto);
                somma=somma+voto;
                counterV++;
        }
        media=(float)somma/nVoti;
        printf_s("Media studente:%0.1f \n", media);
        somma=0;
        counterV=0;
        counterStud++;
    }
    printf("Elaborazione Terminata");

    return 0;
}
