// Del Basso Raffaele - Esercitazione del 27/11/2020

#include <stdio.h>
#include <stdlib.h>
// Dichiarazione delle costanti
#define N 20
#define M 20
#define EMPTYCHAR '-'
#define DEFAULTCHAR '+'

void cancellaTela(char[N][M]);
void sostituisciTela(char[N][M], char);
void disegnaPunto(char[N][M], int, int, char);
void disegnaLinea(char[N][M], int, int, int, int, char);
void disegnaRettangolo(char[N][M], int, int, int, int, char);
void disegnaCirconferenza(char[N][M], int, int, int, char);
void disegnaX(char[N][M], int, int, int, char);
void visualizzaTela(char[N][M]);
void sostituisciCaratteri(char[N][M], char, char);
int trovaCarattere(char[N][M], char);

enum Direzioni {SU = 1, DESTRA, GIU, SINISTRA, SU_DESTRA, GIU_DESTRA, GIU_SINISTRA, SU_SINISTRA};
enum Scelte {CAMBIA_CARATTERE = 1, CANCELLA_TELA, DISEGNA_PUNTO, DISEGNA_LINEA, DISEGNA_RETTANGOLO, DISEGNA_CIRCONFERENZA, DISEGNA_X, VISUALIZZA_TELA, SOSTITUISCI_CARATTERI, ESCI};

int main()
{
    /*
        Conviene dichiarare l'array bidimensionale
        di tipo char e non di tipo int, per due ragioni:
        1. Un char occupa 1 byte mentre un intero occupa 4 byte,
           quindi si ha un risparmio di memoria direttamente proporzionale
           alla dimensione della matrice.
        2. Se dichiarassimo la matrice di tipo int, per decidere se stampare
           il carattere che indica "il quadratino vuoto" o quello che indica
           "il quadratino pieno", bisognerebbe fare un if per ogni cella della matrice:
           if (tela[i][j] == 0)
              stampa "quadratino vuoto"
           else
              stampa "quadratino pieno"
           Dichiarando l'array bidimensionale direttamente di tipo char,
           questo controllo è superfluo in quanto si può direttamente
           stampare il contenuto della cella, senza fare alcun controllo.
    */
    char tela[N][M];
    char carattere = DEFAULTCHAR;
    int scelta;
    char scelta2;
    int i;
    int j;
    int lunghezza;
    int direzione;
    int base;
    int altezza;
    int raggio;
    int tuttoOk;
    char carattereDaSostituire;
    char carattereSostituto;
    int carattereTrovato;
    int telaVuota;
    cancellaTela(tela);
    telaVuota = 1;
    do {
        printf("-------- MENU PRINCIPALE --------\n");
        printf("1. Cambia carattere con cui disegnare (attuale: %c): \n", carattere);
        printf("2. Cancella tela\n");
        printf("3. Disegna punto\n");
        printf("4. Disegna linea\n");
        printf("5. Disegna rettangolo\n");
        printf("6. Disegna circonferenza\n");
        printf("7. Disegna X\n");
        printf("8. Visualizza tela\n");
        printf("9. Sostituisci caratteri\n");
        printf("10. Esci\n\n");

        printf("Inserisci scelta: ");
        scanf("%d", &scelta);

        printf("\n");
        switch(scelta) {
        case CAMBIA_CARATTERE:
            // Cambio del carattere. Chiedo all'utente il nuovo carattere con cui disegnare,
            // assicurandomi che non inserisca lo stesso carattere utilizzato per indicare le celle vuote (EMPTYCHAR).
            printf("-------- CAMBIO DEL CARATTERE --------\n");
            do {
                printf("Inserisci nuovo carattere: ");
                scanf(" %c", &carattere);
                if (carattere == EMPTYCHAR) {
                    printf("Non puoi usare lo stesso carattere che indica le celle vuote.\n");
                }
            } while (carattere == EMPTYCHAR);
            // Funzionalità aggiuntiva: chiedo all'utente se vuole che il nuovo carattere rimpiazzi
            // tutti i caratteri precedenti.
            if (!telaVuota) {
                do {
                    printf("Vuoi che il nuovo carattere sostituisca tutte le celle? [Y/N] ");
                    scanf(" %c", &scelta2);
                } while (scelta2 != 'Y' && scelta2 != 'N');
                if (scelta2 == 'Y') {
                    sostituisciTela(tela, carattere);
                }
            }
            printf("Carattere sostituito.\n");
            break;
        case CANCELLA_TELA:
            // Cancellazione della tela. E' possibile cancellare la tela
            // solo se non è vuota. La richiesta viene fatta mediante l'inserimento di Y o N,
            // per evitare cancellazioni indesiderate.
            printf("-------- CANCELLAZIONE DELLA TELA --------\n");
            if (!telaVuota) {
                do {
                    printf("Sei sicuro di voler cancellare la tela? [Y/N] ");
                    scanf(" %c", &scelta2);
                } while (scelta2 != 'Y' && scelta2 != 'N');
                if (scelta2 == 'Y') {
                    cancellaTela(tela);
                    telaVuota = 1;
                    printf("Tela cancellata.\n");
                }
            } else {
                printf("La tela e' vuota.\n");
            }
            break;
        case DISEGNA_PUNTO:
            // Disegno di un punto. Chiedo all'utente le coordinate i e j,
            // mostrando in tempo reale il valore massimo che può inserire,
            // il quale dipende ovviamente dalla dimensione della matrice.
            // In questo modo l'utente sa che non può andare oltre la matrice.
            // Tale controllo sarà fatto chiaramente per ogni figura.
            printf("-------- DISEGNA PUNTO --------\n");
            do {
                printf("Inserisci coordinata i (limite: %d): ", N-1);
                scanf("%d", &i);
            } while (i < 0 || i > N-1);
            do {
                printf("Inserisci coordinata j (limite: %d): ", M-1);
                scanf("%d", &j);
            } while (j < 0 || j > M-1);
            disegnaPunto(tela, i, j, carattere);
            printf("Punto disegnato.\n");
            telaVuota = 0;
            break;
        case DISEGNA_LINEA:
            // Disegno di una linea. Anche qui chiedo le coordinate i e j
            // con gli stessi controlli fatti per il punto.
            printf("-------- DISEGNA LINEA --------\n");
            do {
                printf("Inserisci coordinata i dell'origine (limite: %d): ", N-1);
                scanf("%d", &i);
            } while (i < 0 || i > N-1);
            do {
                printf("Inserisci coordinata j dell'origine (limite: %d): ", M-1);
                scanf("%d", &j);
            } while (j < 0 || j > M-1);
            // Nessun controllo effettuato per la lunghezza della linea.
            // Se la lunghezza farà in modo che la linea vada oltre la matrice,
            // semplicemente la linea non verrà disegnata per intero.
            // Questa cosa è gestita nella funzione disegnaLinea.
            printf("Inserisci lunghezza linea: ");
            scanf("%d", &lunghezza);
            // Visualizzazione del menu per le direzioni della linea.
            // In aggiunta alle quattro direzioni standard, ho aggiunto anche le diagonali.
            printf("Direzione:\n");
            printf("1. Su\n");
            printf("2. Destra\n");
            printf("3. Giu'\n");
            printf("4. Sinistra\n");
            printf("5. In alto a destra\n");
            printf("6. In basso a destra\n");
            printf("7. In basso a sinistra\n");
            printf("8. In alto a sinistra\n");
            do {
                printf("\nInserisci direzione: ");
                scanf("%d", &direzione);
            } while (direzione < SU || direzione > SU_SINISTRA);
            disegnaLinea(tela, i, j, lunghezza, direzione, carattere);
            printf("Linea disegnata.\n");
            telaVuota = 0;
            break;
        case DISEGNA_RETTANGOLO:
            // Disegno di un rettangolo (o quadrato). Anche qui chiedo le coordinate i e j del vertice top-left.
            printf("-------- DISEGNA RETTANGOLO --------\n");
            do {
                printf("Inserisci coordinata i del vertice top-left (limite: %d): ", N-1);
                scanf("%d", &i);
            } while (i < 0 || i > N-1);
            do {
                printf("Inserisci coordinata j del vertice top-left (limite: %d): ", M-1);
                scanf("%d", &j);
            } while (j < 0 || j > M-1);
            // Qui effettuo il controllo per fare in modo che la base e l'altezza non vadano
            // oltre la dimensione consentita dalla matrice, per fare in modo che il rettangolo
            // (o il quadrato) disegnato non sia mai incompleto.
            do {
                printf("Inserisci lunghezza base (limite: %d): ", (M-j));
                scanf("%d", &base);
            } while (base < 1 || base > M-j);
            do {
                printf("Inserisci lunghezza altezza (limite: %d): ", (N-i));
                scanf("%d", &altezza);
            } while (altezza < 1 || altezza > N-i);
            disegnaRettangolo(tela, i, j, base, altezza, carattere);
            printf("Quadrato disegnato.\n");
            telaVuota = 0;
            break;
        case DISEGNA_CIRCONFERENZA:
            // Disegno di una circonferenza. Chiedo le coordinate del centro.
            do {
                printf("Inserisci coordinata i del centro (limite: %d): ", N-1);
                scanf("%d", &i);
            } while (i < 0 || i > N-1);
            do {
                printf("Inserisci coordinata j del centro (limite: %d): ", M-1);
                scanf("%d", &j);
            } while (j < 0 || j > M-1);
            // Con un ciclo do... while, mi assicuro che l'utente inserisca una lunghezza
            // del raggio tollerabile per la matrice.
            do {
                // Ho utilizzato una variabile sentinella in quanto
                // i controlli sono numerosi. In questo modo, evito che nel while
                // la CPU debba rifare i 4 controlli che ci sono. La variabile
                // prende il valore 0 se c'è qualcosa che non va, e poi nella condizione del while
                // andrò a fare il controllo sulla variabile sentinella, senza rifare
                // tutti i vari controlli.
                tuttoOk = 1;
                printf("Inserisci lunghezza del raggio: ");
                scanf("%d", &raggio);
                if ((i-raggio >= 0 && i+raggio < N) && (j-raggio >= 0 && j+raggio < M)) {
                    disegnaCirconferenza(tela, i, j, raggio, carattere);
                    printf("Circonferenza disegnata.\n");
                    telaVuota = 0;
                } else {
                    printf("Il raggio e' troppo grande.\n");
                    tuttoOk = 0;
                }
            } while (!tuttoOk);
            break;
        case DISEGNA_X:
            // Figura aggiuntiva: X. Chiedo le coordinate del centro.
            printf("-------- DISEGNA X --------\n");
            do {
                printf("Inserisci coordinata i del centro (limite: %d): ", N-1);
                scanf("%d", &i);
            } while (i < 0 || i > N-1);
            do {
                printf("Inserisci coordinata j del centro (limite: %d): ", M-1);
                scanf("%d", &j);
            } while (j < 0 || j > M-1);
            // Stessa cosa per la circonferenza: ciclo do... while per impedire che
            // la X vada oltre la dimensione consentita dalla matrice.
            do {
                tuttoOk = 1;
                printf("Inserisci lunghezza della X: ");
                scanf("%d", &lunghezza);
                // La lunghezza deve essere necessariamente dispari: caratteristica tipica di una X.
                if (lunghezza % 2 == 1) {
                    // Poiché la X parte dal punto centrale, divido la lunghezza per due e controllo
                    // se tale lunghezza va oltre le dimensioni della matrice oppure no.
                    lunghezza = lunghezza/2;
                    if ((i-(lunghezza) >= 0 && i+(lunghezza) < N) && (j-lunghezza >= 0 && j+lunghezza < M)) {
                        disegnaX(tela, i, j, lunghezza, carattere);
                        printf("X disegnata.\n");
                        telaVuota = 0;
                    } else {
                        printf("La lunghezza e' troppo grande.\n");
                        tuttoOk = 0;
                    }
                } else {
                    printf("La lunghezza della X deve essere dispari.\n");
                    tuttoOk = 0;
                }
            } while (!tuttoOk);
            break;
        case VISUALIZZA_TELA:
            // Visualizza tela. Semplice richiamo della funzione visualizzaTela, passandole la matrice.
            visualizzaTela(tela);
            break;
        case SOSTITUISCI_CARATTERI:
            // Funzionalità aggiuntiva: sostituzione dei caratteri.
            printf("-------- SOSTITUISCI CARATTERI --------\n");
            // Se la tela non è vuota
            if (!telaVuota) {
                // Chiedo quale carattere l'utente vuole sostituire.
                // Non è ammesso che l'utente inserisca lo stesso carattere
                // che indica le celle vuote, così come non è ammesso che l'utente
                // inserisca un carattere che non è presente nella matrice.
                // Per compiere questa azione, ho realizzato la funzione apposita trovaCarattere.
                do {
                    printf("Inserisci carattere da sostituire: ");
                    scanf(" %c", &carattereDaSostituire);
                    if (carattereDaSostituire == EMPTYCHAR) {
                        printf("Non puoi sostituire il carattere che indica le celle vuote.\n");
                        carattereTrovato = 0;
                    } else {
                        if (!trovaCarattere(tela, carattereDaSostituire)) {
                            carattereTrovato = 0;
                            printf("Il carattere inserito non si trova sulla tela.\n");
                        } else {
                            carattereTrovato = 1;
                        }
                    }
                } while (!carattereTrovato);
                // Per il carattere sostituto, invece, il controllo è uno solo:
                // L'utente non può inserire lo stesso carattere usato per indicare le celle vuote.
                do {
                    printf("Inserisci carattere da sostituire a '%c': ", carattereDaSostituire);
                    scanf(" %c", &carattereSostituto);
                    if (carattereSostituto == EMPTYCHAR) {
                        printf("Non puoi usare lo stesso carattere che indica le celle vuote.\n");
                    }
                } while (carattereSostituto == EMPTYCHAR);
                sostituisciCaratteri(tela, carattereDaSostituire, carattereSostituto);
                printf("Tutte le occorrenze di '%c' sono state sostituite con '%c'.\n", carattereDaSostituire, carattereSostituto);
            } else {
                printf("La tela e' vuota. Nessun carattere da sostituire.\n");
            }
            break;
        }
        printf("\n");
    } while (scelta != ESCI);
    return 0;
}

// Funzione cancellaTela: riceve la matrice e imposta ogni cella al carattere vuoto.
void cancellaTela(char tela[N][M]) {
    int i;
    int j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            tela[i][j] = EMPTYCHAR;
        }
    }
}

// Funzione sostituisciTela: sostituisce ogni carattere della tela con il carattere passato come secondo parametro.
void sostituisciTela(char tela[N][M], char carattere) {
    int i;
    int j;
    for(i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            if (tela[i][j] != EMPTYCHAR) {
                tela[i][j] = carattere;
            }
        }
    }
}

// Funzione disegnaPunto: riceve la tela, le coordinate e il carattere.
void disegnaPunto(char tela[N][M], int i, int j, char carattere) {
    tela[i][j] = carattere;
}

// Funzione disegnaLinea: riceve la tela, le coordinate di partenza, la lunghezza, la dimensione e il carattere.
void disegnaLinea(char tela[N][M], int i, int j, int lunghezza, int direzione, char carattere) {
    int cont;
    cont = 0;
    // Il ciclo while consente di fermare il disegno della linea se le coordinate vanno oltre
    // la dimensione consentita dalla matrice.
    while (cont != lunghezza && (i >= 0 && i < N) && (j >= 0 && j < M)) {
        tela[i][j] = carattere;
        // Lo switch, in base alla direzione scelta, consente a i e a j di andare in direzioni diverse,
        // per fare in modo che il prossimo punto sia disegnato nella posizione corretta.
        switch(direzione) {
        case SU:
            i--;
            break;
        case DESTRA:
            j++;
            break;
        case GIU:
            i++;
            break;
        case SINISTRA:
            j--;
            break;
        case SU_DESTRA:
            i--;
            j++;
            break;
        case GIU_DESTRA:
            i++;
            j++;
            break;
        case GIU_SINISTRA:
            i++;
            j--;
            break;
        case SU_SINISTRA:
            i--;
            j--;
            break;
        }
        cont++;
    }
}

// Funzione disegnaRettangolo: riceve la tela, le coordinate del vertice top-left, base e altezza e il carattere.
void disegnaRettangolo(char tela[N][M], int i, int j, int base, int altezza, char carattere) {
    int k;
    int l;
    // Ciclo for che disegna il lato di sinistra e il lato di destra.
    for (k=0; k<altezza; k++) {
        tela[k+i][j] = carattere;
        tela[k+i][j+base-1] = carattere;
    }

    // Ciclo for che disegna il lato di sopra e il lato di sotto.
    for (l=0; l<base; l++) {
        tela[i][j+l] = carattere;
        tela[i+altezza-1][j+l] = carattere;
    }
}

// Funzione disegnaCirconferenza: riceve la tela, le coordinate del centro
// (che sono invertite perché la i in realtà è la y, mentre la j è la x), il raggio e il carattere.
void disegnaCirconferenza(char tela[N][M], int yCentro, int xCentro, int raggio, char carattere) {
    int i;
    int j;
    // Si crea una sottomatrice che non è altro che il quadrato circoscritto alla circonferenza
    // che si verrà a creare.
    for (i=yCentro - raggio; i<=yCentro + raggio; i++) {
        for (j=xCentro - raggio; j<=xCentro + raggio; j++) {
            // Per ogni cella della sottomatrice, controllo, grazie all'equazione della circonferenza,
            // se la cella appartiene alla circonferenza. Se così è, allora disegno il carattere.
            if (((j - xCentro) * (j - xCentro) + (i - yCentro) * (i - yCentro)) <= raggio * raggio) {
                tela[i][j] = carattere;
            }
        }
    }
}

// Funzione disegnaX: riceve la tela, le coordinate del centro (sempre invertite), la lunghezza e il carattere.
void disegnaX(char tela[N][M], int yCentro, int xCentro, int lunghezza, char carattere) {
    // La X è composta da due linee diagonali. Perciò posso richiamare la funzione disegnaLinea
    // per disegnarle, andando a variare le coordinate e la direzione.
    disegnaLinea(tela, yCentro - lunghezza, xCentro - lunghezza, lunghezza * 2 + 1, GIU_DESTRA, carattere);
    disegnaLinea(tela, yCentro - lunghezza, xCentro + lunghezza, lunghezza * 2 + 1, GIU_SINISTRA, carattere);
}

// Funzione visualizzaTela: riceve solo la tela.
void visualizzaTela(char tela[N][M]) {
    // La funzione mostra anche i vari indici nella parte di sinistra e nella parte alta della matrice.
    int i, j;
    printf("   ");
    for (i=0; i<M; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (i=0; i<N; i++) {
        printf("%2d ", i);
        for (j=0; j<M; j++) {
            printf("%2c ", tela[i][j]);
        }
        printf("\n");
    }
}

// Funzione sostituisciCaratteri: riceve la tela, il carattere da sostituire e il carattere sostituto.
void sostituisciCaratteri(char tela[N][M], char daSostituire, char sostituto) {
    int i;
    int j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            if (tela[i][j] == daSostituire) {
                tela[i][j] = sostituto;
            }
        }
    }
}

// Funzione trovaCarattere: riceve la tela e il carattere da trovare.
// Restituisce 0 se il carattere non è presente nella matrice, e restituisce 1 altrimenti.
int trovaCarattere(char tela[N][M], char carattere) {
    int trovato = 0;
    int i;
    int j;
    i = 0;
    // I due cicli si interrompono non appena il carattere viene trovato.
    while (!trovato && i<N) {
        j=0;
        while (!trovato && j<M) {
            if (tela[i][j] == carattere) {
                trovato = 1;
            }
            j++;
        }
        i++;
    }
    return trovato;
}
