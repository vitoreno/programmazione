#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARTE 40

enum TipoPalo {DENARI, SPADE, COPPE, BASTONI};
enum NomeCarta {ASSO = 1, FANTE = 8, CAVALLO, RE};

void MescolaMazzo(int mazzo[]);
void PescaCarta(int mazzo[], int mano[]);
int SiGioca(int mano[]);
char* StampaPalo(int carta);
int ValoreCarta(int carta);
void StampaCarta(int carta);
int VerificaPresa(int carta1, int carta2, int idxGiocatoreDiMano, int paloBriscola);
int CalcolaPunti(int carta);
void StampaMano(int mano[], int idxGiocatore);