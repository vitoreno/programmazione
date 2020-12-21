# Scrittura di un file .obj
Programma per la creazione di un file obj contenente i punti appartenenti a una retta nello spazio 3D.

## Breve (brevissima) panoramica sul formato obj
Il file obj e' un file di testo in cui:
- ogni riga che incomincia con # viene ignorata (commento)
- ogni vertice puo' essere rappresentato su una riga formattata nel seguente modo **v <x:float> <y:float> <z:float>**

Si utilizza l'equazione parametrica della retta 3D al variare del parametro t tra -100 e 100
https://www.youmath.it/lezioni/algebra-lineare/geometria-dello-spazio/677-formule-per-le-equazioni-parametriche-della-retta.html