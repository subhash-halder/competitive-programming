#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> ret = {0};
    int i = 1;
    int j = 0;
    int nextBreak = 1;
    while (i <= num) {
      if (i == nextBreak) {
        nextBreak = i << 1;
        j = 0;
      }
      ret.push_back(ret[j] + 1);
      i++;
      j++;
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> res = sol.countBits(16);
  for (int i : res) {
    cout << i;
  }
  cout << endl;
  return 0;
}
