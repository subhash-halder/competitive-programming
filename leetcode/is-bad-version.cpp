#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

bool isBadVersion(int version) { return version >= 1 ? true : false; }
class Solution {
public:
  int firstBadVersionRec(int i, int left, int right) {
    while (true) {
      if (isBadVersion(i) && (i == 1 || !isBadVersion(i - 1))) {
        return i;
      } else if (isBadVersion(i)) {
        right = i;
        i = left + (right - left) / 2;
      } else {
        left = i;
        i = i + (right - i) / 2;
      }
    }
  }
  int firstBadVersion(int n) { return firstBadVersionRec(n, 1, n); }
};

int main() {
  Solution sol = Solution();
  int res = sol.firstBadVersion(3);
  cout << res << endl;
  return 0;
}
