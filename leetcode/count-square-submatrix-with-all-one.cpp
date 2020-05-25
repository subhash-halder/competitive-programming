#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

enum Visited { U, T, F };
/* brutforce
class Solution {
public:
  unordered_map<string, Visited> visited;
  int total = 0;
  bool countSquareRec(vector<vector<int>> &matrix, pair<int, int> start,
                      pair<int, int> end) {
    string pairName = to_string(start.first) + "-" + to_string(start.second) +
                      "-" + to_string(end.first) + "-" + to_string(end.second);
    if (visited[pairName] != Visited::U) {
      return visited[pairName] == Visited::T ? true : false;
    }
    if (start.first == end.first && start.second == end.second) {
      if (matrix[start.first][start.second] == 1) {
        total += 1;
        visited[pairName] = Visited::T;
        return true;
      } else {
        visited[pairName] = Visited::F;
        return false;
      }
    }
    countSquareRec(matrix, start, {end.first - 1, end.second - 1});
    countSquareRec(matrix, {start.first + 1, start.second + 1}, end);
    countSquareRec(matrix, {start.first, start.second + 1},
                   {end.first - 1, end.second});
    countSquareRec(matrix, {start.first + 1, start.second},
                   {end.first, end.second - 1});
    bool ret = true;
    for (int i = start.first, len = end.first; i <= len; i++) {
      if (matrix[i][start.second] != 1) {
        ret = false;
        break;
      }
      if (matrix[i][end.second] != 1) {
        ret = false;
        break;
      }
    }
    if (ret)
      for (int i = start.second, len = end.second; i <= len; i++) {
        if (matrix[start.first][i] != 1) {
          ret = false;
          break;
        }
        if (matrix[end.first][i] != 1) {
          ret = false;
          break;
        }
      }
    if (ret && (end.first - start.first) > 1) {
      ret = countSquareRec(matrix, {start.first + 1, start.second + 1},
                           {end.first - 1, end.second - 1});
    }

    visited[pairName] = ret ? Visited::T : Visited::F;
    if (ret) {
      total += 1;
      int squareLen = end.first - start.first + 1;
    }
    return ret;
  }
  int countSquares(vector<vector<int>> &matrix) {
    int noOfRows = matrix.size();
    int noOfColumns = matrix[0].size();
    int rowMaxIndex = noOfRows - 1;
    int columnMaxIndex = noOfColumns - 1;
    if (noOfColumns == noOfRows) {
      countSquareRec(matrix, {0, 0}, {rowMaxIndex, columnMaxIndex});
    } else if (noOfColumns > noOfRows) {
      int i = 0;
      while ((i + noOfRows) <= noOfColumns) {
        countSquareRec(matrix, {0, i}, {rowMaxIndex, i + noOfRows - 1});
        i++;
      }
    } else {
      int i = 0;
      while ((i + noOfColumns) <= noOfRows) {
        countSquareRec(matrix, {i, 0}, {i + noOfColumns - 1, columnMaxIndex});
        i++;
      }
    }
    int ret = total;
    total = 0;
    visited.clear();
    return ret;
  }
};
*/

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int noOfRows = matrix.size();
    int noOfColumns = matrix[0].size();
    int tmpM[noOfRows][noOfColumns];
    int total = 0;
    for (int r = 0; r < noOfRows; r++) {
      for (int c = 0; c < noOfColumns; c++) {
        if (matrix[r][c] == 1) {
          int addetive = INT32_MAX;
          if (r == 0 && c == 0)
            addetive = 0;
          if (r > 0) {
            addetive = min(addetive, tmpM[r - 1][c]);
          } else {
            addetive = 0;
          }
          if (c > 0) {
            addetive = min(addetive, tmpM[r][c - 1]);
          } else {
            addetive = 0;
          }
          if (r > 0 && c > 0) {
            addetive = min(addetive, tmpM[r - 1][c - 1]);
          } else {
            addetive = 0;
          }
          tmpM[r][c] = addetive + 1;
          total += (addetive + 1);
        } else {
          tmpM[r][c] = 0;
        }
      }
    }
    return total;
  }
};

int main() {
  Solution sol = Solution();
  cout << endl;
  struct testCase {
    vector<vector<int>> input;
    int result;
  };

  testCase t[] = {
      {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 14},
      {{{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}}, 15},
      {{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}, 7},
      {{{0, 0, 0}, {0, 1, 0}, {0, 1, 0}, {1, 1, 1}, {1, 1, 0}}, 8},
      {{{0, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 0, 1, 0}}, 13},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    cout << "For matrix: " << endl;
    for (auto v : tc.input) {
      for (int i : v) {
        cout << i << " ";
      }
      cout << endl;
    }
    int res = sol.countSquares(tc.input);
    cout << "result: " << res << endl;
    assertm(res == tc.result, "");
  }
  cout << endl;
}
