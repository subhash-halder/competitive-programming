#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace ::std;

class Solution {
public:
  int hammingDistance(int x, int y) {
    int res = x ^ y;
    int result = 0;
    for (int i = 0; i < 32; i++) {
      if ((res | 1) == res) {
        result++;
      }
      res = res >> 1;
    }
    return result;
  }
};

int main() {
  Solution s = Solution();

  int res = s.hammingDistance(1, 4);
  cout << res << endl;
  return 0;
}
