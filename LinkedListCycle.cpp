#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int v = 0, ListNode* n = nullptr) {
    val = v;
    next = n;
  }
};

bool hasCycle(ListNode *head) {
  ListNode *slow = head, *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }

  return false;
}

int main () {
  ListNode *head = new ListNode(1);
  ListNode *tmp = head; 

  for (int i = 0; i < 5; ++i) {
    tmp->next = new ListNode(tmp->val+1);
    tmp = tmp->next;
  }

  return 0;
}
