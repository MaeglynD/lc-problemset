#include <vector>
using namespace std; 

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int v = 0, ListNode* n = nullptr) {
    val = v;
    next = n;
  }
};

ListNode* createLinkedList(vector<int> nums) {
  if (nums.empty()) 
    return nullptr;

  ListNode* root = new ListNode(), *tmp = root;

  for (int& n : nums) {
    tmp->next = new ListNode(n);
    tmp = tmp->next;
  }

  return root->next;
}

void logLinkedList(ListNode* root) {
  cout << "[";

  while(root) {
    cout << root->val << ", ";
    root = root->next;
  }

  cout << "]" << endl;
}