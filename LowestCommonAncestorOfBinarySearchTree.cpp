#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  while (root) {
    if (p->val < root->val && q->val < root->val) {
      root = root->left;
    } else if (p->val > root->val && q->val > root->val) {
      root = root->right;
    } else {
      break;
    }
  }

  return root;
}

int main () {
  TreeNode* root;

  root = constructTree({6,2,8,0,4,7,9,-1,-1,3,5});
  cout << lowestCommonAncestor(root, root->left->right->left, root->left->right->right)->val << endl;

  root = constructTree({2,1});
  cout << lowestCommonAncestor(root, root, root->left)->val;

  return 0;
}