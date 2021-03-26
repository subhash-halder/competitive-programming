#include <iostream>
#include <map>

using namespace ::std;

void change(int &a) {
  cout << "value of a inside change function: " << a << endl;
  a = 10;
}

int main() {
  int i = 16;
  int b = i & (i - 1);
  cout << b << endl;
  cout << (32 & 1) << endl;
  int a = 2;
  cout << "value of a: " << a << endl;
  change(a);
  cout << "value of a after change: " << a << endl;
  cout << endl;
  return 0;
}
