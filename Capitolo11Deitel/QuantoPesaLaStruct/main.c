/*
	Quanto pesano le struct cosi' dichiarate???
*/
#include <stdio.h>

typedef struct Interi_
{
	int a;
	int b;
} Interi;

typedef struct InteriChar_
{
	int a;
	int b;
	char c;
} InteriChar;

typedef struct InteriCharInMezzo_
{
	int a;
	char c;
	int b;
} InteriCharInMezzo;

typedef struct InteriCharInMezzo2_
{
	int a;
	char c;
	char d;
	int b;
} InteriCharInMezzo2;

typedef struct InteriCharInMezzo3_
{
	int a;
	char c;
	int b;
	char d;
} InteriCharInMezzo3;

int main()
{
	printf("Quanto pesa la struct?\n\n");
	printf("%-20s - %4d byte\n", "Interi", sizeof(Interi));
	printf("%-20s - %4d byte\n", "InteriChar", sizeof(InteriChar));
	printf("%-20s - %4d byte\n", "InteriCharInMezzo", sizeof(InteriCharInMezzo));
	printf("%-20s - %4d byte\n", "InteriCharInMezzo2", sizeof(InteriCharInMezzo2));
	printf("%-20s - %4d byte\n", "InteriCharInMezzo3", sizeof(InteriCharInMezzo3));

	return 0;
}