#include<stdlib.h> 
#include<stdio.h> 
#include "Algoritmos.h"

void bubbleSort(int numberList[], int size)
{
	int i, j, aux;

	for (i = 0; i < size - 1; i++){
		for (j = (i + 1); j < size; j++){
			if (numberList[j] < numberList[i]){

				aux = numberList[i];
				numberList[i] = numberList[j];
				numberList[j] = aux;
			}
		}
	}
}

void insertionSort(int numberList[], int size)
{
	int i, j, key;
	
	for (i = 1; i < size; i++)
	{
		key = numberList[i];
		j = i - 1;

		while (j >= 0 && numberList[j] > key)
		{
			numberList[j + 1] = numberList[j];
			j--;
			
		}

		numberList[j + 1] = key;
	}
}

void selectionSort(int numberList[], int size)
{
	int i, indMenor, j;

	for (i = 0; i < size; ++i) {
		indMenor = i;

		for (int j = i + 1; j < size; ++j) {
			if (numberList[j] < numberList[indMenor]) {
				indMenor = j;
			}
		}

		int aux = numberList[i];
		numberList[i] = numberList[indMenor];
		numberList[indMenor] = aux;
	}
}

void merge(int numberList[], int start, int middle, int end) {
	
	int index1 = start, index2 = middle + 1, indexAux = 0, size = end - start + 1;

	int *vetAux;
	vetAux = (int*)malloc(size * sizeof(int));

	while (index1 <= middle && index2 <= end)
	{
		if (numberList[index1] < numberList[index2]) 
		{
			vetAux[indexAux] = numberList[index1];
			index1++;
		}
		else 
		{
			vetAux[indexAux] = numberList[index2];
			index2++;
		}

		indexAux++;
	}

	while (index1 <= middle)
	{
		vetAux[indexAux] = numberList[index1];
		indexAux++;
		index1++;
	}

	while (index2 <= end) 
	{
		vetAux[indexAux] = numberList[index2];
		indexAux++;
		index2++;
	}

	for (indexAux = start; indexAux <= end; indexAux++)
	{  
		numberList[indexAux] = vetAux[indexAux - start];
	}

	free(vetAux);
}

void mergeSortAux(int numberList[], int start, int end){

	if (start < end) 
	{
		int aux = (end + start) / 2;

		mergeSortAux(numberList, start, aux);
		mergeSortAux(numberList, aux + 1, end);
		merge(numberList, start, aux, end);
	}
}

void mergeSort(int numberList[], int size)
{
	mergeSortAux(numberList, 0, size - 1);
}