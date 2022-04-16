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

int maxDepth(TreeNode* root) {
  return root ? max(maxDepth(root->left), maxDepth(root->right))+1 : 0;
}

int main () {
  TreeNode l2{4}, l1{5, &l2}, left{1, &l1}, right{3}, root{2, &left, &right};

  cout << maxDepth(&root) << endl;

  return 0;
}