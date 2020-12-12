# Appunti
## Equivalenza tra for e while
```c
for (i = 0; i <= 10; i++)
	printf("%9d %9d %9d\n", i, i*i, i*i*i);
```

```c
// Questo while e' equivalente al for precedente
i = 0;
while(i <= 10)
{
	printf("%9d %9d %9d\n", i, i*i, i*i*i);
	
	i++;
}
```

****************

## Cosa succede alla variabile i e qual e' la sequenza di operazioni effettuate???

- i	0
- controllo la condizione del ciclo -> ENTRO
- eseguo la printf
- i	1
- controllo la condizione del ciclo -> ENTRO
- eseguo la printf
- i	2
- (...)
- i	9
- controllo la condizione del ciclo -> ENTRO
- eseguo la printf
- i	10
- controllo la condizione del ciclo -> ENTRO
- eseguo la printf
- i	11
- controllo la condizione del ciclo -> ESCO