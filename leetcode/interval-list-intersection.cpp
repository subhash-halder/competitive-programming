#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                           vector<vector<int>> &B) {
    vector<vector<int>> ret;
    int a = 0, b = 0, al = A.size(), bl = B.size();
    while (a < al && b < bl) {
      if (A[a][1] < B[b][0]) {
        a++;
        continue;
      }
      if (B[b][1] < A[a][0]) {
        b++;
        continue;
      }
      ret.push_back({max(A[a][0], B[b][0]), min(A[a][1], B[b][1])});
      if (b < (bl - 1) && A[a][1] >= B[b + 1][0]) {
        b++;
        continue;
      }
      if (a < (al - 1) && B[b][1] >= A[a + 1][0]) {
        a++;
        continue;
      }
      a++;
      b++;
    }

    return ret;
  }
};

int main() {
  Solution sol = Solution();
  cout << endl;
  struct testCase {
    vector<vector<int>> a;
    vector<vector<int>> b;
    vector<vector<int>> result;
  };

  testCase t[] = {
      {
          {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
          {{1, 5}, {8, 12}, {15, 24}, {25, 26}},
          {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}},
      },
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    auto res = sol.intervalIntersection(tc.a, tc.b);
    cout << "result: " << endl;
    for (auto v1 : res) {
      cout << "[" << v1[0] << "," << v1[1] << "]";
      cout << endl;
    }
  }
  cout << endl;
}
