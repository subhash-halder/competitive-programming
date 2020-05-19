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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (root == nullptr)
      return ret;
    int prevRemain = 1;
    int newRemain = 0;
    int height = 0;
    ret.push_back(vector<int>{});
    list<TreeNode *> queue = {root};
    while (!queue.empty()) {
      if (prevRemain == 0) {
        prevRemain = newRemain;
        newRemain = 0;
        height++;
        ret.push_back(vector<int>{});
      }
      TreeNode *t = queue.front();
      queue.pop_front();
      ret[height].push_back(t->val);
      if (t->left != nullptr) {
        newRemain++;
        queue.push_back(t->left);
      }
      if (t->right != nullptr) {
        newRemain++;
        queue.push_back(t->right);
      }
      prevRemain--;
    }
    return ret;
  }
};
