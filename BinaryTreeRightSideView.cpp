#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

vector<int> rightSideView(TreeNode* root) {
  if (!root) return {};

  vector<int> ans;
  queue<TreeNode*> q;

  q.push(root);

  while(!q.empty()) {
    int qs = q.size();

    for (int i = 0; i < qs; ++i) {
      root = q.front();

      if (i == qs-1) ans.push_back(root->val);
      if (root->left) q.push(root->left);
      if (root->right) q.push(root->right);

      q.pop();
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> testCases = {
    {1,2,3,-1,5,-1,4},
    {1,-1,3},
  };
  
  for (auto& test : testCases) {
    auto res = rightSideView(constructTree(test));

    for (auto& x : res) {
      cout << x << ", ";
    }

    cout << endl;
  }
  
  return 0;
}