#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

void dfs(TreeNode* node, bool& valid, TreeNode* l, TreeNode* r) {
  if (!valid || !node) return;

  if ((l && node->val <= l->val) || (r && node->val >= r->val)) {
    valid = false;
    return;
  }

  if (node->left) {
    dfs(node->left, valid, l, node);
  }

  if (node->right) {
    dfs(node->right, valid, node, r);
  }
}

bool isValidBST(TreeNode* root) {
  bool valid = true;

  dfs(root, valid, NULL, NULL);

  return valid; 
}

int main() {
  vector<vector<int>> testCases = {
    {2,1,3},
    {5,1,4,-1,-1,3,6},
    {5,4,6,-1,-1,3,7},
    {2,2,2},
    {2147483647}
  };

  for (auto& test : testCases) {
    cout << isValidBST(constructTree(test)) << endl;
  }

  return 0;
}