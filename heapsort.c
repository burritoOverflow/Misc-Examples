#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

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

void max_heapify(int A[], int i, int Asize)
{
  int l = left(i);
  int r = right(i);
  int largest = 0;

  if (l <= (Asize - 1) && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }

  if (r <= (Asize -1) && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(&A[i], &A[largest]);
    max_heapify(A, largest, Asize);
  }
}

void build_max_heap(int A[], int Asize)
{
  int start = (Asize / 2) - 1;
  for(int i = start; i > 0; i--) {
    max_heapify(A, i, Asize);
  }
}

void heapSort(int A[], int Asize)
{
  build_max_heap(A, Asize);
  for (int i = Asize - 1; i > 0; i--)
  {
    swap(&A[0], &A[i]);
    max_heapify(A, 0, --Asize);
  }
}

void printArr(int A[], int Asize)
{
  for(int i = 0; i < Asize; i++)
  {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

int main ()
{

  int arr[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
  int arrSize = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, arrSize);
  printArr(arr, arrSize);

}
