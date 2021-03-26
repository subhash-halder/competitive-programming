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
  int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    if (nums.size() == 0) {
      return 0;
    }
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      if (target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<int> input;
    int target;
    int result;
  };

  testCase t[] = {
      {{1, 3, 5, 6}, 5, 2}, {{1, 3, 5, 6}, 4, 2}, {{1, 3, 5, 6}, 7, 4},
      {{2, 3, 5, 6}, 1, 0}, {{1}, 4, 1},          {{2}, 1, 0},
      {{}, 4, 0},           {{1}, 1, 0},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.searchInsert(tc.input, tc.target);
    assertm(res == tc.result, tc.target);
  }
  cout << endl;
}
