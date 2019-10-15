#include <assert.h>
#include <iostream>
#include <ctime>

void printArr(int A[], int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << A[i] << ", ";
	}
	std::cout << std::endl;
}

void merge(int A[], int leftFirst, int leftLast, int rightFirst, int rightLast, int auxA[])
{
	int index = leftFirst;
	int saveFirst = leftFirst;

	while((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (A[leftFirst] < A[rightFirst])
		{
			auxA[index] = A[leftFirst];
			leftFirst++;
		}
		else
		{
			auxA[index] = A[rightFirst];
			rightFirst++;
		} 
		index++;
	}

	// copy remaining items from left half
	while(leftFirst <= leftLast)
	{
		auxA[index] = A[leftFirst];
		leftFirst++;
		index++;
	}

	// copy remaining items from right half
	while(rightFirst <= rightLast)
	{
		auxA[index] = A[rightFirst];
		rightFirst++;
		index++;
	}

	// copy values back to original array
	for(index = saveFirst; index <= rightLast; index++)
	{
		A[index] = auxA[index];
	}

}

void mergeSort(int A[], int first, int last, int auxA[])
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		mergeSort(A, first, middle, auxA);
		mergeSort(A, middle + 1, last, auxA);
		merge(A, first, middle, middle + 1, last, auxA);
	}
}

void testSort(int A[], int size)
{
	int k = -1;
	for(int i = 0; i < size; i++)
	{
		if (k > 0)
		{
			assert(A[i] >= k);

		}
		k = A[i];
	}
}

int main()
{

	std::clock_t start;
	srand(time(NULL));
	int arr[1000000];
	int auxArr[1000000];

	// populate array with 1000000 random values 
	// between 1 and 1000
	for (int i = 0; i < 1000000; i++)
	{
		arr[i] = rand() % 1000 + 1;
	}

	int arrSize = sizeof(arr)/sizeof(arr[0]);

	start = std::clock();
	mergeSort(arr, 0, arrSize - 1, auxArr);

	std::cout << "Time to sort 1000000 integers: " <<
	  (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	testSort(arr, arrSize);

}
