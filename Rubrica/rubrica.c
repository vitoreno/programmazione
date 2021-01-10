C#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    char nome[16];
    char cognome[16];
    char telefono[16];
    char controllo;
} rubrica;

#define SIZE 51.0 //49 +2 di \n

// PROTOTIPI FUNZIONI
void StampaMenu();
void CreaContatto(rubrica contatto);
void CercaContatto(rubrica contatto);
void ModificaContatto(rubrica contatto);
void EliminaContatto(rubrica contatto);
int RiscriviElimina(int rigaEliminare, int num_righe, rubrica contatto);
void VisualizzaRubrica();
void RichiestaModifica(FILE* fp, int riga, rubrica contatto);
void ModificaCampo(FILE* fp, int riga, rubrica contatto);

int main()
{
  rubrica contatto;
  contatto.controllo='-';
  short scelta;
  char ricomincia;

  do
  {
    do {
      StampaMenu();
      scanf("%d",&scelta);
        if(scelta<0 || scelta>5)
          printf("Errore di digitazione. Riprova.\n");
    } while(scelta<0 || scelta>5);
    puts("");
    switch(scelta)
    {
      case 0: puts(""); printf("Programma terminato."); return 0;
      case 1: CreaContatto(contatto); break;
      case 2: CercaContatto(contatto); break;
      case 3: ModificaContatto(contatto); break;
      case 4: EliminaContatto(contatto); break;
      case 5: VisualizzaRubrica(); break;
    }
    puts("");puts("");
    do
    {
      printf("Vuoi continuare? [S|N] : ");
      scanf(" %c",&ricomincia);
    } while(ricomincia != 'S' && ricomincia != 's' && ricomincia != 'N' && ricomincia != 'n');
  } while(ricomincia=='S' || ricomincia=='s');

  return 0;
}

// FUNZIONI
void StampaMenu()
{
  printf("**** MENU RUBRICA CONTATTI ****\n");
  printf("Seleziona una funzione:\n");
  printf("1. Crea Contatto\n");
  printf("2. Cerca Contatto\n");
  printf("3. Modifica Contatto\n");
  printf("4. Elimina Contatto\n");
  printf("5. Visualizza Rubrica\n");
  printf("0. Esci\n");
  puts("");
  printf("Scelta: ");
}

void CreaContatto(rubrica contatto)
{
  FILE* fpA;
  /* Apro il file e successivamente valuto se l'apertura e' andata a buon fine */
  fpA = fopen("rubrica.csv","a+");

  if(fpA != NULL)
  {
    printf("Per uscire digita CTRL+Z e INVIO\n\n");
    /* L'apertura del file e' andata a buon fine */
    printf("Inserire NOME, COGNOME e TELEFONO\n");
    printf("? ");
    scanf("%s%s%s", contatto.nome, contatto.cognome, contatto.telefono);

    while (!feof(stdin))
    {
        fprintf(fpA,"%-15s %-15s %-15s %c\n", contatto.nome, contatto.cognome, contatto.telefono, contatto.controllo);
        printf("? ");
        scanf("%s%s%s", contatto.nome, contatto.cognome, contatto.telefono);
    }

    fclose(fpA);
  }
  else
      printf("Il file non puo' essere aperto/creato\n");
}

void CercaContatto(rubrica contatto)
{
  FILE* fpR;
  char nome[16];
  char cognome[16];
  short flag = 0;
  fpR = fopen("rubrica.csv", "r");

  if(fpR != NULL)
  {
    printf("*** CERCA CONTATTO ***\n");
    printf("Inserisci il nome: ");
    scanf("%s", nome);
    printf("Inserisci il cognome: ");
    scanf("%s", cognome);
    puts("");

    fseek(fpR, 0, SEEK_END);
    int num_righe = (ftell(fpR) / SIZE);
    //printf("%d",num_righe); //per sapere il numero delle righe
    rewind(fpR); //porto il file pointer all'inizio del file
    for(int i=0;i<num_righe;i++)
    {
      fscanf(fpR,"%s %s %s %c",contatto.nome,contatto.cognome,contatto.telefono,&contatto.controllo);
      if(*nome==*contatto.nome && *cognome==*contatto.cognome)
      {
        flag = 1;
        printf("CONTATTO DI %s %s\n",contatto.nome,contatto.cognome);
        printf("Telefono: %s\n", contatto.telefono);
        break;
      }
    }
    if(!flag)
      printf("Il contatto non e' stato trovato\n");
  }
  else
  {
    printf("Il file non è stato trovato o non puo' essere aperto.\n");
  }
  fclose(fpR);
}

void ModificaContatto(rubrica contatto)
{
  short scelta;
  FILE* fpRR;
  fpRR = fopen("rubrica.csv", "r+");
  if(fpRR != NULL)
  {
    short flag = 0;
    char nome[16];
    char cognome[16];
    char telefono[16];
    int riga;
    fseek(fpRR, 0, SEEK_END);
    int num_righe = ceil(ftell(fpRR) / SIZE);
    rewind(fpRR);
    do
    {
      printf("*** MODIFICA CONTATTO ***\n");
      printf("Cerca il contatto da modificare\n");
      printf("1. Ricerca per NOME e COGNOME\n");
      printf("2. Ricerca per TELEFONO\n");
      scanf("%d",&scelta);
      if(scelta<0 || scelta>2)
        printf("Errore di digitazione. Riprova.\n");
    } while(scelta<0 || scelta>2);

    switch (scelta)
    {
      case 1:
              printf("Inserisci il nome: ");
              scanf("%s", nome);
              printf("Inserisci il cognome: ");
              scanf("%s", cognome);
              puts("");
              for(int i=0;i<num_righe;i++)
              {
                fscanf(fpRR,"%s %s %s %c",contatto.nome,contatto.cognome,contatto.telefono,&contatto.controllo);
                if(*nome==*contatto.nome && *cognome==*contatto.cognome)
                {
                  flag = 1;
                  printf("Contatto trovato.\n");
                  printf("%s %s %s", contatto.nome,contatto.cognome,contatto.telefono);
                  puts("");
                  riga = i;
                  RichiestaModifica(fpRR,riga,contatto);
                  break;
                }
              }
              if(!flag)
                printf("Il contatto non e' stato trovato.\n");

          break;
      case 2:
              printf("Inserisci il numero di telefono: ");
              scanf("%s", telefono);
              puts("");
              for(int i=0;i<num_righe;i++)
              {
                fscanf(fpRR, "%s%s%s", contatto.nome,contatto.cognome,contatto.telefono);
                if(*telefono==*contatto.telefono)
                {
                  flag = 1;
                  printf("Contatto trovato.\n");
                  printf("%s %s %s", contatto.nome,contatto.cognome,contatto.telefono);
                  puts("");
                  riga = i;
                  RichiestaModifica(fpRR,riga,contatto);
                  break;
                }
              }
              if(!flag)
                printf("Il contatto non e' stato trovato.\n");
          break;
    }
    fclose(fpRR);
  }
  else
  {
      printf("Il file non è stato trovato o non puo' essere aperto");
  }
}

void EliminaContatto(rubrica contatto)
{
  /* riscrivere un altro file saltando la riga da eliminare */
  FILE* fpR;
  char nome[16];
  char cognome[16];
  short flag = 0;
  fpR = fopen("rubrica.csv", "r");

  if(fpR != NULL)
  {
    printf("*** ELIMINA CONTATTO ***\n");
    printf("Inserisci il nome: ");
    scanf("%s", nome);
    printf("Inserisci il cognome: ");
    scanf("%s", cognome);
    puts("");

    fseek(fpR, 0, SEEK_END);
    int num_righe = (ftell(fpR) / SIZE);
    //printf("%d",num_righe); //per sapere il numero delle righe
    rewind(fpR); //porto il file pointer all'inizio del file
    for(int i=0;i<num_righe;i++)
    {
      fscanf(fpR,"%s %s %s %c",contatto.nome,contatto.cognome,contatto.telefono,&contatto.controllo);
      if(*nome==*contatto.nome && *cognome==*contatto.cognome)
      {
        flag = 1;
        int eliminazione = RiscriviElimina(i,num_righe,contatto);
        if(eliminazione != 0)
          printf("Eliminazione avvenuta con successo.");
        break;
      }
    }
    if(!flag)
      printf("Il contatto non e' stato trovato\n");
  }
  else
  {
    printf("Il file non è stato trovato o non puo' essere aperto.\n");
  }
  fclose(fpR);
  remove("rubrica.csv");
  rename("temp.csv","rubrica.csv");
}

int RiscriviElimina(int rigaEliminare, int num_righe, rubrica contatto)
{
  FILE* fpR = fopen("rubrica.csv", "r");
  FILE* fpW = fopen("temp.csv", "w");
  if(fpR == NULL)
  {
    printf("Errore di apertura del file.\n");
    return 0;
  }
  if(fpW == NULL)
  {
    printf("Errore di apertura del file temporaneo.\n");
    return 0;
  }
  for(int i=0;i<num_righe;i++)
  {
    fscanf(fpR,"%s %s %s %c",contatto.nome,contatto.cognome,contatto.telefono,&contatto.controllo);
    if(i!=rigaEliminare)
    {
      fprintf(fpW,"%-15s %-15s %-15s %c\n",contatto.nome,contatto.cognome,contatto.telefono,'-');
    }
  }
  fclose(fpW);
  fclose(fpR);

  return 1;
}

void VisualizzaRubrica()
{
  FILE* fpR;
  char buf[52]; //uno in più per il carattere terminatore (\0)
  char* res;

  fpR = fopen("rubrica.csv", "r");
  if(fpR != NULL)
  {
    res=fgets(buf,52,fpR); //52 perché lunghezza - 1
    while(res!=NULL)
    {
      printf("%s",res);
      res=fgets(buf,52,fpR);
    }
    fclose(fpR);
  }
  else
    printf("Il file non e' stato trovato o non puo' essere aperto");
}

void RichiestaModifica(FILE* fp, int riga, rubrica contatto)
{
  short scelta;
  do
  {
    puts("");
    printf("Cosa vuoi modificare?\n");
    printf("1. Nome e Cognome\n");
    printf("2. Telefono\n");

    scanf("%d",&scelta);
    if(scelta<0 || scelta>2)
      printf("Errore di digitazione. Riprova.\n");
  } while(scelta<0 || scelta>2);

  switch (scelta)
  {
    case 1:
            printf("Inserisci NOME e COGNOME\n");
            scanf("%s%s",contatto.nome,contatto.cognome);
            ModificaCampo(fp,riga,contatto);
        break;
    case 2:
            printf("Inserisci TELEFONO\n");
            scanf("%s",contatto.telefono);
            ModificaCampo(fp,riga,contatto);
        break;
  }
}

void ModificaCampo(FILE* fp, int riga, rubrica contatto)
{
  fseek(fp,riga*SIZE,SEEK_SET);
  fprintf(fp,"%-15s %-15s %-15s %c\n", contatto.nome, contatto.cognome, contatto.telefono, contatto.controllo);
}
