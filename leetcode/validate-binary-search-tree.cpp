#include <cstdint>

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
  bool validate(TreeNode *root, long max, long min) {
    if (root == nullptr) {
      return true;
    }
    int val = root->val;

    if (val >= max)
      return false;
    if (val <= min)
      return false;

    if (!validate(root->left, val, min))
      return false;
    if (!validate(root->right, max, val))
      return false;

    return true;
  }
  bool isValidBST(TreeNode *root) {
    return validate(root, INT64_MAX, INT64_MIN);
  }
};
