#include <iostream>

void reverseRecursive(const std::string& str)
{
    int numOfChars = str.size();
    if(numOfChars == 1)
    {
      std::cout << str << std::endl;
    }
    else
    {
       std::cout << str[numOfChars - 1];
       reverseRecursive(str.substr(0, numOfChars - 1));
    }
}

void reverseIterative(const std::string &str)
{
  std::string outString = str;
  int j = outString.size() - 1;
  int temp;

  for (int i = 0; i < str.size() / 2; i++, j--) {
    temp = outString[j];
    outString[j] = outString[i];
    outString[i] = temp;
  }
  std::cout << outString << std::endl;
}

int main()
{
    std::string str;

    std::cout << "Please enter a string \n";

    getline(std::cin, str);

    reverseIterative(str);
    reverseRecursive(str);
}
