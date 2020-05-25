#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <utility>

using namespace ::std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    int i = 0;
    int j = 0;
    unordered_set<int> m;
    int ubound = s.length();
    while (j < ubound) {
      if (m.find(s[j]) != m.end()) {
        m.erase(s[i]);
        i++;
      } else {
        m.insert(s[j]);
        int lm = m.size();
        res = max(lm, res);
        j++;
      }
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  string str = " ";
  // string str = "pwwkew";
  // string str = "abcabcbb";
  // string str = "aab";
  int res = sol.lengthOfLongestSubstring(str);

  cout << "Longest substring for " << str << " is " << res << endl;

  return 0;
}
