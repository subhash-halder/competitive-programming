#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <list>
#include <unordered_map>
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
  TreeNode *generateBST(TreeNode *root, vector<int> &v, int len, int &i,
                        int minVal, int maxVal) {

    if (i < len && v[i] < root->val && v[i] >= minVal) {
      TreeNode *node = new TreeNode(v[i]);

      root->left = generateBST(node, v, len, ++i, minVal, root->val - 1);
    }
    if (i < len && v[i] > root->val && v[i] <= maxVal) {
      TreeNode *node = new TreeNode(v[i]);
      root->right = generateBST(node, v, len, ++i, root->val + 1, maxVal);
    }

    return root;
  }
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    if (preorder.size() == 0) {
      return nullptr;
    }
    int i = 1;
    return generateBST(new TreeNode(preorder[0]), preorder, preorder.size(), i,
                       INT32_MIN, INT32_MAX);
  }
};

int main() {
  Solution sol = Solution();
  vector<int> vec = {8, 5, 1, 7, 10, 12};
  TreeNode *res = sol.bstFromPreorder(vec);
  cout << res << endl;
  return 0;
}
