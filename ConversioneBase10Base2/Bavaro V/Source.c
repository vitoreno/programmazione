
                                                   /*CONVERTE I NUMERI IN BASE 10 IN BASE 2*/
#include<stdio.h>
int main() { /*START*/
	int N; /*NUMERO INTERO*/
	float D; /*NUMERO DECIMALE*/

	printf("Enter number to convert, -1 to end: \n");
	scanf_s("%d", &N); /*INSERISCI NUMERO DA CONVERTIRE*/

	while (N != -1 ) {   /*RIPETI FINCHE NON VIENE LETTO IL VALORE SENTINELLA*/
		if (N > 1) {     
			do {                                   
				if (N % 2 == 0) {     /* CALCOLA IL RESTO DELLA DIVISONE CON DUE*/
					N = N / 2;        /*SE UGUALE A 0, DIVIDI PER DUE E SCIRVI 0*/
					
					printf(" 0\n");
				} else {
					N = N / 2;        /*SE UGUALE A 1, DIVIDI PER DUE*/
					
					printf(" 1\n");   /*SCRIVI 1*/
				  }
			} while (N > 0);          /*RIPETI FINCHE IL NUMERO è MAGGIORE DI 0*/
			printf("Read from bottom to top.\n"); /*REGOLA DI LETTURA DEL RISULTATO*/
		}
		else {                        /*ISTRUZIONI IN CASO IL NUMERO SIA O DIVENTI MINORE DI 1*/
			scanf_s("%f", &D);
			do {                                  
				D = D * 2;            /*MOLTIPLICA PER 2*/
				if (D > 1) {          /*SE IL NUMERO DIVENTA MAGGIORE DI 1*/
					D = D - 1;        /*SOTTRAI 1 DAL RISULTATO*/
					
					printf(" 1\n");   /*SCRIVI 0*/
				} else {              /*SE IL NUMERO DIVENTA MINORE DI 1*/
					
					printf(" 0\n");   /*SCRIVI 0*/
				 }
			} while (D * 2 != 1);     /*RIPETI FINCHE LA MOTIPLICAZIONE FA 1*/
			printf(" 1\n");                
			printf("Read from top do bottom.\n"); /*REGOLA DI LETTURA DEL RISULTATO*/
		}
		printf("Enter number to convert, -1 to end: \n"); 
		scanf_s("%d", &N);
	}
	return 0;
}