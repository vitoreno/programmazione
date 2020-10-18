//Nome: Salvatore
//Cognome: Forte
//Matricola: 737321

/*programma che valuti il valore della costante matematica "e" Eulero
 * rispetto al numero di cicli inseriti dall'utente*/

#include <stdio.h>

int main (  ){//inizio del main
	setbuf ( stdout, NULL );/* necessario settare il buffer per poter stampare in modo corretto
	                           i messaggi di i/o sull'ambiente di svilupo eclipse*/

	int cicli;
	printf ( "%s","inserire il numero di cicli per calcolare la costante di eurelio: " );
	scanf ( "%d", &cicli );


	unsigned int dividendo = 1;//valore che rimarremo invariato e che utilizzero per dividere di
	                           //volta in volta con il divisore "cioè con il valore di ogni fattoriale.

	unsigned int fattoriale = 1;/*variabile che conterrà il fattoriale che incrementeremo e
	                            che calcoleremo ad ogni ciclo fin quando non raggiunge il
	                            numero inserito dall'utente*/

	unsigned int count = 0; //contatore.

	float result_fatt = 1;//variabile che conterrà il risultato di ogni fattoriale.
    float e; //valore a cui assegneremo il calcolo finale.


    /*iterazione che si ripete finchè il contatore non risulta
     * uguale al  numero di cicli inserito dall'utente*/

	while ( count < cicli ){//1-inizio while principale.

         /*while per il calcolo del fattoriale,
           finchè fattoriale maggiore di 1 ripetere*/

	   while ( fattoriale > 1 ){//2-inizio del while annidato per il calcolo del fattoriale


		 result_fatt *= fattoriale;/*moltiplichiamo la variabile result_fatt per il valore
		                             del fattoriale*/

		 --fattoriale;/*decrementiamo il valore fattoriale e ripetiamo il ciclo
		               fin quando non arriveremo a valore 1*/

	   }//2-fine del while annidato per il calcolo del fattoriale


		/*sommiamo alla variabile 'e' il dividendo diviso result_fatt che sarebbe
		 il valore che col ciclo precedente abbiamo ricavato*/

		e += dividendo / result_fatt;
        result_fatt = 1;//riinizializiamo il risultato del fattoriale in modo da ripetere l'operazione senza errori
		++count;        //incrementiamo count
		fattoriale = count;//e riinizializziamo il valore fattoriale con il valore count

	}//1-fine del while principale

	printf ("la costante di Eulero composta dal numero di cicli inseriti è %f\n", e );

   return 0;

}//fine del main
