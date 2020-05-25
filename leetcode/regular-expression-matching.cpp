#include <cassert>
#include <cstdint>
#include <iostream>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.empty())
      return s.empty();
    bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
    if (p.length() >= 2 && p[1] == '*') {
      return (isMatch(s, p.substr(2)) ||
              (firstMatch && isMatch(s.substr(1), p)));
    } else {
      return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
  }
};

int main() {
  string a = "adsfdf";
  Solution sol = Solution();

  struct testCase {
    string input;
    string regex;
    bool result;
  };

  testCase t[] = {
      {"aaabaaa", "aaabaaa", true}, {"mississippi", "mis*is*p*.", false},
      {"ab", ".*", true},           {"aa", "a*", true},
      {"aa", "a", false},           {"baacd", "ba*c.", true},
      {"aab", "c*a*b", true},       {"mississippi", "mis*is*ip*.", true},
      {"ab", ".*c", false},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    bool res = sol.isMatch(tc.input, tc.regex);
    assertm(res == tc.result, tc.input);
  }
  cout << endl;
}
