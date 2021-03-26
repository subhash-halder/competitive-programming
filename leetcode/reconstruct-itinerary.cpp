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
  vector<string> findItinerary(vector<vector<string>> &tickets) {}
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<vector<string>> input;
    vector<string> output;
  };

  testCase t[] = {
      {
          {{"MUC", "LHR"}, {"jfk", "muc"}, {"sfo", "sjc"}, {"lhr", "sfo"}},
          {"jfk", "muc", "lhr", "sfo", "sjc"},
      },
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    vector<string> res = sol.findItinerary(tc.input);
    for (string a : res) {
      printf("%s, ", a.c_str());
    }
  }
  cout << endl;
}
