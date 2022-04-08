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

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *tmp = new ListNode(0, head);
  ListNode *ptr1 = tmp; 
  ListNode *ptr2 = head;

  for (int i = 0; i < n; ++i) {
    ptr2 = ptr2->next;
  }

  while(ptr2) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  ptr1->next = ptr1->next->next;

  return tmp->next;
}

int main () {
  ListNode *head1 = new ListNode(1);
  ListNode *tmp = head1; 

  // 0, 0, 3, 6, 9, 12
  for (int i = 0; i < 5; ++i) {
    tmp->next = new ListNode(i*3);
    tmp = tmp->next;
  }

  ListNode *ans = removeNthFromEnd(head1, 1);

  while (ans) {
    cout << ans->val << ", ";
    ans = ans->next;
  }

  return 0;
}
