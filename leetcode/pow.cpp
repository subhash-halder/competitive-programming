#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  long double getPow(long double x, long int n) {
    if (n <= 1) {
      return x;
    }
    long double ff = getPow(x, n >> 1);
    long double ret = ff * ff;
    if (n & 1) {
      ret = ret * x;
    }
    return ret;
  }
  long double myPow(double x, long int n) {
    if (n == 0) {
      return 1;
    }
    long double multipleWith = n < 0 ? 1 / x : x;
    return getPow(multipleWith, abs(n));
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    double x;
    int n;
    double result;
  };

  testCase t[] = {
      {2, 2, 4},
      {2, 10, 1024},
      {2, -2, 0.25},
      {0.00001, 23478858, 0},
      {2.00000, -2147483648, 0},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    double ress = sol.myPow(tc.x, tc.n);
    cout << ress << endl;
    assertm(ress == tc.result, ress)
  }
  cout << endl;
}
