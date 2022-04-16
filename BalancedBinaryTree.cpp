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

int dfs(TreeNode* node, bool& balanced) {
  if (!node || !balanced) return 0;

  int l = dfs(node->left, balanced);
  int r = dfs(node->right, balanced);

  if (balanced) {
    balanced = abs(l-r) < 2;
  }

  return max(l, r) +1;
}

bool isBalanced(TreeNode* root) {
  bool balanced = true;

  dfs(root, balanced);

  return balanced;
}

int main () {
  TreeNode l2{4}, l1{5, &l2}, left{1, &l1}, right{3}, root{2, &left, &right};

  cout << isBalanced(&root);

  return 0;
}