# Approssimazione del numero di Nepero

Obiettivo: valutare il valore della costante numerica e (numero di nepero).

Prima di poter calcolare il numero di Nepero, è necessario calcolare il fattoriale. 

## Formule da usare

**Fattoriale**:

$$
!n = (n-1) * (n-2) * ... *1
$$

**Nepero**: 

$$
e = 1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + ...
$$

Per tanto in via assolutamente generale i passi per poter risolvere il problema sono:

### Pseudocodice

1) Dichiarazioni variabili

2) Inizializzazione variabili 

3) Processing

4) Stampa risultati

Diamo ora una definizione più precisa di questi passaggi:

INIZIO

- Dichiarazione variabili intere relative a: fattoriale, numero di iterazioni
- Dichiarare i contatori (i e j)
- Dichiarare una variabile float che conterrà il numero di Nepero approssimato
- Inizializzare i contatori la variabile del fattoriale e della costante di nepero  a 1 (I motivi saranno spiegati in seguito)
- Stampare "Inserire un numero di iterazioni compreso tra 1 e 8"
- Acquisire il numero n di iterazioni 
- Cicla finchè la variabile contatore i non è maggiore o uguale del numero di iterazioni n
  - Calcolare il fattoriale e salvare il risultato nella variabile relativa (Procedura descritta in seguito)
  - Calcolare il numero di Nepero effetuando un casting a float il risultato
  - Incrementare i 
  - Riassegnare a j il valore 1
- Stampare "Il numero di nepero è ..."

FINE

**Pseudocodice del fattoriale**

Per essere ancora più precisi andiamo a definire il modo in cui calcolare il fattoriale, ma occorre fare una precisazione: il numero del quale calcolare il fattoriale risulterà essere proprio il contatore **i** usato nel ciclo principale. 

Tale pseudocodice è da sostituire in quello principale nella sezione "Calcolare il fattoriale e salvare il risultato nella variabile relativa".

INIZIO

- Cicla finchè il contatore j non diventa > di **i** del quale calcolare il fattoriale
  
  - Se j = 1 
    
    - fattoriale = i * (i - j)
  
  - Altrimenti 
    
    - fattoriale = fattoriale * (i - j)
  
  - incrementa il contatore **j**

## Uso Variabili

| Variabile  | Scopo                                                                                        |
| ---------- | -------------------------------------------------------------------------------------------- |
| n          | Numero di iterazioni (acquisito in input)                                                    |
| fattoriale | Fattoriale di un numero i                                                                    |
| i          | Contatore del ciclo principale e contemporaneamente numero del quale calcolare il fattoriale |
| j          | Contatore del ciclo per il calcolo del fattoriale                                            |
| nepero     | Costante del quale approssimare il valore                                                    |
