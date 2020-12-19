/*
	Risoluzione esercizio Deitel 6.21
	pag. 279
*/

#include <stdio.h>

enum TipiBiglietto {FIRST = 1, ECONOMY};

void StampaMenu();
void EmettiBiglietto(int P[], int scelta);
int RicercaPosto(const int P[], int scelta);
int AltraClasse(int scelta);
void StampaClasse(int scelta);

int main()
{
	int PostiAereo[11] = { 0 };
	int scelta;
	
	do
	{
		StampaMenu();
		scanf_s("%d", &scelta);

		switch (scelta)
		{
		case FIRST:
		case ECONOMY:
			EmettiBiglietto(PostiAereo, scelta);
			break;
		default:
			printf("Scelta non valida, prego scegliere un numero valido.\n");
			break;
		}
	} while (scelta != 0);

	return 0;
}

void StampaMenu()
{
	printf("++++++++++++++\n");
	printf("[1] First class\n");
	printf("[2] Economy\n");
	printf("[0] USCITA\n");
	printf("++++++++++++++\n");
}

int RicercaPosto(const int P[], int scelta)
{
	/* Funzione per ricerca di un posto libero 
	
		Se la richiesta e' in prima classe, cerco tra i posti 1 e 5
		Se la richiesta e' economy, cerco tra i posti 6 e 10

		Argomenti:
			P: Array contenente i posti dell'aereo
			scelta: variabile per first/economy

		Valori restituiti:
			-1: ERRORE
			0: POSTO NON DISPONIBILE
			intero > 0: NUMERO DEL POSTO LIBERO
	*/
	int p1, p2;
	int i;

	if (scelta == FIRST)
	{
		p1 = 1;
		p2 = 5;
	}
	else if (scelta == ECONOMY)
	{
		p1 = 6;
		p2 = 10;
	}
	else
		return -1;
	
	/* Ricerca lineare tra p1 e p2 */
	for (i = p1; i <= p2; i++)
		if (P[i] == 0)
			return i;
	
	return 0;
}

void EmettiBiglietto(int P[], int scelta)
{
	/* Funzione per l'emissione di un biglietto */
	int PostoLibero; /* Eventuale indice del posto libero */
	int CambioClasse = 0; /* Gestione del cambio classe */

	PostoLibero = RicercaPosto(P, scelta);
	if (!PostoLibero)
	{
		if(scelta == FIRST)
			printf("Vuoi accettare un eventuale posto in ECONOMY? [0] No, [1] Si: ");
		else
			printf("Vuoi accettare un eventuale posto in FIRST? [0] No, [1] Si: ");
		
		scanf_s("%d", &CambioClasse);

		if (CambioClasse)
			PostoLibero = RicercaPosto(P, AltraClasse(scelta));
	}

	/* Sono sicuro che PostoLibero e CambioClasse contengono tutte le informazioni necessarie a procedere */
	if (PostoLibero)
	{
		/* Posto Assegnato correttamente */
		P[PostoLibero] = 1; /* Il posto viene occupato */
		
		printf("Carta di imbarco\n");
		printf("Posto assegnato: %2d ", PostoLibero);
		printf("Classe ");
		if (CambioClasse)
			StampaClasse(AltraClasse(scelta));
		else
			StampaClasse(scelta);
		printf("\n");

	}
	else
		printf("Il prossimo volo partira' tra tre ore.\n");
}

int AltraClasse(int scelta)
{
	if (scelta == FIRST)
		return ECONOMY;
	else
		return FIRST;
}

void StampaClasse(int scelta)
{
	if (scelta == FIRST)
		printf("FIRST");
	else
		printf("ECONOMY");
}