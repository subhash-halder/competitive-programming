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
  string convert(string s, int numRows) {
    if (numRows <= 1 || s.length() == 0)
      return s;
    int sLen = s.length();
    char ret[sLen + 1];
    ret[sLen] = '\0';
    int c = 0;
    int adder = numRows - 1;
    for (int i = 0; i < numRows; i++) {
      int j = i;
      while (j < sLen) {
        ret[c] = s[j];
        j = j + (adder - (j % adder)) * 2;
        c++;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  cout << endl;
  struct testCase {
    string input;
    int rows;
    string result;
  };

  testCase t[] = {
      {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
      {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    string res = sol.convert(tc.input, tc.rows);
    cout << "result: " << res << endl;
    assertm(res.compare(tc.result), tc.input);
  }
  cout << endl;
}
