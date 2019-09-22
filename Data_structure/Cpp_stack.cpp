#include "Header/Cpp_stack.h"
#include <iostream>
using namespace std;

void//ten decimal convert to base decimal
convert(Stack<char> &S, int64_t n, int base){
  static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  while( 0 < n){
    int reminder = (int)(n % base);
    S.push(digit[reminder]);
    n /= base;
  }
}