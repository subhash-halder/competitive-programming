#include <ios>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

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
  /*
   * recurssion
  bool checkMirrot(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr)
      return true;
    if (t1 == nullptr || t2 == nullptr)
      return false;
    if (t1->val == t2->val) {
      if (!checkMirrot(t1->left, t2->right))
        return false;
      if (!checkMirrot(t1->right, t2->left))
        return false;
    } else {
      return false;
    }
    return true;
  }
  bool isSymmetric(TreeNode *root) { return checkMirrot(root, root); }
  */

  bool isSymmetric(TreeNode *root) {
    list<TreeNode *> queue = {root, root};
    while (!queue.empty()) {
      TreeNode *t1 = queue.front();
      queue.pop_front();
      TreeNode *t2 = queue.front();
      queue.pop_front();

      if ((t1 == nullptr && t2 != nullptr) ||
          (t1 != nullptr && t2 == nullptr)) {
        return false;
      }
      if (t1 != nullptr && t2 != nullptr) {
        if (t1->val != t2->val) {
          return false;
        }
        queue.push_back(t1->left);
        queue.push_back(t2->right);
        queue.push_back(t1->right);
        queue.push_back(t2->left);
      }
    }
    return true;
  }
};
