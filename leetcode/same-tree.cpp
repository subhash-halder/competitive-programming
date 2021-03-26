#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace ::std;

class Solution {
public:
  /*
  vector<vector<int>> subsets(vector<int>& nums) {
      const int n = nums.size();
      vector<vector<int>> results;
      for (int i = 0; i < pow(2, n); i++) {
          vector<int> v;
          for (int j = 0; j < n; j++) {
              if (i & (1<<j)) {
                  v.push_back(nums[j]);
              }
          }
          results.push_back(move(v));
      }
      return results;
  }
  */
  void subSet(vector<int> &nums, vector<vector<int>> &res, vector<int> &pre,
              int from, int to) {
    if (from == to)
      return;
    for (int i = from; i < to; i++) {
      vector<int> row = pre;
      row.push_back(nums[i]);
      res.push_back(row);
      subSet(nums, res, row, i + 1, to);
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret = {{}};
    vector<int> a = {};
    subSet(nums, ret, a, 0, nums.size());
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<int> input = {1, 2, 3, 4};
  vector<vector<int>> res = s.subsets(input);

  for (vector<int> arr : res) {
    for (int a : arr) {
      printf("%d, ", a);
    }
    cout << endl;
  }

  cout << endl;
  return 0;
}
