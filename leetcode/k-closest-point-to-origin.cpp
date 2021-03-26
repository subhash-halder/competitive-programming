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

struct Status {
  bool processing;
};

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    vector<vector<int>> res;

    return res;
  }
};

int main() {
  string a = "adsfdf";
  Solution sol = Solution();

  struct testCase {
    int K;
    vector<vector<int>> v;
    vector<vector<int>> result;
  };

  testCase t[] = {{1, {{1, 3}, {-2, 2}}, {{-2, -2}}}};

  cout << "Testing ......\n";
  int count = 1;
  for (testCase tc : t) {
    vector<vector<int>> res = sol.kClosest(tc.v, tc.K);
    cout << count << endl;
    cout << "[ ";
    for (auto vv : res) {
      cout << "[ " << vv[0] << "," << vv[1] << "], ";
    }
    cout << "] " << endl;
    count++;
  }
  cout << endl;
}
