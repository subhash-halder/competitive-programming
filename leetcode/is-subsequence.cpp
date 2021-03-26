#include <algorithm>
#include <cassert>
#include <cstdint>
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
  bool isSubsequence(string s, string t) {
    int su = s.length() - 1;
    int tu = t.length() - 1;
    if (su == -1) {
      return true;
    }
    int si = 0, ti = 0;
    while (ti <= tu) {
      if (t[ti] == s[si]) {
        if (si == su) {
          return true;
        }
        si++;
      }
      ti++;
    }
    return false;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    string s;
    string t;
    int result;
  };

  testCase t[] = {
      {"abc", "aasdfbadsfacadf", true},
      {"axc", "aasdfbadsfacadf", false},
      {"", "aasdfbadsfacadf", true},
      {"aa", "", false},
      {"", "", true},
      {"aaaa", "asdfaadfa", true},
      {"abcd", "abcd", true},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.isSubsequence(tc.s, tc.t);
    assertm(res == tc.result, tc.s);
  }
  cout << endl;
}
