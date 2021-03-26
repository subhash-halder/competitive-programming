#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
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
  int change(int amount, vector<int> &coins) { ret = 0; }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<int> input;
    int result;
  };

  testCase t[] = {
      {{0, 1, 0}, 2},    {{0, 1, 0, 1}, 4}, {{0, 0, 0, 0}, 0},
      {{1, 0, 0, 1}, 4}, {{}, 0},           {{0, 0, 1, 0, 0, 0, 1, 1}, 6},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.findMaxLength(tc.input);
    cout << res << endl;
    assertm(res == tc.result, "");
  }
  cout << endl;
}
