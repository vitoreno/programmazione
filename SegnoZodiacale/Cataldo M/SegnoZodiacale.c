/*
OBIETTIVO: Creare un programma che inserita in input la data di nascita restituisce il segno zodiacale corrispondente

Disporre di una variabile per il giorno e una variabile per il mese di nascita

Richiedere all'utente di inserire giorno e mese di nascita

Per ogni mese valido SE è valido anche il giorno, inserire le condizioni che consentano di stampare correttamente il segno zodiacale

stampa del segno zodiacale
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int giorno; //dichiaro variabile giorno
    int mese;  // dichiaro variabile mese

    printf("Inserisci giorno di nascita: ");
    scanf("%d", &giorno);
    printf("Inserisci mese di nascita: (in numeri) ");
    scanf("%d",&mese);


    switch(mese){//imposto le condizioni per ogni mese in base al giorno inserito
       case 1:
        if (giorno>=1&&giorno<=31){/*verifico che il giorno inserito sia valido per il mese.
                                  Se è valido eseguo il ciclo, altrimenti restituisco messaggio d'errore*/
          if (giorno >= 1 && giorno <= 20)
            printf("Capricorno!");
          else
            printf("Acquario!");
            }
            else printf ("Giorno non valido");
       break;
/*ripeto per ogni mese*/
       case 2:
        if (giorno>=1&&giorno<=29){
          if (giorno >= 1 && giorno <= 19)
            printf("Acquario!");
          else
            printf("Pesci!");
             }
            else printf ("Giorno non valido");
       break;

       case 3:
        if (giorno>=1&&giorno<=31){
          if (giorno >= 1 && giorno <= 20)
            printf("Pesci!");
          else
            printf("Ariete!");
             }
            else printf ("Giorno non valido");
       break;

       case 4:
        if (giorno>=1&&giorno<=30){
          if (giorno >= 1 && giorno <= 20)
            printf("Ariete!");
          else
            printf("Toro!");
             }
            else printf ("Giorno non valido");
       break;

       case 5:
        if (giorno>=1&&giorno<=31){
          if (giorno >= 1 && giorno <= 20)
            printf("Toro!");
          else
            printf("Gemelli!");
             }
            else printf ("Giorno non valido");
       break;

       case 6:
        if (giorno>=1&&giorno<=30){
          if (giorno >= 1 && giorno <= 21)
            printf("Gemelli!");
          else
            printf("Cancro!");
             }
            else printf ("Giorno non valido");
       break;

       case 7:
        if (giorno>=1&&giorno<=31){
          if (giorno >= 1 && giorno <= 22)
            printf("Cancro!");
          else
            printf("Leone!");
             }
            else printf ("Giorno non valido");
       break;

       case 8:
        if (giorno>=1&&giorno<=31){
          if (giorno >= 1 && giorno <= 23)
            printf("Leone!");
          else
            printf("Vergine!");
             }
            else printf ("Giorno non valido");
       break;

       case 9:
        if (giorno>=1&&giorno<=30){
          if (giorno >= 1 && giorno <= 22)
            printf("Vergine!");
          else
            printf("Bilancia!");
             }
            else printf ("Giorno non valido");
       break;

       case 10:
        if (giorno>=1&&giorno<=31){
          if (giorno >= 1 && giorno <= 22)
            printf("Bilancia!");
          else
            printf("Scorpione!");
             }
            else printf ("Giorno non valido");
       break;

       case 11:
        if (giorno>=1&&giorno<=30){
          if (giorno >= 1 && giorno <= 22)
            printf("Scorpione!");
          else
            printf("Sagittario!");
             }
            else printf ("Giorno non valido");
       break;

       case 12:
        if (giorno>=1&&giorno<=31){
          if (giorno >= 1 && giorno <= 21)
            printf("Sagittario!");
          else
            printf("Capricorno!");
             }
            else printf ("Giorno non valido");
       break;

       default:
        printf("Mese non valido");
        break;
       }//fine switch

    return 0;//fine
}
 