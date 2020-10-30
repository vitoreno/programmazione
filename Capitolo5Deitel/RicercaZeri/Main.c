/*
	Programma per la ricerca degli zeri di una funzione
*/

#include <stdio.h>
#include <math.h>

/* Prototipi delle funzioni */
int EsisteZero(float, float);
float f(float);

int main()
{
	float a, b, c;
	float tolleranza = 1e-4;
	int MaxIter = 100;
	int cnt = 0;

	printf("Programma per la ricerca degli zeri di una funzione\n\n");
	printf("la funzione studiata e' y = 0.75*x*x - 4.235*x + 3.112\n\n");

	printf("Inserire il primo punto dell'intervallo. a = ");
	scanf_s("%f", &a);
	printf("Inserire il secondo punto dell'intervallo. b = ");
	scanf_s("%f", &b);

	if (EsisteZero(a, b))
	{
		do
		{
			c = (a + b) * 0.5;
			if (EsisteZero(a, c))
				b = c;
			else
				a = c;
		} while (fabs(f(c)) > tolleranza && ++cnt < MaxIter);

		printf("\n*** Display dei risultati ***\n");
		printf("Soluzione ottenuta in %d iterazioni del metodo\n", cnt);
		printf("Lo zero della funzione e' in x = %f\n", c);
		printf("f(%f) = %f\n", c, f(c));
	}
	else
		printf("Non ci sono zeri nell'intervallo specificato [%.2f, %.2f] oppure c'e' piu' di una radice\n", a, b);

	return 0;
}

/* Definizione delle funzioni */

/* 
	Durante l'esercitazione a casa osservare ATTENTAMENTE se il corpo delle
	funzioni è implementato come riportato nel diagramma di flusso.
	
	Se sì
		tutto ok
	Se no
		Fare
			Osservare cosa è cambiato
			Capire se le implementazioni sono equivalenti
		Finché(ho dei dubbi);
*/
int EsisteZero(float pt1, float pt2)
{
	int retVal;

	if (f(pt1) * f(pt2) <= 0)
		retVal = 1;
	else
		retVal = 0;

	return retVal;
}

float f(float x)
{
	return 0.75*x*x - 4.235*x + 3.112;
}