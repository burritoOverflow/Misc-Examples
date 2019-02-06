// https://open.kattis.com/problems/cold
// Accepted solution for open.kattis cold-puter science
#include <iostream>

int find_neg_temps(int n) { // pass the number of temps
  int temp_array[n];
  int neg_count = 0;

  // store each value in the array
  for (int i = 0; i < n; i++) {
    std::cin >> temp_array[i];
      }

  // determine number of neg values
  for (int i = 0; i < n; i++) {
    if (temp_array[i] < 0) {
      neg_count++;
    }
  }

  return neg_count;
}

int main()
{

  int number_of_temps;

  // first input is num of temps (num of subsequent inputs)
  std::cin >> number_of_temps;
  std::cout << find_neg_temps(number_of_temps) << std::endl;

}
