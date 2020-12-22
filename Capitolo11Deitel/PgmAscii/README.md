# Programma per la scrittura di un file immagine .pgm ascii

Questo programma si propone di dimostrare come sia possibile scrivere un'immagine utilizzando un file di testo (ASCII).
L'immagine viene scritta in formato .pgm, maggiori dettagli al sito: https://en.wikipedia.org/wiki/Netpbm

## Esercizio
1. Compilare ed eseguire il codice main.c
2. Aprire il file SaltPepper.pgm con un editor di immagini (ad es. GIMP https://www.gimp.org/ ) e visualizzare il file
3. Creare una funzione per la scrittura di un array bidimensionale su un file .pgm ASCII. Tale funzione deve ricevere in input il nome del file da creare, l'array di dati da scrivere e le dimensioni colonne x righe richieste.
4. Modificare il codice main.c per utilizzare la funzione scritta al punto 3
5. Includere tale funzione nel programma ASCII-ART Paint oppure nell'esercizio 6.23 del Deitel&Deitel (Grafici a tartaruga)
6. Varie ed eventuali...