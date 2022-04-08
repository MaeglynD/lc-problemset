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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* head = new ListNode();
  ListNode* tail = head;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      tail->next = list1;
      list1 = list1->next;
    } else {
      tail-> next = list2;
      list2 = list2->next;
    }
    
    tail = tail->next;
  }

  if (list1) {
    tail->next = list1;
  } else if (list2) {
    tail->next = list2;
  }

  return head->next;
}

int main () {
  ListNode *head1 = new ListNode(0);
  ListNode *head2 = new ListNode(1);
  ListNode *tmp = head1; 

  // 0, 0, 3, 6, 9, 12
  for (int i = 0; i < 5; ++i) {
    tmp->next = new ListNode(i*3);
    tmp = tmp->next;
  }

  tmp = head2;

  // 1, 2, 3, 4, 5
  for (int i = 2; i < 6; ++i) {
    tmp->next = new ListNode(i);
    tmp = tmp->next;
  }

  ListNode *ans = mergeTwoLists(head1, head2);

  while (ans) {
    cout << ans->val << ", ";
    ans = ans->next;
  }

  return 0;
}
