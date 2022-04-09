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

void reorderList(ListNode *head){
  if (!head || !head->next) {
    return;
  }

  ListNode *lptr = head, *rptr = head->next, *curr;
  
  while (rptr && rptr->next) {
    lptr = lptr->next;	
    rptr = rptr->next->next;
  }
  
  rptr = lptr->next;
  curr = rptr;
  lptr->next = nullptr;
  lptr = nullptr;

  while (curr){
    rptr = rptr->next;
    curr->next = lptr;
    lptr = curr;
    curr = rptr;
  }

  // From here forward we simply use rptr as a tmp var
  while (lptr) {
    rptr = lptr->next;
    lptr->next = head->next;
    head->next = lptr;
    head = lptr->next; 
    lptr = rptr; 
  }
}

int main () {
  ListNode *head = new ListNode(1);
  ListNode *tmp = head; 

  // 1, 0, 3, 6, 9, 12
  // converts to..
  // 1, 12, 0, 9, 3, 6
  for (int i = 0; i < 5; ++i) {
    tmp->next = new ListNode(i*3);
    tmp = tmp->next;
  }

  reorderList(head);

  while (head) {
    cout << head->val << ", ";
    head = head->next;
  }

  return 0;
}
