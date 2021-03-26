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

class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {
public:
  Node *flatten(Node *head) {
    Node *ret = new Node();
    ret->next = nullptr;
    ret->prev = nullptr;
    ret->child = nullptr;
    Node *update = ret;
    list<Node *> stack;
    unordered_map<Node *, bool> visited;
    stack.push_front(head);
    update->val = head->val;
    while (!stack.empty()) {
      Node *currentNode = stack.front();
      if (currentNode->child != nullptr) {
        stack.push_front(currentNode->child);
        update->next = new Node();
        update->next->prev = update;
        update->next->next = nullptr;
        update->next->child = nullptr;
        update = update->next;
        update->val = currentNode->child->val;
        currentNode->child = nullptr;
      } else {
        stack.pop_front();
        if (currentNode->next != nullptr) {
          stack.push_front(currentNode->next);
          update->next = new Node();
          update->next->prev = update;
          update->next->next = nullptr;
          update->next->child = nullptr;
          update = update->next;
          update->val = currentNode->next->val;
        }
      }
    }
    return ret;
  }
};

int main() {
  Node *n1 = new Node();
  n1->next = new Node();
  n1->val = 2;
  n1->child = new Node();
  n1->child->val = 5;
  n1->next->val = 3;
  n1->next->prev = n1;
  Solution sol = Solution();
  Node *n2 = sol.flatten(n1);
  cout << n2->val << " : " << n2->next->val << " : " << n2->next->next->val
       << endl;
}
