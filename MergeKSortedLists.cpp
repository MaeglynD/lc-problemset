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

ListNode* mergeKLists (vector<ListNode*> lists) {
  ListNode *head = new ListNode;
  ListNode *tail = head;

  map<int, vector<ListNode*>> hm; 

  for (auto& sortedList : lists) {
    ListNode* tmp = sortedList;

    while (tmp) {
      if (hm.count(tmp->val)) {
        hm[tmp->val].push_back(tmp);
      } else {
        hm[tmp->val] = { tmp };
      }

      tmp = tmp->next;
    }
  }

  for (auto& [v, nodes] : hm) {
    for (auto& n : nodes) {
      tail->next = n;	
      tail = tail->next;
    }
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

  ListNode *ans = mergeKLists({ head1, head2 });

  while (ans) {
    cout << ans->val << ", ";
    ans = ans->next;
  }

  return 0;
}
