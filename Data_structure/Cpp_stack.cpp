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

//use stack to determine experssion whether layout correct
bool
paren(const char exp[], int lo, int n){
  Stack<char> s;
  for (int i = 0; exp[i] ; i++){
    switch(exp[i]){
      case '(': case '[': case '{': s.push(exp[i]); break;
      case ')': if( (s.empty()) || (s.pop() != ')') ) return false; break;
      case ']': if( (s.empty()) || (s.pop() != ']') ) return false; break;
      case '}': if( (s.empty()) || (s.pop() != '}') ) return false; break;
      defalut: break;//ingore normal chara
    }
  }
  return s.empty();//If stack is empty ,expression layout correct
}