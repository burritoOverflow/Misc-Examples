#include <assert.h>
#include <algorithm>

#define SIZE 9

/*
  returns the index where the value
  was found, else returns -1
*/
int BinarySearch(int arr[], int size, int value, int low, int high)
{
  // empty array, value not found
  if (size == 0) {
    return -1;
  }
  // base case
  if(low > high)
  {
    return -1;
  }
  int mid = (low + high) / 2;
  // found value
  if(arr[mid] == value)
  {
    return mid;
  }
  // value smaller: move the high point to one less than mid
  else if(arr[mid] > value) return BinarySearch(arr, size, value, low, mid - 1);
  // value larger: move the low point to one more than mid
  else return BinarySearch(arr, size, value, mid + 1, high);
}

int main(int argc, char const *argv[])
{
  // int inputValue = atoi(argv[1]);
  int arr[SIZE] = {12, 54, 67, 79, 90, 431, 789, 1200, 1500};

  for (int i = 0; i < SIZE - 1; i++)
  {
    assert(BinarySearch(arr, SIZE, arr[i], 0, SIZE - 1) == i);
  }

}
