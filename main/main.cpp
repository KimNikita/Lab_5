#include <iostream>
#include "MultiStack.h"

int main()
{
  TMultiStack<int>a(3, 3);
  a.Push(1, 0);
  a.Push(2, 2);
  a.Push(3, 1);
  cout << a;
  return 0;
}
