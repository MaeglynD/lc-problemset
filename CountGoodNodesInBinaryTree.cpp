#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

void dfs(TreeNode* node, int& ans, int threshold) {
  if (node->val >= threshold) ans++;

  threshold = max(threshold, node->val);

  if (node->left) dfs(node->left, ans, threshold);
  if (node->right) dfs(node->right, ans, threshold);
}

int goodNodes(TreeNode* root) {
  int ans = 0;

  dfs(root, ans, INT_MIN);

  return ans;
}

int main() {
  vector<vector<int>> testCases = {
    {3,1,4,3,-1,1,5},
    {3,3,-1,4,2},
    {1},
  };

  for (auto& test : testCases) {
    cout << goodNodes(constructTree(test)) << endl;
  }
  
  return 0;
}