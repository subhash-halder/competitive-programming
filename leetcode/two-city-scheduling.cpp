#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

struct compare {
  inline bool operator()(const vector<int> &a, const vector<int> &b) {
    if ((a[0] <= a[1] && b[0] <= b[1])) {
      return (a[1] - a[0]) > (b[1] - b[0]);
    }
    if ((a[0] >= a[1] && b[0] >= b[1])) {
      return (a[0] - a[1]) < (b[0] - b[1]);
    }
    if (a[0] <= a[1] && b[0] >= b[1])
      return true;
    return false;
  };
};

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    sort(costs.begin(), costs.end(), compare());
    int len = costs.size();
    int half = len / 2;
    for (vector<int> cost : costs) {
      cout << "[" << cost[0] << ", " << cost[1] << "]";
    }
    cout << endl;
    int count = 0;
    int res = 0;
    while (count < half) {
      res += costs[count][0];
      count++;
    }
    while (count < len) {
      res += costs[count][1];
      count++;
    }
    cout << endl;
    return res;
  };
};

int main() {
  Solution sol = Solution();
  vector<vector<vector<int>>> cases = {
      {{10, 20}, {30, 200}, {400, 50}, {30, 20}},
      {{10, 20}, {30, 200}, {400, 500}, {30, 200}},
      {{100, 20}, {300, 200}, {4000, 500}, {3000, 200}},
  };
  for (vector<vector<int>> costs : cases) {
    int res = sol.twoCitySchedCost(costs);
    cout << res << endl;
  }
  return 0;
}
