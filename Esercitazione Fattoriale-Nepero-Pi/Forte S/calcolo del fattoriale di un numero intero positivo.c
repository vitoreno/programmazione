//Nome: Salvatore
//Cognome: Forte
//Matricola: 737321

//programma che acquisce un numero intero positivo e calcoli il suo fattoriale.

#include <stdio.h> //direttive di i/o per il preprocessore


int main (  ){ //inizio del main

setbuf ( stdout, NULL );  /*funzione che mi permette di settera il buffer per far si
                          che i messsaggi di prompt vengano stampati nel modo corretto,
                          necessario nell'IDE ECLIPSE */

int valore;              //variabile che conterrà il valore inserito dall'utente
int valore_invariato ;    /*variabile che conterrà lo stesso valore inserito dall'utente e
                           che rimarrà invariato per un confronto finale*/

//messaggio di rompt
printf ( "%s", "inserire un numero intero non negativo per calcolare il suo fattoriale: " );
scanf ( "%d", &valore );   //acquisiamo valore

valore_invariato = valore;/*poniamo il valore inserito dall'utente nella variabile
                            'valore_invariato',in modo da stampare successivamente
                             il valore inserito inizialmente, per un confronto.*/



 /*inizio iteranzione controllata da sentinella */

  while ( valore != -1 ){//1-inizio del while con valore di flag o sentinella
	                     //  "per terminare il programma"

         /*oltre ad essermi acccertato che il valore non sia -1,  mi accerto
          * che sia anche maggiore di zero, per evitare che l'utente non
          * inserisca numeri negativi*/

      if ( valore > 0 ){//2-inizio di if all'interno del while

         unsigned int risultato = 1;  /*variabile che conterrà il risultato del fattoriale,
                                        inizializzata 1 perchè altrimenti mi ritroverei
                                         col moltiplicare per zero ad ogni iterazione.
                                      */

              /*prendendo in considerazione il valore inserito dall'utente, questa iterazione
	            permette di calcolare il fattoriale di quel specifico numero e si ripeterà fin
	    	    quando il numero non sarà decrementato fino a 1*/

          while ( valore > 1){//3-inizio del while all'interno dell'if
       	        risultato *= valore; //moltiplico "valore" * "risultato"
                --valore;            //predecremento
	      }//3-fine del while all'interno dell'if


        printf ( "il fattoriale del numero inserito %d e\': %d\n", valore_invariato, risultato );

     }//2-fine di if all'interno del while

          //condizione che si verifica nel caso l'utente inserisca dei numeri negativi
	 else {//inizio dell'else
          puts ( "***hai inserito un valore errato*** \a" );
     }//fine dell'else

    /*acquisiamo un nuovo valore per il calcolo del fattoriale o -1 per terminare*/
    printf ( "%s","inserisci un'altro valore o -1 per terminare: ");
    scanf ( "%d", &valore );
    valore_invariato = valore; //assegno il nuovo "valore" acquisito a "valore invariato".

  }//1-fine del while di terminazione con valore di flag

  return 0;

}//fine del main
