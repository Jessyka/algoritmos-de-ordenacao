#include <stdio.h>
#include <stdlib.h>

#include "math.h"
#include "Algoritmos.h"

void printVector(int numberlist[], int size)
{
	int i;
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("%d \t", numberlist[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	int numberlist[10] = { 5, 3, 6, 2, 10, 8, 27, 64, 9, 1 };
	int size = sizeof(numberlist) / sizeof(numberlist[0]);

	printVector(numberlist, size);

	bubbleSort(numberlist, size);
	//selectionSort(numberlist, size);
	//insertionSort(numberlist, size);

	//mergeSort(numberlist, size);
	

	printVector(numberlist, size);

	system("PAUSE");
}

