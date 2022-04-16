#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int v = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) {
    val = v;
    left = l;
    right = r;
  }
};

bool isSame(TreeNode* p, TreeNode* q) {
  return !p && !q || p && q && p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  return root && (isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}

int main () {
  TreeNode a2{4}, a1{5, &a2}, left{1, &a1}, right{3}, root{2, &left, &right};
  TreeNode b2{4}, b1{5, &b2}, leftb{1, &b1}, rightb{3}, rootb{2, &leftb, &rightb};

  cout << isSubtree(&root, &rootb) << endl;

  a1.val = 9;

  cout << isSubtree(&root, &rootb) << endl;

  return 0;
}