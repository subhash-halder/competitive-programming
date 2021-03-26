#include <algorithm>
#include <cassert>
#include <cstdint>
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

using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int per = 0, row = 0, rowLen = grid.size(), column, columnLen;
    for (; row < rowLen; row++) {
      columnLen = grid[row].size();
      for (column = 0; column < columnLen; column++) {
        if (grid[row][column] == 1) {
          // checkl for top
          if (row == 0 || grid[row - 1][column] == 0)
            per++;
          // check for right
          if (column == (columnLen - 1) || grid[row][column + 1] == 0)
            per++;
          // checkl for bottom
          if (row == (rowLen - 1) || grid[row + 1][column] == 0)
            per++;
          // check for left
          if (column == 0 || grid[row][column - 1] == 0)
            per++;
        }
        cout << per << ", ";
      }
      cout << endl;
    }
    return per;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<vector<int>> input;
    int output;
  };

  testCase t[] = {
      {
          {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}},
          16,
      },
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    int res = sol.islandPerimeter(tc.input);
    cout << res << endl;
  }
  cout << endl;
}
