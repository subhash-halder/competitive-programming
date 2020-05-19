#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <utility>

using namespace ::std;

class Solution {
public:
  void calculateLongest(string s, int leftPointer, int rightPointer, int ubound,
                        string &res) {
    int maxLen = res.length();
    int edgeCheck = floor(maxLen >> 1);
    if ((leftPointer - edgeCheck) < 0 || (rightPointer + edgeCheck) > ubound ||
        s[leftPointer - edgeCheck] != s[rightPointer + edgeCheck]) {
      return;
    }
    int trackMax = 0;
    int L = leftPointer;
    for (; leftPointer >= 0 && rightPointer < ubound &&
           s[leftPointer] == s[rightPointer];
         leftPointer--, rightPointer++) {
      if (leftPointer == rightPointer) {
        trackMax = 1;
      } else {
        trackMax += 2;
      }
      L = leftPointer;
    }
    if (trackMax > res.length()) {
      res = s.substr(L, trackMax);
    }
  }
  string longestPalindrome(string s) {
    string res = "";
    int ubound = s.length();
    int left = floor(ubound >> 1);
    int right = left + 1;
    int counter = 0;
    while (left >= 0 || right < ubound) {
      bool selectLeft = counter & 1;
      int i = 0;
      if (selectLeft) {
        if (left < 0) {
          counter++;
          continue;
        }
        i = left;
      } else {
        if (right >= ubound) {
          counter++;
          continue;
        }
        i = right;
      }
      calculateLongest(s, i, i, ubound, res);
      if (s[i] == s[i + 1]) {
        calculateLongest(s, i, i + 1, ubound, res);
      }
      if (selectLeft) {
        left--;
      } else {
        right++;
      }
      counter++;
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    string input;
    string result;
  };

  testCase t[7] = {
      {"aaabaaa", "aaabaaa"},
      {"aaa", "aaa"},
      {"eabcb", "bcb"},
      {"bb", "bb"},
      {"bbbbbbbbbbbbbb", "bbbbbbbbbbbbbb"},
      {"", ""},
      {"babaddtattarrattatddetartrateedredividerb", "ddtattarrattatdd"},
  };

  for (testCase tc : t) {
    string res = sol.longestPalindrome(tc.input);
    cout << "Longest palindromic substring for " << tc.input << " is " << res
         << endl;
    cout << "Expected output is: " << tc.result << "\n\n\n";
  }

  return 0;
}
