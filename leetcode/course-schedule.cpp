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

struct Status {
  bool processing;
};

class Solution {
public:
  bool checkCycle(unordered_map<int, list<int>> &graph, int root,
                  unordered_map<int, Status> &m) {
    if (graph.find(root) == graph.end()) {
      return false;
    }
    list<int> v = graph[root];
    for (int e : v) {
      if (m.find(e) != m.end()) {
        if (m[e].processing) {
          return true;
        }
        continue;
        ;
      }
      m[e] = {true};
      if (checkCycle(graph, e, m)) {
        return true;
      }
      m[e] = {false};
    }
    return false;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, list<int>> graph;
    for (vector<int> ps : prerequisites) {
      graph[ps[1]].push_back(ps[0]);
    }
    int graphLen = graph.size();
    unordered_map<int, Status> m;
    for (pair<int, list<int>> g : graph) {
      if (m.find(g.first) != m.end()) {
        continue;
      }
      m[g.first] = {true};
      if (checkCycle(graph, g.first, m)) {
        return false;
      }
      m[g.first] = {false};
    }
    return true;
  }
};

int main() {
  string a = "adsfdf";
  Solution sol = Solution();

  struct testCase {
    int noOfCourse;
    vector<vector<int>> prerequisites;
    bool result;
  };

  testCase t[] = {
      {2, {{0, 1}}, true},
      {2, {{0, 1}, {1, 0}}, false},
      {10, {{0, 1}, {1, 2}, {2, 3}, {2, 4}}, true},
      {10, {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}}, true},
      {10, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 2}}, false},
      {3, {{0, 2}, {1, 2}, {2, 0}}, false},
      {3, {{1, 0}, {1, 2}, {0, 1}}, false},
      {3, {{1, 0}, {2, 0}, {0, 2}}, false},
  };

  cout << "Testing ......\n";
  int count = 1;
  for (testCase tc : t) {
    int res = sol.canFinish(tc.noOfCourse, tc.prerequisites);
    cout << count << endl;
    assertm(res == tc.result, "");
    count++;
  }
  cout << endl;
}
