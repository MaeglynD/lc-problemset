#include <bits/stdc++.h>
#include "../utils/linked-list.h"
using namespace std;
typedef long long ll;

ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
  ListNode* ans;

  for (auto node : lists) {
    while(node) {
      pq.push({ node->val, node });
      node = node->next;
    }
  }

  if (pq.empty())
    return ans;

  ans = pq.top().second;

  while(!pq.empty()) {
    ListNode* parent = pq.top().second;

    pq.pop();

    parent->next = pq.empty() ? nullptr : pq.top().second;
  }

  return ans;
}

int main () {
  vector<vector<vector<int>>> testCases = {
    {{1,4,5}, {1,3,4}, {2,6}},
    {},
  };

  for (auto& test : testCases) {
    vector<ListNode*> args;

    for (auto& list : test) 
      args.push_back(createLinkedList(list));

    ListNode* res = mergeKLists(args);

    logLinkedList(res);
  }

  return 0;
}