#include <iostream>

bool sortedAscending(int array[], int size)
{
  for(int i = 0; i < size; i++)
  {
    if (array[i] < array[i + 1])
    {
      return true;
    }
  }
  return false;
}

bool sortedDescending(int array[], int size)
{
  for(int i = 0; i < size; i++)
  {
    if (array[i] > array[i + 1])
    {
      return true;
    }
  }
  return false;
}

bool isSorted(int array[], int size)
{
  bool sorted = false;
  int i = 0;
  // determine the arrangements of the initial elements wrt each other;
  // if the first element is smaller than the second, check if the list is
  // sorted in ascending order, otherwise, check if it is sorted in descending
  // order
  if(array[i] > array[i + 1])
  {
    sorted = sortedAscending(array, size);
  }
  else
  {
    sorted = sortedDescending(array, size);
  }
  return sorted;
}

int main()
{
  int array1[10] = {1, 3, 4, 6, 12, 71, 102};
  int array2[5] = {54, 45, 36, 12, 4};

  if (isSorted(array1, 10) && isSorted(array2, 5)) {
    std::cout << "Sorted." << std::endl;
  }
}
