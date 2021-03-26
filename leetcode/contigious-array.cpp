#include <algorithm>
#include <cassert>
#include <cstdint>
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
  // brutforce
  // int findMaxLength(vector<int> &nums) {
  //   int maxL = 0;
  //   int l = nums.size();
  //   if (l < 2) {
  //     return 0;
  //   }
  //   int count = 0;
  //   for (int i = 0; i < l; i++) {
  //     pair<int, int> matrix[l];
  //     for (int j = i; j < l; j++) {
  //       count++;
  //       int oneCount = 0;
  //       int zeroCount = 0;
  //       if (j > i) {
  //         zeroCount = matrix[j - 1].first;
  //         oneCount = matrix[j - 1].second;
  //       }
  //       nums[j] == 1 ? oneCount++ : zeroCount++;
  //       matrix[j] = {zeroCount, oneCount};
  //       if (zeroCount == oneCount) {
  //         int localMaxL = j - i + 1;
  //         if (localMaxL > maxL) {
  //           maxL = localMaxL;
  //         }
  //       }
  //     }
  //   }
  //   cout << "total: " << count << endl;
  //   return maxL;
  // }
  int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> m;
    int count = 0;
    int maxL = 0;
    int l = nums.size();
    for (int i = 0; i < l; i++) {
      count = count + (nums[i] == 0 ? -1 : 1);
      if (count == 0) {
        maxL = max(maxL, i + 1);
      } else {
        if (m.find(count) != m.end()) {
          maxL = max(maxL, i - m[count]);
        } else {
          m[count] = i;
        }
      }
    }
    return maxL;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<int> input;
    int result;
  };

  testCase t[] = {
      {{0, 1, 0}, 2},    {{0, 1, 0, 1}, 4}, {{0, 0, 0, 0}, 0},
      {{1, 0, 0, 1}, 4}, {{}, 0},           {{0, 0, 1, 0, 0, 0, 1, 1}, 6},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.findMaxLength(tc.input);
    cout << res << endl;
    assertm(res == tc.result, "");
  }
  cout << endl;
}
