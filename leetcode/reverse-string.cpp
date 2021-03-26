#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int len = s.size();
    int half = len / 2;
    int left = 0;
    int right = len - 1;
    while (left < half) {
      char tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    vector<char> input;
  };

  testCase t[] = {
      {{'a', 'b', 'c', 'd'}},
      {{'a', 'b', 'e', 'c', 'd'}},
      {{'a'}},
      {{'a', 'b'}},
      {{}},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    sol.reverseString(tc.input);
    for (char c : tc.input) {
      cout << c << ", ";
    }
    cout << endl;
  }
  cout << endl;
}
