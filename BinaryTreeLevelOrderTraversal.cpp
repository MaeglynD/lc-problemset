#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

vector<vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};

  vector<vector<int>> order;
  queue<TreeNode*> q;

  q.push(root);

  while (!q.empty()) {
    int qs = q.size();

    if (!qs) break;

    vector<int> children(qs);

    for (int i = 0; i < qs; ++i) {
      root = q.front();
      children[i] = root->val;

      if (root->left) q.push(root->left);
      if (root->right) q.push(root->right);

      q.pop();
    }

    order.push_back(children); 
  }

  return order;
}

int main() {
  vector<vector<int>> testCases = {
    {3,9,20,-1,-1,15,7},
    {1},
    {1,2,3,4,-1,-1,5}
  };

  for (auto& test : testCases) {
    auto res = levelOrder(constructTree(test));

    cout << "[";

    for (auto& x : res) {
      cout << "[";

      for (auto& y : x) {
        cout << y << ", ";
      }

      cout << "], ";
    }

    cout << "]" << endl;
  }

  return 0;
}