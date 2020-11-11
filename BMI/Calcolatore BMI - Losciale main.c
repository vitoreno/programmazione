/*Calcolatore dell'Indice di Massa Corporea (BMI)*/

#include <stdio.h>

int main()
{
 float peso;
 float altezza;
 float BMI;

 printf("Inserire il tuo peso corporeo in Kilogrammi: ");
 scanf("%f", &peso);

 printf("\nInserire la tua altezza in Metri: ");
 scanf("%f", &altezza);

 BMI = peso / (altezza * altezza); /*Calcolo BMI.*/
 printf("\nIl tuo Indice di Massa Corporea (BMI) e': %f\n", BMI);

 if (BMI < 18.5) {
    printf ("\nSei sottopeso.\n");
 } else if (BMI <= 24.9){
     printf ("\nSei normopeso.\n");
    }
   else if (BMI <= 29.9){
    printf("\nSei sovrappeso.\n");
    }
   else if (BMI >= 30){
    printf("\nSei obeso.\n");
 }
  if (BMI >= 25.0 || BMI < 18.5){
    printf ("\nIl tuo peso ideale ha un Indice di Massa Corporea (BMI) tra 18.6 e 24.9.");
 }
 return 0;
}
