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
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    vector<vector<int>> ret;
    if (!people.empty()) {
      ret.reserve(people.size());
      for (int i = people.size(); i > 0; i--) {
        ret.push_back({-1, 0});
      }
      sort(people.begin(), people.end(), [](vector<int> &v1, vector<int> &v2) {
        if (v1[0] == v2[0]) {
          return v1[1] < v2[1];
        } else {
          return v1[0] < v2[0];
        }
      });
      int maxVal = people[people.size() - 1][0];

      pair<int, int> preState = {-1, 0};
      for (vector<int> v : people) {
        if (preState.first == v[0]) {
          preState.second++;
        } else {
          preState = {v[0], 0};
        }
        int position = v[1] - preState.second;
        for (int i = 0; i < ret.size(); i++) {
          if (ret[i][0] == -1) {
            if (position == 0) {
              ret[i] = {v[0], v[1]};
              break;
            }
            position--;
          }
        }
      }
    }
    return ret;
  };
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<vector<int>> input;
  };

  testCase t[] = {
      {{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    vector<vector<int>> res = sol.reconstructQueue(tc.input);
    for (vector<int> v : res) {
      printf("[%d, %d]", v[0], v[1]);
    }
  }
  cout << endl;
}
