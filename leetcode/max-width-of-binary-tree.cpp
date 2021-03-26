#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

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
  int widthOfBinaryTree(TreeNode *root) {
    int maxWidth = 1;
    unordered_map<TreeNode *, int> width;
    unordered_map<TreeNode *, int> height;
    unordered_map<int, int> startI;
    list<TreeNode *> queue;
    queue.push_back(root);
    width[root] = 1;
    height[root] = 1;
    while (!queue.empty()) {
      TreeNode *currentNode = queue.front();
      queue.pop_front();
      if (currentNode->left != nullptr) {
        height[currentNode->left] = height[currentNode] + 1;
        queue.push_back(currentNode->left);
        if (startI.find(height[currentNode->left]) == startI.end()) {
          startI[height[currentNode->left]] = width[currentNode] * 2 - 2;
        }
        width[currentNode->left] =
            width[currentNode] * 2 - 1 - startI[height[currentNode->left]];
        maxWidth = max(maxWidth, width[currentNode->left]);
      }
      if (currentNode->right != nullptr) {
        height[currentNode->right] = height[currentNode] + 1;
        queue.push_back(currentNode->right);
        if (startI.find(height[currentNode->right]) == startI.end()) {
          startI[height[currentNode->right]] = width[currentNode] * 2 - 1;
        }
        width[currentNode->right] =
            width[currentNode] * 2 - startI[height[currentNode->right]];
        maxWidth = max(maxWidth, width[currentNode->right]);
      }
    }
    return maxWidth;
  }
};
