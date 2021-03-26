#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  // recursion
  // vector<vector<int>> m;
  // int getUncrossedLineRec(vector<int> &A, vector<int> &B, int &al, int &bl,
  //                         int ai, int bi) {
  //   if (ai >= al || bi >= bl) {
  //     return 0;
  //   }
  //   if (m[ai][bi] != -1) {
  //     return m[ai][bi];
  //   }
  //   int res;
  //   if (A[ai] == B[bi]) {
  //     res = 1 + getUncrossedLineRec(A, B, al, bl, ai + 1, bi + 1);
  //   } else {

  //     int r1 = getUncrossedLineRec(A, B, al, bl, ai + 1, bi);
  //     int r2 = getUncrossedLineRec(A, B, al, bl, ai, bi + 1);
  //     res = max(r1, r2);
  //   }
  //   m[ai][bi] = res;
  //   return res;
  // }
  // int maxUncrossedLines(vector<int> &A, vector<int> &B) {
  //   int al = A.size();
  //   int bl = B.size();
  //   int mSize = max(al, bl);
  //   m.clear();
  //   m.resize(mSize, vector<int>(mSize, -1));
  //   return getUncrossedLineRec(A, B, al, bl, 0, 0);
  // }
};

int main() {
  string a = "adsfdf";
  Solution sol = Solution();

  struct testCase {
    vector<int> A;
    vector<int> B;
    int result;
  };

  testCase t[] = {
      {{1, 4, 2}, {1, 2}, 2},
      {{2, 5, 1, 2, 5}, {10, 5, 2, 1, 5, 2}, 3},
      {{1, 3, 7, 1, 7, 5}, {1, 9, 2, 5, 1}, 2},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.maxUncrossedLines(tc.A, tc.B);
    cout << res << endl;
    assertm(res == tc.result, "");
  }
  cout << endl;
}
