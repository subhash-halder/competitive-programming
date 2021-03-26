#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace ::std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    list<TreeNode *> queueP;
    list<TreeNode *> queueQ;
    queueP.push_back(p);
    queueQ.push_back(q);
    while (!queueP.empty() && !queueQ.empty()) {
      TreeNode *pLocal = queueP.front();
      TreeNode *qLocal = queueQ.front();
      queueP.pop_front();
      queueQ.pop_front();
      if ((pLocal == nullptr && qLocal != nullptr) ||
          (pLocal != nullptr && qLocal == nullptr)) {
        return false;
      }
      if (pLocal != nullptr && pLocal->val != qLocal->val) {
        return false;
      }
      queueP.push_back(pLocal->left);
      queueP.push_back(pLocal->right);
      queueQ.push_back(qLocal->left);
      queueQ.push_back(qLocal->right);
    }
    if (queueP.empty() && queueQ.empty()) {
      return true;
    }
    return false;
  }
};
