# Esempi di apertura dei file di testo

Il codice e' formato da un'unica funzione main contenente esempi di apertura di file di testo in modalita' "w", "r", "a+"
Per quel che riguarda la modalita' append+ si riporta uno stralcio della documentazione in cui si osserva la necessita'
di riposizionare manualmente il File Position Pointer (mediante funzione fseek, per esempio) nel caso in cui la scrittura
segua una operazione di lettura.

## Modifiche al codice lasciate per esercizio
1. Codificare una o piu' funzioni per snellire il main (suggerimento: creare ad esempio una funzione per la lettura di un file un intero per volta, stampando un messaggio ulteriore nel caso in cui si localizzi una sentinella come 555)
2. Verificare il comportamento del file in modalita' "a+" quando una operazione di lettura segue una operazione di scrittura.