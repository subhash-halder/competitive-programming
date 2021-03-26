#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    k = k % size;
    if (k == 0)
      return;
    int repWith = k;
    int replace = nums[0];
    int base = 0;
    int count = size;
    while (count > 0) {
      int tmp = replace;
      int preRepWith = repWith;
      replace = nums[repWith];
      nums[repWith] = tmp;
      repWith = (repWith + k) % size;
      if (preRepWith == base) {
        replace = nums[preRepWith + 1];
        repWith = (preRepWith + 1 + k) % size;
        base = preRepWith + 1;
      }
      count--;
    }
  }
};

int main() {
  Solution sol = Solution();

  vector<int> vec = {2, 4, 5, 6, 3};
  sol.rotate(vec, 3);
  for (int i : vec) {
    printf("%d, ", i);
  }
  cout << endl;
  vector<int> vec1 = {1, 2, 3, 4};
  sol.rotate(vec1, 2);
  for (int i : vec1) {
    printf("%d, ", i);
  }
  cout << endl;
}
