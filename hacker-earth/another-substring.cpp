#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#define pr(x, y) printf("%s: %d\n", x, y)
using namespace std;

const int MAXSIZE = 100002;

int solve(int n, int k, int a[MAXSIZE]) {
  int i, left = 0, right = 0, totalFilled = 0, minVal = INT_MAX;
  int map[k + 1];
  for (i = 0; i <= k; i++) {
    map[i] = 0;
  }
  totalFilled = 1;
  map[a[0]] = 1;
  while (right < n) {
    if (totalFilled == k) {
      minVal = min(minVal, right - left + 1);
      if (minVal == k)
        return k;
      if (map[a[left]] == 1) {
        totalFilled--;
      }
      map[a[left]]--;
      left++;
    } else {
      right++;
      if (right < n) {
        if (map[a[right]] == 0)
          totalFilled++;
        map[a[right]]++;
      }
    }
  }
  return minVal;
}

int main() {
  struct testCase {
    int n;
    int k;
    int a[MAXSIZE];
  };

  vector<testCase> testCases = {
      {6, 3, {1, 2, 2, 3, 2, 1}},
  };

  for (testCase tc : testCases) {
    printf("%d\n", solve(tc.n, tc.k, tc.a));
  }

  return 0;
}
