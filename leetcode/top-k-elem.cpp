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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mm;
    vector<int> retArr;
    retArr.reserve(k);
    for (int n : nums) {
      if (mm.find(n) == mm.end()) {
        mm[n] = 1;
      } else {
        mm[n]++;
      }
    }
    vector<pair<int, int>> tmpVec;
    tmpVec.reserve(mm.size());
    for (pair<int, int> m : mm) {
      tmpVec.push_back(m);
    }
    sort(tmpVec.begin(), tmpVec.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
    });
    while (k) {
      retArr.push_back(tmpVec.back().first);
      tmpVec.pop_back();
      k--;
    }
    return retArr;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<int> nums;
    int k;
    vector<int> result;
  };

  testCase t[] = {{{1, 1, 1, 2, 2, 3}, 2, {1, 2}}, {{1}, 1, {1}}};

  cout << "Testing ......\n";
  for (testCase tc : t) {
    vector<int> ress = sol.topKFrequent(tc.nums, tc.k);
    for (int a : ress) {
      printf("%d, ", a);
    }
    cout << endl;
  }
  cout << endl;
}
