#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int zeroPointer = 0;
    int twoPointer = nums.size() - 1;
    int ptr = 0;
    while (ptr <= twoPointer) {
      if (nums[zeroPointer] == 0 && nums[ptr] == 0) {
        zeroPointer++;
        ptr++;
        continue;
      }
      if (nums[ptr] == 0) {
        iter_swap(nums.begin() + zeroPointer, nums.begin() + ptr);
        zeroPointer++;
        continue;
      }
      if (nums[ptr] == 2) {
        iter_swap(nums.begin() + ptr, nums.begin() + twoPointer);
        twoPointer--;
        continue;
      }
      ptr++;
    }
  }
};

int main() {
  Solution sol = Solution();
  struct tc {
    vector<int> input;
  };
  vector<tc> cases = {
      {{1, 0, 2, 2, 0, 0, 1}},
      {{2, 2, 2, 1, 1, 1, 0, 0, 0}},
      {{1, 1, 1, 1, 1}},
      {{2, 2, 2, 2, 2}},
      {{0, 0, 0, 0, 0}},
      {{0}},
      {{1}},
      {{2}},
      {{}},
  };
  for (tc c : cases) {
    sol.sortColors(c.input);
    for (int i : c.input) {
      printf("%d,", i);
    }
    cout << endl;
  }
  return 0;
}
