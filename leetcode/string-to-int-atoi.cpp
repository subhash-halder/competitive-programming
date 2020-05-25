#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    long int ret = 0;
    int sign = 1;
    int minChecker = INT32_MIN / 10;
    int maxChecker = INT32_MAX / 10;
    bool isSignedCaptured = false;
    bool isCapturedStarted = false;
    for (char c : str) {
      int cAscii = (int)c;
      if (cAscii == 32 && !isCapturedStarted)
        continue;
      if (!isSignedCaptured && !isCapturedStarted && ret == 0 &&
          (c == '+' || c == '-')) {
        if (c == '-')
          sign = -1;
        isSignedCaptured = true;
        isCapturedStarted = true;
        continue;
      }
      if (cAscii < 48 || cAscii > 57) {
        break;
      }
      isCapturedStarted = true;
      int numToAdd = cAscii - 48;
      if (sign > 0 && (ret > maxChecker || (ret == maxChecker && numToAdd > 7)))
        return INT32_MAX;
      if (sign < 0 &&
          (-ret < minChecker || (-ret == minChecker && numToAdd > 8)))
        return INT32_MIN;
      ret = ret * 10 + numToAdd;
    }
    return ret * sign;
  }
};

int main() {
  Solution sol = Solution();
  cout << endl;
  struct testCase {
    string input;
    int result;
  };

  testCase t[] = {
      {"0-1", 0},
      {"   4", 4},
      {"   +123 adfad", 123},
      {"0", 0},
      {"-120", -120},
      {"-91283472332", INT32_MIN},
      {"-2147483649", -2147483648},
      {"-2147483648", -2147483648},
      {"-2147483647", -2147483647},
      {"4147483648", INT32_MAX},
      {"2147483648", INT32_MAX},
      {"2147483646", 2147483646},
      {"2147483647", 2147483647},
      {"+-123", 0},
      {"+ 23", 0},
      {"+0 45", 0},
      {"5 56", 5},

  };

  cout << "Testing ......\n";
  cout << INT32_MIN;
  for (testCase tc : t) {
    int res = sol.myAtoi(tc.input);
    cout << "result: " << res << endl;
    assertm(res == tc.result, tc.input);
  }
  cout << endl;
}
