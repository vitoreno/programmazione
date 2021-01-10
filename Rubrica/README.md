# Rubrica personalizzata

## Dettagli
Ho voluto gestire una rubrica in un file che potesse essere implementato, con una piccola query, in Excel, così da creare una tabella automatizzata contenente nome, cognome e numero di telefono del contatto.
Ho utilizzato i file ad accesso sequenziale, inserendo un "carattere di controllo" alla fine di ogni riga, così da avere una dimensione fissa per record. In questo modo sono riuscito a muovermi facilmente con il carrello e l'fseek.

## Credits
Esercitazione a cura di Simone Le Noci.

## Suggerimenti per la lettura critica e migliorie

* Utilizzare per esercizio i file binari al posto dei file di testo, anche per scrivere delle struct contenenti sole stringhe
* Utilizzare alcune funzioni per la manipolazione delle stringhe