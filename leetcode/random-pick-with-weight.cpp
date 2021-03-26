#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  Solution(vector<int> &w) {
    wCom.reserve(w.size());
    maxW = 0;
    for (int i : w) {
      maxW += i;
      wCom.push_back(maxW);
    }
  }

  int pickIndex() {
    int getW = rand() % maxW;
    return bSearch(getW + 1);
  }

  int bSearch(int i) {
    int l = 0;
    int r = wCom.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      // printf("%d : %d : %d : %d : %d\n", l, wCom[l], r, wCom[r], i);
      if (i > wCom[mid]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }

private:
  vector<int> wCom;
  int maxW;
};

int main() {
  vector<int> v = {1, 2, 1};
  Solution sol = Solution(v);
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
}
