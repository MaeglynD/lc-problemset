#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

void dfs(TreeNode* node, int& ans, int& i) {
  if (ans || !node) return;

  dfs(node->left, ans, i);

  i--;

  if (i == 0) {
    ans = node->val;
  }

  dfs(node->right, ans, i);
}

int kthSmallest(TreeNode* root, int k) {
  int ans = 0;

  dfs(root, ans, k);

  return ans;
}

int main() {
  vector<pair<vector<int>, int>> testCases = {
    {{3,1,4,-1,2}, 1},
    {{5,3,6,2,4,-1,-1,1}, 3}
  };

  for (auto& [tree, num] : testCases) {
    cout << kthSmallest(constructTree(tree), num) << endl;
  }

  return 0;
}