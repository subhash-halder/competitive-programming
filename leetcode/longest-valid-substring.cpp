#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int maxP = 0;
    int len = s.length();
    list<int> stack = {-1};

    for (int i = 0; i < len; i++) {
      if (s[i] == '(') {
        stack.push_front(i);
      } else {
        stack.pop_front();
        if (stack.empty()) {
          stack.push_front(i);
        } else {
          maxP = max(maxP, i - stack.front());
        }
      }
    }
    return maxP;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    string input;
    int result;
  };

  testCase t[] = {
      {")()())", 4}, {"((())()()", 8}, {")(((((()())()()))()(()))(", 22},
      {"()(()", 2},  {"()(()()", 4},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.longestValidParentheses(tc.input);
    cout << "result: " << res << endl;
    assertm(res == tc.result, tc.input);
  }
  cout << endl;
}
