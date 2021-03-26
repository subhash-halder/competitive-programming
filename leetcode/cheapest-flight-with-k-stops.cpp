#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    int ret = INT32_MAX;
    // stack for dfs search
    list<pair<int, int>> stack;
    // Make an adjecency list of the graph
    vector<pair<int, int>> adjList[n];
    // creating the adjecency list
    for (vector<int> flight : flights) {
      adjList[flight[0]].push_back({flight[1], flight[2]});
    }
    for (int i = 0; i < n; i++) {
      for (pair<int, int> ali : adjList[i])
        printf("%d -> %d: %d, ", i, ali.first, ali.second);
    }
    // add the root of the graph
    stack.push_back({src, -1});
    int cost = 0;
    int maxDepth = K;
    unordered_map<int, bool> visited;
    int aChildI = 0;
    while (!stack.empty()) {
      pair<int, int> curInd = stack.front();
      int goToCost = adjList[curInd.first][stack.front().second].second;
      if (curInd.first == dst) {
        cost += goToCost;
        ret = min(ret, cost);
        cost -= goToCost;
        stack.pop_front();
        continue;
      }
      if (curInd.second == -1) {
        stack.push_front(adjList[src][aChildI]);
        visited.clear();
        cost = 0;
        maxDepth = K;
        continue;
      }
      for ()
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  struct testCase {
    int n;
    vector<vector<int>> flights;
    int src;
    int dest;
    int k;
  };

  vector<testCase> testCases = {{
      3,
      {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}},
      0,
      2,
      1,
  }};
  for (testCase tc : testCases) {
    int res = sol.findCheapestPrice(tc.n, tc.flights, tc.src, tc.dest, tc.k);
    printf("result: %d\n", res);
  }
  return 0;
}
