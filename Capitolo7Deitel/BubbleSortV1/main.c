#include <stdio.h>
#define N 5

void StampaVettore(int* vet, const int dim);
void BubbleSort(int* vet, const int dim);


int main()
{
	int arr[N] = { 10, 7, 5, 2, 1 };
	StampaVettore(arr, N);
	BubbleSort(arr, N);
	StampaVettore(arr, N);
	return 0;
}

void StampaVettore(int* vet, const int dim)
{
	printf("\n");
	for (int i = 0; i < dim; i++)
		printf("%5d", vet[i]);
	printf("\n");
}

void BubbleSort(int* vet, const int dim)
{
	void Scambia(int* pA, int* pB);
	int passi, i;

	for (passi = 0; passi < dim - 1; passi++)
		for (i = 0; i < dim - 1; i++)
			if (vet[i] > vet[i + 1])
				Scambia(&vet[i], &vet[i + 1]);
}

void Scambia(int* pA, int* pB)
{
	int appoggio = *pA;
	*pA = *pB;
	*pB = appoggio;
}