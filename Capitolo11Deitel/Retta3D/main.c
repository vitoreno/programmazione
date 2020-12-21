/*
	Programma per la creazione di un file obj contenente
	i punti appartenenti a una retta nello spazio 3D.

	Il file obj e' un file di testo in cui ogni riga che incomincia con # viene ignorata (commento)
	e ogni vertice puo' essere rappresentato su una riga formattata nel seguente modo:
	v <x:float> <y:float> <z:float>

	Si utilizza l'equazione parametrica della retta 3D al variare del parametro t tra -100 e 100
	https://www.youmath.it/lezioni/algebra-lineare/geometria-dello-spazio/677-formule-per-le-equazioni-parametriche-della-retta.html
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Vettore3D_
{
	float x;
	float y;
	float z;
} Vettore3D;

int main()
{
	Vettore3D Punto, Direzione, tmp;
	int t;
	FILE* pObj;

	pObj = fopen("Retta3D.obj", "w");

	if (pObj != NULL)
	{
		printf("Inserire un punto appartenente alla retta (x y z): ");
		scanf("%f %f %f", &Punto.x, &Punto.y, &Punto.z);

		printf("Inserire una direzione (componenti di un vettore parallelo alla retta): ");
		scanf("%f %f %f", &Direzione.x, &Direzione.y, &Direzione.z);

		fprintf(pObj, "# File obj per disegnare la retta 3D passante per il punto\n");
		fprintf(pObj, "# di coordinate (x, y, z) = (%f, %f, %f)\n", Punto.x, Punto.y, Punto.z);
		fprintf(pObj, "# e parallelo al vettore di componenti (l, m, n) = (%f, %f, %f)\n", Direzione.x, Direzione.y, Direzione.z);
		for (t = -100; t <= 100; t++)
		{
			tmp.x = Punto.x + Direzione.x * t;
			tmp.y = Punto.y + Direzione.y * t;
			tmp.z = Punto.z + Direzione.z * t;
			fprintf(pObj, "v %f %f %f\n", tmp.x, tmp.y, tmp.z);
		}
		fprintf(pObj, "# Fine del file ob\n");

		fclose(pObj);
	}
	else
		printf("Impossibile aprire il file Retta3D.obj\n");

	

	return 0;
}