#include <cassert>
#include <cmath>
#include <iostream>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int r = 0;
    while (x != 0) {
      int pop = (x % 10);
      if (r > INT32_MAX / 10 || (r == INT32_MAX / 10 && pop > 7))
        return 0;
      if (r < INT32_MIN / 10 || (r == INT32_MIN / 10 && pop < -8))
        return 0;
      r = (r * 10) + pop;
      x = x / 10;
    }
    return r;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    int input;
    int result;
  };

  testCase t[] = {
      {4, 4}, {123, 321}, {0, 0}, {120, 21}, {-123, -321},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.reverse(tc.input);
    cout << "result: " << res << endl;
    assertm(res == tc.result, tc.input);
  }
  cout << endl;
}
