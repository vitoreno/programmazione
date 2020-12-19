/*
	Esempio di utilizzo di un menu a scelta multipla con enumerazione e switch
*/

#include <stdio.h>

enum PossibiliScelte { USCITA, F1, F2, F3 };

void StampaMenu();
void Funzione1();
void Funzione2();
void Funzione3();

int main()
{
	int scelta;
	printf("Programma di esempio scelta multipla\n");

	/* Presento all'utente le scelte possibili e ciclo finche' non viene richiesto esplicitamente di uscire */
	do
	{
		StampaMenu();
		scanf_s("%d", &scelta);

		/* La selezione multipla e' necessaria per processare la richiesta dell'utente */
		/*
		if (scelta == F1)
			Funzione1();
		else if (scelta == F2)
			Funzione2();
		else if (scelta == F3)
			Funzione3();
		else
			printf("Scelta non valida, prego scegliere un numero valido.\n");
		*/

		switch (scelta)
		{
		case F1:
			Funzione1();
			break;
		case F2:
			Funzione2();
			break;
		case F3:
			Funzione3();
			break;
		case USCITA:
			break;
		default:
			printf("Scelta non valida, prego scegliere un numero valido.\n");
			break;
		}

	} while (scelta != USCITA);

	return 0;
}

void StampaMenu()
{
	printf("++++++++++++++\n");
	printf("MENU PRINCIPALE\n\n");
	printf("[1] Funzione 1\n");
	printf("[2] Funzione 2\n");
	printf("[3] Funzione 3\n");
	printf("[0] USCITA\n");
	printf("++++++++++++++\n");
}

void Funzione1()
{
	printf("Hai richiamato la Funzione 1\n");
}

void Funzione2()
{
	printf("Hai richiamato la Funzione 2\n");
}

void Funzione3()
{
	printf("Hai richiamato la Funzione 3\n");
}

void fun()
{


}