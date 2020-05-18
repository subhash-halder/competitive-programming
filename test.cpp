#include <iostream>

using namespace ::std;

void change(int &a) {
  cout << "value of a inside change function: " << a << endl;
  a = 10;
}

int main() {
  int a = 2;
  cout << "value of a: " << a << endl;
  change(a);
  cout << "value of a after change: " << a << endl;
  cout << endl;
  return 0;
}
