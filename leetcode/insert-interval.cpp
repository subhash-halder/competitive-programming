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
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    bool searchingLower = true;
    bool searchingUpper = false;
    vector<vector<int>> res;
    int len = intervals.size();
    int count = 0;
    while (count < len) {
      vector<int> interval = {intervals[count][0], intervals[count][1]};
      if (searchingLower) {
        if (newInterval[0] <= interval[0]) {
          interval[0] = newInterval[0];
          searchingLower = false;
          searchingUpper = true;
          res.push_back(interval);
          continue;
        } else if (newInterval[0] <= interval[1]) {
          searchingLower = false;
          searchingUpper = true;
          res.push_back(interval);
          continue;
        }
      } else if (searchingUpper) {
        int resI = res.size() - 1;
        if (newInterval[1] < interval[0]) {
          res[resI][1] = newInterval[1];
          res.push_back(interval);
          searchingUpper = false;
          count++;
          continue;
        } else if (newInterval[1] == interval[0] ||
                   newInterval[1] <= interval[1]) {
          res[resI][1] = interval[1];
          searchingUpper = false;
          count++;
          continue;
        }
        count++;
        continue;
      }
      res.push_back(interval);
      count++;
    }
    if (searchingLower) {
      res.push_back(newInterval);
    } else if (searchingUpper) {
      res[res.size() - 1][1] = newInterval[1];
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<vector<int>> input;
    vector<int> newInterval;
  };

  testCase t[] = {
      {
          {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
          {4, 8},
      },
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    vector<vector<int>> res = sol.insert(tc.input, tc.newInterval);
    for (vector<int> vv : res) {
      cout << "[" << vv[0] << "," << vv[1] << "] ";
    }
  }
  cout << endl;
}
