#include <assert.h>
#include <bitset>
#include <stdint.h>
#include <stdio.h>
#include <iostream>

// some bit manipulation operations

 // >> Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand.
 // << Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand.

// toggles the 5th bit of a number passed to the function (converts lowercase ASCII to upper case, vice versa)
 void switchCase(int &a)
 {
    a ^= 1UL << 5;
 }

// can actually just flip the value with bitset functions; isn't that wonderful!
 void switchMe(int &a)
 {
   std::bitset<8> bitVal(a);
   bitVal.flip(5);
   a = (int)(bitVal.to_ulong());
 }

int main(int argc, char const *argv[])
{
  // 1 byte -> [0-255] or [0x00-0xFF]s

  // in binary 00001010
  uint8_t val1 = 10;
  // in binary 00100010
  uint8_t val2 = 34;

  printf("The values in base10 are: %d and %d.\n",val1, val2);

  std::cout << "Binary representations are : " << std::bitset<8>(val1)
  << " and " << std::bitset<8>(val2) << ", respectively.\n";

  // logical AND 00001010 & 00100010 = 00000010, so the result is two
  uint8_t val3 = val1 & val2;

  // this is gross
  std::cout << "Result after logical AND: " << (int)val3 << " (base10) "
            << std::bitset<8>(val3) << " (base2).\n";

  // logical OR 00001010 & 00100010 = 00101010
  uint8_t val4 = val1 | val2;

  std::cout << "Result after logical OR: " << (int)val4 << " (base10) "
            << std::bitset<8>(val4) << " (base2).\n";

  printf("Now, let's shift some bits!\n");
  // binary left shift operator.

  uint8_t val5 = val1 << 1;
  std::cout << "Value before: " << std::bitset<8>(val1) << " after left shift by one "
            << std::bitset<8>(val5) << "\n";
  printf("The value went from %d, to %d\n", val1, val5);
  printf("Now what happens if we shift two bits?\n");

  // back to original value (preshift)
  val5 = val1;
  val5 = val1 << 2;

  std::cout << "Value before: " << std::bitset<8>(val1) << " after left shift by two "
            << std::bitset<8>(val5) << "\n";

  printf("The value went from %d, to %d.\n", val1, val5);
  printf("How about right by one bit?\n");

  // lets just shift the bits back this time.
  assert(val1 == val5 >> 2);

  // well, yeah.
  val5 = val5 >> 2;
  val5 = val1 >> 1;

  std::cout << "Value before: " << std::bitset<8>(val1) << " after right shift by one "
            << std::bitset<8>(val5) << "\n";
  printf("The value went from %d, to %d.\n", val1, val5);

  int val6 = 65;
  switchCase(val6);
  std::cout << (char)val6 << std::endl;

  switchMe(val6);
  std::cout << (char)val6 << std::endl;

}
