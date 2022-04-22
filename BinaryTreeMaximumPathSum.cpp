#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

int dfs(TreeNode* root, int& total) {
  if (!root) return 0;

  int l = max(0, dfs(root->left, total));
  int r = max(0, dfs(root->right, total));

  total = max(total, root->val+r+l);
  
  return root->val+max(r, l);
}

int maxPathSum(TreeNode* root) {
  int total = INT_MIN; 

  dfs(root, total);

  return total;
}

int main () {
  vector<vector<int>> testCases = {
    {1,2,3},
    {-10,9,20,-1,-1,15,7}
  };

  for (auto& test : testCases) {
    cout << maxPathSum(constructTree(test)) << endl;
  }

  return 0;
}