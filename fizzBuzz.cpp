// multiples of 3 += 'Fizz'
// multiples of 5 += "Buzz"
// solves FizzBuzz by appending 'Fizz' or 'Buzz' when appropriate.

#include <iostream>
#include <string>


std::string fizzBuzz(int n)
{
  std::string outString = "";

  if(n == 0)
  {
    return std::to_string(n);
  }

  if(n % 3 == 0)
  {
    outString += "Fizz";
  }

  if(n % 5 == 0)
  {
    outString += "Buzz";
  }

  // in the event the string has remained unchanged
  if (outString == "") {
    return std::to_string(n);
  }

  else
  {
    return outString;
  }
}


int main()
{
  for(int i = 0; i <= 100; i++)
  {
    std::cout << fizzBuzz(i) << std::endl;
  }

}
