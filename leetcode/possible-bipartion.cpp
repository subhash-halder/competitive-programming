#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
private:
  struct node {
    bool visited;
    vector<node> child;
  };
  unordered_map<int, int> visited;
  unordered_map<int, list<int>> adjList;
  bool possible = true;

public:
  void bfs(list<int> &ll, int color, int height) {
    if (ll.size() == 0) {
      return;
    }
    list<int> nextll;
    int nextColor = color == 0 ? 1 : 0;
    int nextHeight = ++height;
    for (int l : ll) {
      if ((visited.find(l) != visited.end())) {
        if (visited[l] != color) {
          possible = false;
          return;
        }
        continue;
      }
      visited[l] = color;
      if (adjList.find(l) != adjList.end()) {
        for (int al : adjList[l]) {
          nextll.push_back(al);
        }
      }
    }
    bfs(nextll, nextColor, nextHeight);
  }
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    for (vector<int> dislike : dislikes) {
      if (adjList.find(dislike[0]) != adjList.end()) {
        adjList[dislike[0]].push_back(dislike[1]);
      } else {
        adjList[dislike[0]] = {dislike[1]};
      }
    }

    for (int i = 0; i <= N; i++) {
      if (visited.find(i) == visited.end()) {
        list<int> ll = {i};
        bfs(ll, 0, 0);
      }
    }
    return possible;
  }
};

int main() {

  struct testCase {
    int N;
    vector<vector<int>> input;
    bool result;
  };

  testCase t[] = {
      {5, {}, true},
      {4, {{1, 2}, {1, 3}, {2, 4}}, true},
      {3, {{1, 2}, {1, 3}, {2, 3}}, false},
      {5, {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}}, false},
      {10,
       {{4, 7},  {4, 8},  {2, 8}, {8, 9},  {1, 6},  {5, 8}, {1, 2}, {6, 7},
        {3, 10}, {8, 10}, {1, 5}, {7, 10}, {1, 10}, {3, 5}, {3, 6}, {1, 4},
        {3, 9},  {2, 3},  {1, 9}, {7, 9},  {2, 7},  {6, 8}, {5, 7}, {3, 4}},
       true},
  };

  cout << "Testing ......\n";
  for (testCase tc : t) {
    Solution sol = Solution();
    bool res = sol.possibleBipartition(tc.N, tc.input);
    cout << res << endl;
    assertm(res == tc.result, "");
  }
  cout << endl;
}
