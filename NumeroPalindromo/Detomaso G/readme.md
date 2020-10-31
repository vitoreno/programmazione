# Numero Palindromo

**Obiettivo**: preso in input un numero da 5 cifre stabilre se è palindromo

**Osservazione**: per stabilre se un numero e' palindromo o meno, banalmente, è necessario controllare se esso letto al contrario è uguale al numero di partenza.

Nasce quindi il problema di invertire il numero di partenza. Un metodo efficace è il seguente: 

- Predisporre una variabile che conterrà il numero inverso da inizializzare a 0 (chiamiamola inverso)

- Ricavare dal numero di partenza, singolarmente, le sue cifre (calcolando il resto della divisione di quel numero per 10), memorizzando la **cifra** in una variabile

- Moltiplicare la variabile **inverso** per 10 e sommare ad essa la cifra ricavata precedentemente. Il risultato verrà assegnato alla stessa variabile **inverso** (che accumulerà le varie somme, risultando al termine del processo il numero "letto al contrario")
  
  ### Snippet operazione
  
  ```
  inverso = inverso * 10 + cifra;
  ```
  
  Queste operazioni presentate, ovviamente, dovranno essere inserite all'interno di un ciclo, che itera fino a quando la variabile contatore è minore del numero di cifre del numero che stiamo analizzando

Per questo problema verrà implementata una funzione, che chiameremo **invertiNumero**, di seguito il prototipo:

```
int invertiNumero(int n, nCifre);
```

### Variabili Main

| Nome variabile | Tipo | Scopo                               |
| -------------- | ---- | ----------------------------------- |
| nPal           | int  | Numero palindromo da analizzare     |
| numCifre       | int  | Conterrà il numero di cifre di nPal |

### Pseudocodice

INIZIO

- Dichiarazioni variabili 

- Scrivi "Inserire numero intero da massimo 5 cifre"

- Acquisisci nPal

- Calcola numero di cifre di nPal

- Finchè numCifre > 5
  
  - Scrivi "ERRORE - Inserire numero intero da massimo 5 cifre"
  
  - Acquisisci nPal

- Se nPal < 0 
  
  - nPal *= -1

- Se nPal == invertiNumero(nPal)
  
  - Scrivi "Il numero e' palindromo"

- Altrimenti 
  
  - Scrivi "Il numero non e' palindromo"

### Variabili funzione inverti numero

| cifra   | int | Cifra estratta da nPal                                                         |
| ------- | --- | ------------------------------------------------------------------------------ |
| i       | int | Contatore ciclo                                                                |
| inverso | int | Conterrà nPal "letto al contrario", e sarà il valore di ritorno della funzione |
| n       | int | Primo parametro di input: numero da invertire                                  |
| nCifre  | int | Secondo parametro di input: numero di cifre del numero n da invertire          |

### Pseudocodice funzione invertiNumero

**Prototipo:** invertiNumero(int n)

- Dichiarazione variabili i, inverso, cifra

- Inizializzazione a 0 delle variabili i e inverso

- Fai
  
  - cifra = nPal % 10
  
  - inverso = inverso * 10 + cifra
  
  - nPal /= 10
  
  - incremento contatore i

- Mentre i < numCifre

- Ritorna inverso
