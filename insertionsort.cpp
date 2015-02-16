#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <chrono>
#include "insertionsort.h"

#define ARR_LENGTH 100

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int arrLength;
	if (argc > 1) arrLength = atoi(argv[1]);
	else arrLength = ARR_LENGTH;

	for(int i = 1; i <= 100; i++)
	{
		int *arr = new int[arrLength*i];
		for(int j = 0; j < arrLength*i; j++)
		{
			arr[j] = rand() % arrLength + 1;
		}
		auto t1 = chrono::high_resolution_clock::now();
		insertionSort(arr, arrLength*i);
		auto t2 = chrono::high_resolution_clock::now();
		cout << arrLength*i << "\t" << chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << endl;
		delete [] arr;
	}

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