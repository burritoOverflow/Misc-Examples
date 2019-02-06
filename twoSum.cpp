// accepted solution for https://leetcode.com/problems/two-sum/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::vector<int> solution;
      for(int i = 0; i < nums.size() - 1; i++){
        for(int j = i + 1; j < nums.size(); j++){
          if (nums[i] + nums[j] == target)
          {
            solution.push_back(i);
            solution.push_back(j);
          }
        }
      }
      return solution;
    }
};

// driver to test based on provided input
int main()
{
  Solution s;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> solution = s.twoSum(nums, target);
  std::vector<int>::iterator it;

  for(it = solution.begin(); it != solution.end(); it++)
  {
    std::cout << *it << " ";
  }
}
