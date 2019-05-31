#include <set>
#include <iostream>
#include <assert.h>

// find duplicate elements in a list
int Duplicate(int arr[], int size)
{
  std::set<int> myset;
  // if -1, no duplicates
  int dup = -1;
  
  // used for the return value
  std::pair<std::set<int>::iterator,bool> ret;
  
  for(int i = 0; i < size; i++)
  {
    if (myset.insert(arr[i]).second == false)
    {
      dup = arr[i];
    }
  }
  return dup;
}

int main() {
  
  int list[] = { 2, 1, 4, 3, 5, 12, 43, 12, 56};
  int list2[] = { 12, 45, 43, 89, 90, 90, 14};
  int list3[] = {1};
  
  int size = sizeof(list) / sizeof(*list);
  int size2 = sizeof(list2) / sizeof(*list2);
  int size3 = sizeof(list3) / sizeof(*list3);
  
  assert(Duplicate(list, size) == 12);
  assert(Duplicate(list2, size2) == 90);
  assert(Duplicate(list3, size3) == -1);


}
