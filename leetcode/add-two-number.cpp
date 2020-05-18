#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace ::std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *res;
  ListNode *track;
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    int i = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int s = carry;
      if (l1 != nullptr) {
        s += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        s += l2->val;
        l2 = l2->next;
      }
      carry = s / 10;
      int val = s % 10;
      if (i == 0) {
        res = new ListNode(val);
        track = res;
      } else {
        ListNode *newNode = new ListNode(val);
        track->next = newNode;
        track = newNode;
      }
      i++;
    }
    return res;
  }
};

int main() {
  Solution s = Solution();
  ListNode n1 = ListNode(2);
  ListNode n2 = ListNode(4);
  ListNode n3 = ListNode(9);
  n1.next = &n2;
  n2.next = &n3;
  ListNode l1 = ListNode(5);
  ListNode l2 = ListNode(6);
  ListNode l3 = ListNode(4);
  l1.next = &l2;
  l2.next = &l3;

  ListNode *res = s.addTwoNumbers(&n1, &l1);
  for (ListNode *i = res; i != nullptr; i = i->next) {
    cout << i->val << " ";
  }
  cout << endl;
  return 0;
}
