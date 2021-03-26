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

#define M_PILES 105
#define MAX 105
#define INF -1000000

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string ret;
    int len = s.size();
    string tmp;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        if (!tmp.empty()) {
          if (ret.empty()) {
            ret += tmp;
          } else {
            ret += " " + tmp;
          }
        }
        tmp.clear();
      } else {
        tmp = s[i] + tmp;
      }
    }
    if (!tmp.empty()) {
      if (ret.empty()) {
        ret += tmp;
      } else {
        ret += " " + tmp;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    string input;
    string result;
  };

  testCase t[] = {
      {" hello world! ", "world! hello"},
      {" hello    world!", "world! hello"},
      {"   ", ""},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    string ress = sol.reverseWords(tc.input);
    cout << ress << endl;
    assertm(ress == tc.result, ress)
  }
  cout << endl;
}
