#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Best solution

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {

        N = N%14==0 ? 14 : N%14;
        vector<int> cells2(8,0);
        while(N>0)
        {
            for(int i=1;i<cells.size()-1;i++)
            {
                cells2[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            cells = cells2;
            N--;
        }

        return cells;
    }
};
*/

/* Need to check the bit operation
class Solution {
public:
        vector<int> prisonAfterNDays(vector<int>& C, int N) {
                int s = E(C);
                vector<int> H(1 << 8, -1);
                for (int i = 1, f = false; i <= N; ++i) {
                        s = next(s);
                        if (H[s] == -1 || f) {
                                H[s] = i;
                        } else {
                                f = true;
                                int l = i - H[s];
                                int k = (N - i) / l;
                                i += k * l;
                        }
                }
                return D(s);
        }

        int E(vector<int> &C) {
                int s = 0;
                for (int c : C)
                        s = (s << 1) + c;
                return s;
        }

        vector<int> D(int s) {
                vector<int> R;
                for (int i = 7; i >= 0; --i)
                        R.push_back(!!(s & (1 << i)));
                return R;
        }

        int next(int n) {
                int a = n >> 1, b = n << 1;
                return (~(a ^ b)) & (((1 << 6) - 1) << 1);
        }
};
*/

class Solution {
public:
  int insertToMap(unordered_map<int, int> &m, vector<int> &v, int lenV,
                  int ind) {
    int mKey = 0;
    for (int i = 0; i < lenV; i++) {
      mKey = (mKey << 1) + v[i];
    }
    if (m.find(mKey) != m.end()) {
      return m[mKey];
    } else {
      m[mKey] = ind;
      return ind;
    }
  };
  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    int cellLen = cells.size() - 1;
    vector<vector<int>> vv;
    unordered_map<int, int> m;
    vector<int> v;
    v.reserve(cells.size());
    for (int c : cells) {
      v.push_back(c);
    }
    vv.push_back(v);
    insertToMap(m, v, cellLen + 1, 0);
    for (int i = 1; i <= N; i++) {
      vector<int> compareV = vv[i - 1];
      vector<int> v;
      v.reserve(cells.size());
      for (int c : compareV) {
        v.push_back(0);
      }
      for (int j = 1; j < cellLen; j++) {
        if (compareV[j - 1] == compareV[j + 1]) {
          v[j] = 1;
        } else {
          v[j] = 0;
        }
      }
      vv.push_back(v);
      int ind = insertToMap(m, v, cellLen + 1, i);
      if (ind != i) {
        printf("found repetation in %d: %d: %d ", i, ind, (N - 1) % (i - ind));
        return vv[ind + (N - i) % (i - ind)];
      }
    }
    return vv[vv.size() - 1];
  }
};

int main() {
  vector<int> cells = {1, 0, 0, 1, 0, 0, 1, 0};
  int N = 16;
  Solution sol = Solution();

  vector<int> ret = sol.prisonAfterNDays(cells, N);
  for (int a : ret) {
    printf("%d, ", a);
  }
  cout << endl;
}
