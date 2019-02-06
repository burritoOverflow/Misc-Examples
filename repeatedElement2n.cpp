// In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
// Return the element repeated N times.
// accepted solution to https://leetcode.com/problems/n-repeated-element-in-size-2n-array/submissions/
#include <vector>
#include <iostream>
#include <map>

class Solution {
public:
  int repeatedNTimes(std::vector<int>& A) {
    int N_times = A.size() / 2;
    int count, solution;
    // key is num (element), value is n appearances
    std::map<int, int> s_map;
    for(int i = 0; i < A.size(); i++)
    {
      // initialize the map with each value in the vector
      s_map.insert(std::pair<int, int>(A[i], 0));
    }
    for(int i = 0; i < A.size(); i++)
    {
      std::map<int,int>::iterator it = s_map.find(A[i]);
      if (it != s_map.end())
      {
        it->second++;   // increment key's value
        if (it->second == N_times)
        {
          solution = A[i];
        }
      }
    }
  return solution;
  }
};

// solution using provided test case
int main()
{
  Solution s;
  int val;
  std::vector<int> v = {5,1,5,2,5,3,5,4};
  val = s.repeatedNTimes(v);
  std::cout << val << std::endl;


}
