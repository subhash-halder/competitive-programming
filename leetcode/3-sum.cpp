#include <algorithm>
#include <cassert>
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
  vector<vector<int>> threeSum(vector<int> &nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    unordered_map<string, bool> m;
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        int k = -1;
        int target = 0 - (nums[i] + nums[j]);
        int left = j + 1, right = len - 1;
        while (left <= right) {
          int mid = (left + right) / 2;
          if (nums[mid] == target) {
            k = mid;
            break;
          } else if (nums[mid] > target) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }
        if (k == -1)
          continue;
        string mapStr =
            to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
        if (m.find(mapStr) == m.end()) {
          ret.push_back({nums[i], nums[j], nums[k]});
          m[mapStr] = true;
        } else if (nums[i] == nums[len - 1]) {
          return ret;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<int> input;
    vector<vector<int>> output;
  };

  testCase t[] = {
      {
          {-1, 0, 1, 2, -1, -4},
          {{-1, 0, 1}, {-1, -1, 2}},
      },
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    vector<vector<int>> ress = sol.threeSum(tc.input);
    for (vector<int> res : ress) {
      for (int a : res) {
        printf("%d, ", a);
      }
      printf("\n");
    }
  }
  cout << endl;
}
