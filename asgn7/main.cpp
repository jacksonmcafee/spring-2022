#include <iostream>
#include "stack.h"

using namespace std;

int main(void) {

  Stack<char> char10(4);
  char10.Push('a');
  char10.Push('b');
  char10.Push('c');
  char10.Push('d');

  cout << char10.Full() << endl;

  Stack<char> char10_new(char10);
  cout << char10.Full() << endl;

  cout << char10;
  char10.Pop();
  char10.Pop();
  char10.Pop();
  cout << char10;

  cout << char10_new;

  return 0;
}
