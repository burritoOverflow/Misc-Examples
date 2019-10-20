#include <assert.h>
#include <iostream>
#include <ctime>

// utility functions
void printArr(int A[], int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << A[i] << ", ";
	}
	std::cout << std::endl;
}


// verify that the array is sorted after
// invoking a sorting algorithm.
// run once per algorithm
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


// merge sort
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


// heap sort
int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

void maxHeapify(int A[], int n, int i)
{
	int l = left(i);
	int r = right(i);
	int largest = 0;

	if (l <= (n - 1) && A[l] > A[i]) 
	{
		largest = l;
	}
	else 
	{
		largest = i;
	}
	
	if (r <= (n - 1) && A[r] > A[largest]) 
	{
		largest = r;
	}
	
	if (largest != i) 
	{
		std::swap(A[i], A[largest]);
		maxHeapify(A, n, largest);
	}
}

void buildMaxHeap(int A[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--) {
    maxHeapify(A, n, i);
  }
}

void heapsort(int A[], int n)
{
  buildMaxHeap(A, n);
  for (int i = n - 1; i > 0; i--)
  {
    std::swap(A[0], A[i]);
    maxHeapify(A, --n, 0);
  }
}


// quick sort
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

// used to populate array with random values between
// 1 and 1000
void populateArrRandom(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 1000 + 1;
	}
}

int main()
{

	std::clock_t start;
	srand(time(NULL));

	// used throughout, populated with random values 
	// prior to each sorting algorithm
	int arr[1000000];
	int auxArr[1000000];

	int arrSize = sizeof(arr)/sizeof(arr[0]);

	// populate array for mergesort
	populateArrRandom(arr, arrSize);

	// section mergesort
	start = std::clock();
	mergeSort(arr, 0, arrSize - 1, auxArr);

	std::cout << "Time to sort 1000000 integers using merge sort: " <<
	  (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	// verify that the array was sorted
	testSort(arr, arrSize);	
	// end mergesort

	// populate array for heapsort
	populateArrRandom(arr, arrSize);

	// section heapsort
	start = std::clock();
	heapsort(arr, 1000000);
	std::cout << "Time to sort 1000000 integers using heap sort: " <<
	  (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	testSort(arr, sizeof(arr)/sizeof(arr[0]));
	// end heapsort

	// populate array for quick sort
	populateArrRandom(arr, arrSize);

	// section quicksort
	start = std::clock();
	quickSort(arr, 0, arrSize - 1);

	std::cout << "Time to sort 1000000 integers using quicksort: " <<
	  (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	testSort(arr, arrSize);
	// end quicksort

}

