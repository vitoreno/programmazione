//Tombola a cura di Cellammare Gabriel.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h> //libreria per utlizzare la funzione setcolor

#define MAX 100
#define P 6
#define MAXC 1350
#define RIGHE 9
#define COLONNE 10
#define TMB 90

void SetColor(unsigned short); //colora l'output sul prompt
void premi(float,float*); //procedura utilizzata per calcolare l'ammontare di tutti i premi.
void inizialn(int*,int,int,int); //procedura utlizzata per randomizzare tutte le cartelle, in modo tale che una cartella non contenga due numeri uguali.
void menu(); //menù visivo
void estrai(int [][COLONNE],int[],int*,int*); //procedura utlizzata per estrarre (stampare)  il numero della tombola.
void nsorteggiati(int*,int); //procedura utlizzata per visualizzare lo storico dei numeri sorteggiati.
void controllat(int [][COLONNE]); //procedura utlizzata per controllare lo status del tombolone.
void gioco(int,int[],int[],int); //procedura utlizzata per visulizzare le cartelle dei giocatori.
void stampap(int [],float[]); //procedura utlizzata per visulizzare le vincite dei giocatori.
void controllap(int[],int,int[],int[]); //procedura utlizzata per controllare le vincite.
void simpaticone(); //procedura utlizzata per i simpaticoni.


/*
Per riempire totalamente il vettore di numeri e controllare tutte le schede, utilizzerò
un unico vettore di dimensione 1350 (15 numeri per ogni scheda, per 90 schede.)
Dopodiche, una volta che tutti i giocatori avranno scelto il loro
numero di schede, verrà randomizzato il vettore con numeri da 1 a 90.
*/


int main()
{
	srand(time(NULL));
	
	int giocatori; //ngiocatori
	
	int estratto[TMB]={0}; //vettore per controllare i numeri estratti
	int estrattop=0; //variabile parziale per controllare il numero estratto nella rand per i valori estratti.	
	int indice=0; //indice per tener conto dei numeri estratti
	
	int parzi=0; //variabile che conterrà il numero estratto volta per volta
	int controllo=0; //variab ile di controllo
	int vctf=0; //variabile di controllo
	
	int g=0; //indice
	int i,j,cont=1;//indice
	int scelta;//indice
	
	int vetc[MAX]={0}; //vettore che conterrà il numero di cartelle di ogni giocatore
	int ncartelle=90; //numero delle cartelle totali
	int ncartelleg=0;//ncartelle totali acquistate dai giocatori
	float somma=0; //somma parziale in base alle cartelle acquistate
	
	float premiv[P]; //vettore che conterrà tutti i premi
	int vetn[MAXC]={0}; //vettore che conterrà tutti i numeri random in base al numero di schede
	
	int numeritotali=0; //variabile che conterà tutti i numeri in base alle schede (15 numeri per scheda)
	int tombolone[RIGHE][COLONNE]={{'0','0'}}; //tombolone
	
	int atqct[8]={0}; //vettore che conterrà valori di controllo
	char sc; //carattere di controllo finale


	for(i=0;i<7;i++)
	{
		atqct[i]=0;
	}
		
	//fase di inizializzazione di tutti i vettori
	
	for(i=0;i<RIGHE;i++)
	{
		for(j=0;j<COLONNE;j++)
		{
			tombolone[i][j]=cont;
			cont++;
		}
	}

	i=0;
	
	do
	{
		if(i==0)
		{
			estratto[i]=rand()%90+1;
			i++;	
		}
		
		else
		
		{
			estrattop=rand()%90+1;
			
			controllo=0;
			
			for(g=0;g<i;g++)
			{
				
				if(estratto[g]==estrattop)
				{
					controllo=1;
			
				}
			}
			if(controllo==1)
			{

			}
			
			else
			
			{
				estratto[i]=estrattop;
				i++;
			}
		}
		
	}while(i<TMB);
	
	//  ^^^  randomizzazione dei numeri che verranno estratti per la tombola.
	//	 |
	//	 |
	
	do{	
		printf("--- Benvenuto nel gioco della tombola in C ---");
		
	
		printf("\n\n\n");

	
	
		printf("Inserisci il numero di giocatori (Max 10): ");
		
		scanf("%d",&giocatori);
		
		if(giocatori < 2 || giocatori>10)
		{
			printf("Errore, numero errato.");
			
			printf("\n");
			
			system("PAUSE");
			
			system("CLS");
		}
		
	}while(giocatori < 2 || giocatori>10);
	
	system("CLS");
	
	i=0;
	
	do{
		printf("E'IL TUO TURNO GIOCATORE %d!",i+1);
		
		printf("\nSono disponibili %d cartelle.",ncartelle);
		
		printf("\nIl costo di ogni cartella, corrisponde a 1,50 euro.\n");
		
		do{
		
			printf("\nInserisci il numero delle cartelle da acquistare: ");
			
			scanf("%d",&vetc[i]);
			
			if(vetc[i]<1 || vetc[i]>90)
			
			{
				printf("\n");
				printf("Errore, numero non valido!");
				printf("\n");
			}
		
		}while(vetc[i]<1 || vetc[i]>90);
		
		ncartelleg+=vetc[i]; //calcolo cartelle totali
		
		ncartelle=ncartelle-vetc[i]; //sottrazione delle cartelle disponibili
		
		if(ncartelle==0)
		{
			printf("\n");
			printf("Cartelle esaurite!");
			printf("\nIl giocatore %d ha comprato le cartelle rimanenti.\n",i+1);
			printf("\n");
		}
		
		system("PAUSE");
		
		system("CLS");
	
		somma=somma+(1.50*vetc[i]); //calcolo montepremi totale
		
		i++;
		
	}while(i<giocatori && ncartelle!=0);	
	
	
	premi(somma,premiv);
	
	system("Pause");
	
	numeritotali=15*ncartelleg;
	
	inizialn(vetn,numeritotali,giocatori,ncartelleg); //randomizzo tutte le cartelle e i numeri
	
	printf("\nPremi INVIO per iniziare a giocare!\n");
	system("PAUSE");
	
	system("CLS");
	
	do{
	
		do{
	
			menu();
		
			scanf("%d",&scelta);
		
			if(scelta <1 || scelta>5)
			
			{
				printf("\nERRORE! RIPTERE LA SCELTA!");
			
				printf("\n");
			
				system("PAUSE");
				
				system("CLS");
			}
		
		}while(scelta <1 || scelta>5);
		
		switch(scelta)
		{
			case 1:
					estrai(tombolone,estratto,&indice,&parzi); // estrazione visiva, in realtà il numero e' stato randomizzato precedentemente.
						
					for(i=0;i<RIGHE;i++)
					{
						for(j=0;j<COLONNE;j++)
						{
							if(tombolone[i][j]==parzi)
							{
								tombolone[i][j]=0; //azzeramento numeri estratti
							}
						}
					}
					
					for(i=0;i<numeritotali;i++)
					{
						if(vetn[i]==parzi)
						
						{
								vetn[i]=0; //azzeramento numeri estratti
						}
									
					}
					
					if(indice==1)
					{

						simpaticone(giocatori);
					}
					
					controllap(vetn,giocatori,vetc,atqct);
					system("Pause");
					stampap(atqct,premiv);
					break;
					
			case 2:
					gioco(giocatori,vetc,vetn,indice);
					break;
			
			case 3:
					nsorteggiati(estratto,indice);
					break;
					
			case 4:
					controllat(tombolone);
					break;	
			
			case 5:
					system("CLS");
					premi(somma,premiv);
					break;			
		}
		
		
			if(atqct[4]==2 && atqct[5]==2)
			{
				vctf=1;
				sc='N'; //controllo effettuato per uscire dal gioco direttamente se la tombola e il tombolino sono stati vinti.
			}
			
			else
			
			{
				if(vctf==0)
				{
				
					do{
						printf("\nVuoi tornare almenu (S/N)?:  ");
						scanf(" %c",&sc);
			
						if(sc!='S'&& sc!='N')
						{
							printf("\nErrore, ripetere la scelta.\n");
						}
						
					}while(sc!='S'&& sc!='N');
				}
				
				else
				
				{
					break;
				}
			}
		 
			system("CLS");	
			
	}while(sc=='S'&& vctf==0);
	
	printf("\nGrazie per aver giocato!\t\t");
	
	printf("\n\n\n\n\n");
	
	printf("A cura di [Cellammare Gabriel].\t");
	
	printf("\n\n");
	
	system("PAUSE");
	return 0;
}

void menu()
{
	printf("--- Benvenuto nel gioco della tombola in C ---");
	
	printf("\n\n\n");
	
	printf("1) Estrai un numero");
	
	printf("\n2) Controlla le cartelle");
	
	printf("\n3) Controlla i numeri sorteggiati");
	
	printf("\n4) Controlla il tombolone ");
	
	printf("\n5) Visualizza i premi ");
		
	printf("\n   Fai una scelta: ");
}

void premi(float x,float* pvp)
{
	float parz;
	int i=0;
	
	printf("--- Lista dei premi della tombola in C ---");
	
	printf("\n\n");
		
	printf("Sono stati raccolti %.2f euro.\n\n",x);
	
	printf("-LISTA-");
	printf("\n\n");
	
	parz=x/2;
	printf("Tombola: %.2f",parz);
	printf("\n\n");
	parz=parz/2;
	printf("Tombolno: %.2f",parz);
	printf("\n\n");
	parz=parz/2;
	printf("Cinquina: %.2f",parz);
	printf("\n\n");
	parz=parz/2;
	printf("Quaterna: %.2f",parz);
	printf("\n\n");
	parz=parz/2;
	printf("Terna: %.2f",parz);
	printf("\n\n");
	parz=parz/2;
	printf("Ambo: %.2f",parz);
	printf("\n\n");
	
	parz=0;
	
	for(i=0;i<P;i++)
	{
		if(i==0)	
		{
			*(pvp+i)=x/2;	 //utilizzo del puntatore al vettore per i premi (premiv[])						
		}
					
		else
		
		{
			*(pvp+i)=pvp[i-1]/2;
		}		
	}
	
		
}


void inizialn(int* pv,int x,int g,int c)
{
	int i=0,inizio=0;
	int parz=0;
	int gi=0;
	int controllo=0;
	
	system("CLS");
	
	printf("\nBenvenuto nella randomizzazione dei %d numeri calcolati dal sistema.",x);
	
	printf("\n\nI giocatori totali sono: %d\n",g);
	
	printf("\nLe cartelle acquistate da tutti i giocatori sono: %d\n",c);
	
	printf("");
	
	i=0;
	
	//algoritmo per randomizzare numeri da 1 90 da inserire nelle cartelle.
	//N.B Non ci saranno mai due numeri uguali nella stessa cartella.
	
	do
	{		
		
		if(i==0)
		{
			*(pv+i)=rand()%90+1;
			i++;
		}
		
		
		else
		
		{
			if( (i+1)  % 15 == 0)
			{
				inizio=i;
			}

			
			parz=rand()%90+1;
			
			controllo=0; 
			
			for(gi=inizio;gi<i;gi++)
			{
				
				if(*(pv+gi)==parz)
				{
					controllo=1;
			
				}
			}
			
			if(controllo==1)
			{

			}
			
			else
			
			{
				*(pv+gi)=parz;
				i++;
			}
			
		}	
		
	}while(i<x);	

	
}

void estrai(int tomb[][COLONNE],int nestratto[],int* indice,int* p)
{	
	int i,j;
	
	int parz=0;
	
	
	system("CLS");
	
	printf("--- Benvenuto nel gioco della tombola in C ---");
	
	printf("\n\n");

	if(*indice<90)
	
	{
	
	
	for (i = 0; i <50; i++) 
	{ //ciclo per simulare la tombola
		parz=rand()%90+1;
		printf("ESTRAZIONE DEL NUMERO\n");
		printf("_______________________\n");
		printf("||Tombola napoletana   ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||	               ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||Il numero estratto   ||\n");
		printf("||		       ||\n");
		printf("||e': %d              ||\n", parz);
		printf("||==================== ||\n");
		system("CLS");
	}
	


	
		printf("ESTRAZIONE DEL NUMERO\n");
		printf("_______________________\n");
		printf("||Tombola napoletana   ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||	               ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||xxxxxxxxxxxxxxxxxxxx ||\n");
		printf("||		       ||\n");
		printf("||Il numero estratto   ||\n");
		printf("||		       ||\n");
		printf("||e': %d               ||\n", nestratto[*indice]); //estrazione del vettore[i] con indice il puntatore alla variabile indice.
		printf("||==================== ||\n");
		
		*p=nestratto[*indice]; //assegno alla variabile parziale il numero[indice] con cui controllare gli altri vettori nel main.
		
		*indice=*indice+1; //incremento dell'indice se quest'ultimo minore di 90.
		
		
	
}
	
	else
	
	{
		printf("ERRORE! SONO STATI ESTRATTI TUTTI I 90 NUMERI.\n");
	}
	
}

void nsorteggiati(int* pntv,int x)
{
	//stampa storico dei numeri estratti
	
	system("CLS");
	int i;
	
	printf("--- Benvenuto nel gioco della tombola in C ---");
	
	printf("\n\n");
	
	printf("Schermata utlizzata per visualizzare i numeri sorteggiati.");
	
	printf("\n");
	
	if(x==0)
	
	{
		printf("\n");
		
		printf("Nessun numero ancora sorteggiato! \n");
			
		printf("Torna al menu'e premi 1.");
			
		printf("\n");

	}
		
	
	for(i=0;i<x;i++)
	{

			printf("%d numero = %d",i+1,*(pntv+i));
			printf("\n");

	}
	
	
}

void controllat(int t[][COLONNE])
{
	int i,j;
	
	// conserva le informazioni "visive" del prompt dei comandi (Sfondo nero, scritta bianca)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	system("CLS");
	//attribuisce al prompt il colore 5, attraverso la funzione SetColor
	SetColor(5);
	printf("Legenda:\n");
	printf("\n0 = Numero estratto");
	SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
	
	printf("\n\n");
	
	//stampa del tombolone
	
	for(i=0;i<RIGHE;i++)
	{
		printf("| ");
		for(j=0;j<COLONNE;j++)
		{
			if(t[i][j]!=0)
			{
				printf("%.2d | ",t[i][j]);
			}
			
			else
			
			{
				SetColor(5);
					
				printf("%.2d ",t[i][j]);
				
				SetConsoleTextAttribute(hConsole, saved_attributes);
				
				printf("| ");

			}
			
			
		}
		
		printf("\n\n");
	}	
}

void gioco(int giocatorif,int vetcgioc[],int vn[],int nso)
{
	int s,i,j,z;
	int cartella;
	int parz=0;
	int indice=0;
	int cont=0,tmb=0;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	

	//stampa del vettore[MAX] attraverso un algoritmo che stampa le cartelle in base al giocatore, 15 numeri alla volta.
	
	for(z=0;z<giocatorif;z++)
	{
		cartella=vetcgioc[z];
		
			
		system("CLS");
		
		printf("\nIl giocatore %d possiede: %d cartelle/a.",z+1,cartella);
		
		for(i=0;i<cartella;i++)
		{
			printf("\n\nLa");
			
			SetColor(5);
			
			printf(" %d ",i+1);
			
			SetConsoleTextAttribute(hConsole, saved_attributes);
			
			printf("cartella possiede questi numeri. ");
			printf("\n");
			
			for(j=indice;j<(indice+15);j++)
			{	
				if(vn[j]!=0)
				{
					printf("%.2d | ",vn[j]);
				}
			
				else
			
				{
					SetColor(5);
					
					printf("%.2d ",vn[j]);
				
					SetConsoleTextAttribute(hConsole, saved_attributes);
				
					printf("| ");

				}		
				
				
				if(vn[j]==0)
				{
					cont++;
				}
				
				if(j==indice+4)
				{
					printf("\n");
				}	
				
				if(j==indice+9)
				{
					printf("\n");
				}
				
			
				
						
			}
				if(nso!=0)
				
				{
					
					printf("\n");
					
					SetColor(5);
		
					printf("\nTi mancano %d numeri per fare tombola.",15-cont);
					
					SetConsoleTextAttribute(hConsole, saved_attributes);
				}
					
			cont=0;
			
			indice+=15;
		}
	
		
			
		printf("\n\n");
		
		system("PAUSE");
		
		cont=0;
			
	}		
}

void controllap(int vettoren[],int gcont,int vettorec[],int premiamb[])
{
				
	premiamb[6]=0;
	premiamb[7]=0;
	
	//premiamb[6] e [7] contengono i valori dove verranno salvati le informazioni del giocatore e il numero di cartella.
	//vengono azzerate ogni volta.
	int i,z,j;
	int indice=0;
	int cartella=0;
	int controllo=0;
	int cont=0,tmb=0;
	
	//algoritmo che controlla ambo,terna,quaterna,cinquina,tombola e tombolino.
	//premiamb[0]=ambo,[1]=terna,[2]=quaterna,[3]=cinquina,[4]=tombola,[5]=tombolino.
	for(i=0;i<gcont;i++)
	{	
		cartella=vettorec[i];
	
		
		for(j=0;j<cartella;j++)
		{
	
			for(z=indice;z<(indice+15);z++)
			{
				if(vettoren[z]==0)
				{
					cont++;
					tmb++;
					
					if(premiamb[0]==0)
					{
						if(cont==2)
						{
							premiamb[0]=1;
							premiamb[6]=i+1;
							premiamb[7]=j+1;
							controllo=1;							
						}
					}
					
					if(premiamb[1]==0)
					
					{
						if(cont==3)
						{
						
							premiamb[1]=1;
							premiamb[6]=i+1;
							premiamb[7]=j+1;
							controllo=1;	
						}
					}
						
					if(premiamb[2]==0)
					{
						if(cont==4)
						{
						
							premiamb[2]=1;
							premiamb[6]=i+1;
							premiamb[7]=j+1;
							controllo=1;
						}
	
					}
					

					if(premiamb[3]==0)
					{
						if(cont==5)
						{
						
							premiamb[3]=1;
							premiamb[6]=i+1;
							premiamb[7]=j+1;
							controllo=1;
						}
					}				
							
												
						
				}
				
				
				if(z-indice==4 || z-indice==9 || z-indice==14)
				{
					cont=0;
				}
			}
			
			if(premiamb[4]==0)
			{
				if(tmb==15)
				{	
					premiamb[4]=1;
					premiamb[6]=i+1;
					premiamb[7]=j+1;
					controllo=1;
				}
			}
			
			if(premiamb[5]==0)
			{
				if(tmb==15)
				{	
					premiamb[5]=1;
					premiamb[6]=i+1;
					premiamb[7]=j+1;
					controllo=1;
				}
			}
			
			tmb=0;					
			indice+=15;

		}
	 					
	}
					
				
			
			
}
				



void stampap(int vetpremi[],float premivi[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    
	SetColor(5);
	
	//stampa del vettore che conterrà il giocatore vincente e la scheda.
	
	if(vetpremi[0]==1)
	{
		;
		system("CLS");
		printf("SCOMPLIMENTI GIOCATORE %d  !!!",vetpremi[6]);
		printf("\a");
		printf("\nFacendo ambo hai vinto il montepremi pari a %.2f euro.",premivi[5]);
		printf("\nL'ambo e' avvenuto nella cartella: %d .",vetpremi[7]);
		printf("\n\n");
		system("PAUSE");
		vetpremi[0]=2;	

	}
			
	if(vetpremi[1]==1)
	{
		system("CLS");
		printf("SCOMPLIMENTI GIOCATORE %d  !!!",vetpremi[6]);
		printf("\a");
		printf("\nFacendo terna hai vinto il montepremi pari a %.2f euro.",premivi[4]);
		printf("\nLa terna e' avvenuta nella cartella: %d .",vetpremi[7]);
		printf("\n\n");
		system("PAUSE");
		vetpremi[1]=2;		
	}
	
	if(vetpremi[2]==1)
	
	{	
		system("CLS");
		printf("SCOMPLIMENTI GIOCATORE %d  !!!",vetpremi[6]);
		printf("\a");
		printf("\nFacendo quaterna hai vinto il montepremi pari a %.2f euro.",premivi[3]);
		printf("\nLa quaterna e' avvenuta nella cartella: %d .",vetpremi[7]);
		printf("\n\n");
		system("PAUSE");
		vetpremi[2]=2;
	}
	
	if(vetpremi[3]==1)
	{
		system("CLS");
		printf("SCOMPLIMENTI GIOCATORE %d  !!!",vetpremi[6]);
		printf("\a");
		printf("\nFacendo cinquina hai vinto il montepremi pari a %.2f euro.",premivi[2]);
		printf("\nLa cinquina e' avvenuta nella cartella: %d .",vetpremi[7]);
		printf("\n\n");
		system("PAUSE");
		vetpremi[3]=2;
	}
	
	if(vetpremi[4]==1)
	{
		system("CLS");
		printf("SCOMPLIMENTI GIOCATORE %d  !!!",vetpremi[6]);
		printf("\a");
		printf("\nHai vinto il montepremi pari a %.2f euro della tombola!",premivi[0]);
		printf("\nLa tombola e' avvenuta nella cartella: %d .",vetpremi[7]);
		printf("\n\n");
		system("PAUSE");
		vetpremi[4]=2;
	}
	
	if(vetpremi[5]==1)
	{	
	
		system("CLS");
		printf("SCOMPLIMENTI GIOCATORE %d  !!!",vetpremi[6]);
		printf("\a");
		printf("\nHai vinto il montepremi pari a %.2f euro del tombolino!",premivi[1]);
		printf("\nIl tombolino e' avvenuto nella cartella: %d .",vetpremi[7]);
		printf("\n\n");
		system("PAUSE");
		vetpremi[5]=2;
	}
	
	SetConsoleTextAttribute(hConsole, saved_attributes);
}

void simpaticone(int g)
{
	int r,i;
	int p;
	
	r=rand()%2;
	
	if(r==1)
	{
		system("PAUSE");
		
		system("CLS");
		
		p=rand()%g+1;
		
		printf("Il giocatore %d dice: AMBO",p);
		
		printf("\n");
		
		system("PAUSE");
		
		printf("\nCaricamento bestemmie in corso: ");
		
		printf("\n\n");
		
		for(i=0;i<1000;i++)
		{
			printf("%c",rand());
			if(i%25==0)
			{
				printf("\n");
			}
		}
		
		printf("\n");
		printf("\nIl giocatore %d e'stato espulso dalla sala.\n",p);
		
		printf("\nIl gioco continuera' con persone sane di mente.\n");
		
		printf("\n");
	}
}
void SetColor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}


