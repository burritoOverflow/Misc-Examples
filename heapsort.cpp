#include <iostream>
#include <ctime>

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
  if (l <= (n - 1) && A[l] > A[i]) {
    largest = l;
  }
  else {
    largest = i;
  }
  if (r <= (n - 1) && A[r] > A[largest]) {
    largest = r;
  }
  if (largest != i) {
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

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++) {
    std::cout << A[i] << ", ";
  }
  std::cout << std::endl;
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

  for (int i = 0; i < 1000000; i++)
  {
    arr[i] = rand() % 1000 + 1;
  }

  start = std::clock();
  heapsort(arr, 1000000);
  std::cout << "Time to sort 1000000 integers: " <<
      (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

  testSort(arr, sizeof(arr)/sizeof(arr[0]));

}
