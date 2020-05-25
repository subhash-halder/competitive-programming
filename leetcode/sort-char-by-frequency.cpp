#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    map<char, int> m;
    vector<pair<int, char>> v;
    for (char c : s) {
      m[c]++;
    }
    for (pair<char, int> mm : m) {
      v.push_back(make_pair(mm.second, mm.first));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    char ret[s.length() + 1];
    ret[s.length()] = '\0';
    int count = 0;
    for (pair<int, char> vv : v) {
      for (int i = 0; i < vv.first; i++) {
        ret[count] = vv.second;
        count++;
      }
    }

    return ret;
  }
};

int main() {
  Solution sol = Solution();
  cout << endl;
  struct testCase {
    string input;
    string result;
  };

  testCase t[] = {
      {"tree", "eetr"},
      {"treemmm", "mmmeetr"},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    string res = sol.frequencySort(tc.input);
    cout << "result: " << res << endl;
    assertm(tc.result.compare(res) == 0, tc.input);
  }
  cout << endl;
}
