#include <iostream>
#include <ctime>

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = (p - 1);

	for(int j = p; j <= (r - 1); j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);
	return i + 1;
}

void quickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void printArr(int A[], int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << A[i] << ", ";
	}
	std::cout << std::endl;
}

int main()
{

	std::clock_t start;
	srand(time(NULL));
	int arr[1000000];

	// populate array with 1000000 random values 
	// between 1 and 1000
	for (int i = 0; i < 1000000; i++)
	{
		arr[i] = rand() % 1000 + 1;
	}

	start = std::clock();
	quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);

	std::cout << "Time to sort 1000000 integers: " <<
	  (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

}
