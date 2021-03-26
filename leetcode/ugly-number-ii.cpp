#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
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
  /*
  int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++){
            v[i] = min(v[p2]*2, min(v[p3]*3, v[p5]*5));
            if (v[i] == v[p2]*2) p2++;
            if (v[i] == v[p3]*3) p3++;
            if (v[i] == v[p5]*5) p5++;
        }
        return v[n-1];
    }
    */
  int nthUglyNumber(int n) {
    vector<int> v;
    v.reserve(n);
    v.push_back(1);
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 0; i < n; i++) {
      v.push_back(min(v[p2] * 2, min(v[p3] * 3, v[p5] * 5)));
      if (v.back() == (v[p2] * 2))
        p2++;
      if (v.back() == (v[p3] * 3))
        p3++;
      if (v.back() == (v[p5] * 5))
        p5++;
    }
    return v[n - 1];
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    int input;
    int result;
  };

  testCase t[] = {{10, 12}, {200, 16200}, {1690, 2123366400}, {448, 531441}};

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.nthUglyNumber(tc.input);
    cout << res << endl;
    assertm(res == tc.result, "");
  }
  cout << endl;
}
