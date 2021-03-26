#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

#define M_PILES 105
#define MAX 105
#define INF -1000000

using namespace std;

class Solution {
public:
  int best(vector<int> &p, int dp[MAX][M_PILES], int N, int M, int x) {
    if (x >= N) {
      return 0;
    }
    int i, result, sum;
    int max_ = INF;
    if (dp[M][x] > INF) {
      return dp[M][x];
    }

    sum = p[x];
    for (i = 1; i <= M * 2 && x + i <= N; i++) {
      result = sum - best(p, dp, N, max(M, i), x + i);
      if (max_ < result) {
        max_ = result;
      }
      sum += p[x + i];
    }

    dp[M][x] = max_;
    return dp[M][x];
  };
  int stoneGameII(vector<int> &piles) {
    int dp[MAX][M_PILES];
    int i, j;
    for (i = 0; i < MAX; i++)
      for (j = 0; j < MAX; j++)
        dp[i][j] = INF;

    int a = best(piles, dp, piles.size(), 1, 0);
    int total = 0;
    for (i = 0; i < piles.size(); i++) {
      total += piles[i];
    }
    return (total + a) / 2;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<int> input;
    int result;
  };

  testCase t[] = {{{2, 7, 9, 4, 4}, 10},
                  {{2, 7, 9, 4, 49, 4, 5, 2, 1, 90}, 107},
                  {{1, 2, 3, 4, 5, 100}, 104}};

  cout << "Testing ......\n";
  for (testCase tc : t) {
    double ress = sol.stoneGameII(tc.input);
    assertm(ress == tc.result, ress)
  }
  cout << endl;
}
