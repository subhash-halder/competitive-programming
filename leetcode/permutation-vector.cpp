#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> out;
  void permutation(vector<int> &v, int p, int limit) {
    if (p == limit) {
      out.push_back(v);
      return;
    }
    for (int i = p; i <= limit; i++) {
      swap(v[p], v[i]);
      permutation(v, p + 1, limit);
      swap(v[p], v[i]);
    }
  };
  vector<vector<int>> permute(vector<int> &nums) {
    permutation(nums, 0, nums.size() - 1);
    return out;
  };
};

int main() {

  Solution sol = Solution();
  vector<int> inp = {1, 2, 3};
  auto p = sol.permute(inp);
  for (vector<int> i : p) {
    for (int j : i) {
      cout << j;
    }
    cout << endl;
  }
  return 0;
}
