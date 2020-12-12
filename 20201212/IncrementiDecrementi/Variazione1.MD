# Variazione 1
## Codice
```c
i = 0;
while (i++ <= 10)
	printf("%d\n", i);

printf("Valore di i in uscita dal ciclo %d\n", i);
```

******

## Flusso di esecuzione

- assegno 0 a i
- controllo la condizione di ciclo verificando se 0 <= 10
- incremento i di 1 unita'
- eseguo la printf stampando il valore di i (quindi 1)
- controllo la condizione di ciclo verificando se 1 <= 10
- incremento i di 1 unita'
- eseguo la printf stampando il valore di i (quindi 2)
- (...)
- controllo la condizione di ciclo verificando se 10 <= 10
- incremento i di 1 unita'
- eseguo la printf stampando il valore di i (quindi 11)
- controllo la condizione di ciclo verificando se 11 <= 10
- incremento i di 1 unita'
- eseguo la printf fuori dal ciclo stampando la scritta "Valore di i in uscita dal ciclo 12"