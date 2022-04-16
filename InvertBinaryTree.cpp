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

TreeNode* invertTree(TreeNode* root) {
  if (root && (root->left || root->right)) {
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
  }

  return root; 
}

int main () {
  TreeNode left{1}, right{3}, root{2, &left, &right};
  
  cout << "root = " << root.val;
  cout << ", left = " << root.left->val;
  cout << ", right = " << root.right->val << endl;

  root = *invertTree(&root);

  cout << "root = " << root.val; 
  cout << ", left = " << root.left->val;
  cout << ", right = " << root.right->val;

  return 0;
}