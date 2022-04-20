#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& hm, int pi, int l, int r) {
  TreeNode* node = new TreeNode(preorder[pi]);
  int ii = hm[preorder[pi]];

  if (l < ii) 
    node->left = dfs(preorder, inorder, hm, pi+1, l, ii-1);
  if (r > ii) 
    node->right = dfs(preorder, inorder, hm, pi+(ii-l)+1, ii+1, r);

  return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, int> hm;

  for (int i = 0; i < inorder.size(); ++i) {
    hm[inorder[i]] = i;
  }

  return dfs(preorder, inorder, hm, 0, 0, inorder.size()-1);
}

int main() {
  vector<pair<vector<int>, vector<int>>> testCases = {
    {{3,9,20,15,7}, {9,3,15,20,7}},
    {{-1}, {-1}}
  };

  for (auto& [p, i] : testCases) {
    logTree(buildTree(p, i));
  }

  return 0;
}