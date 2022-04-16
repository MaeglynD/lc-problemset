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

int maxDepth(TreeNode* root, int& maxPath) {
  if (!root) return 0;

  int a = maxDepth(root->left, maxPath);
  int b = maxDepth(root->right, maxPath);

  maxPath = max(maxPath, a+b);

  return 1 + max(a, b);
}

int diameterOfBinaryTree(TreeNode* root) {
  int maxPath = 0;

  maxDepth(root, maxPath);

  return maxPath;
}

int main () {
  TreeNode l2{4}, l1{5, &l2}, left{1, &l1}, right{3}, root{2, &left, &right};

  cout << diameterOfBinaryTree(&root) << endl;

  return 0;
}