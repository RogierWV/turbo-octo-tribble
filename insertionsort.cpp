#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "insertionsort.h"

#define ARR_LENGTH 100

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int arrLength;
	if (argc > 1) arrLength = atoi(argv[1]);
	else arrLength = ARR_LENGTH;

	int *arr = new int[arrLength];
	cout << "Unsorted: ";
	for(int i = 0; i < arrLength; i++)
	{
		arr[i] = rand() % arrLength + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	insertionSort(arr, arrLength);

	cout << "Sorted: ";

	for(int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	delete [] arr;
	return 0;
}

void insertionSort(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		int x = arr[i];
		int j = i;
		while(j>0 && arr[j-1]>x)
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = x;
	}
}