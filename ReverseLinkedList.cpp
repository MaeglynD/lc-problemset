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

ListNode* reverseList(ListNode* head) {
  ListNode *next, *prev = nullptr;

  while (head) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }

  return prev; 
}

int main () {
  ListNode *head = new ListNode(1);
  ListNode *tmp = head; 

  for (int i = 0; i < 5; ++i) {
    tmp->next = new ListNode(tmp->val+1);
    tmp = tmp->next;
  }

  tmp = head;
  cout << "old list: ";

  while (tmp != nullptr) {
    cout << tmp->val << ", ";
    tmp = tmp->next;
  }

  tmp = reverseList(head);
  cout << endl << "new list: ";

  while (tmp != nullptr) {
    cout << tmp->val << ", ";
    tmp = tmp->next;
  }

	return 0;
}
