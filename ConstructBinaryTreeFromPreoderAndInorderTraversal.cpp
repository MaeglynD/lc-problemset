#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

// 2nd solution, 35ms, 26.4mb 
TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& hm, int pi, int l, int r) {
  TreeNode* node = new TreeNode(preorder[pi]);
  int ii = hm[preorder[pi]];

  if (l < ii) {
    node->left = dfs(preorder, inorder, hm, pi+1, l, ii-1);

    if (r > ii) {
      node->right = dfs(preorder, inorder, hm, pi+(ii-l)+1, ii+1, r);
    }
  } else if (r > ii) {
    node->right = dfs(preorder, inorder, hm, pi+1, ii+1, r);
  }

  return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, int> hm;

  for (int i = 0; i < inorder.size(); ++i) {
    hm[inorder[i]] = i;
  }

  return dfs(preorder, inorder, hm, 0, 0, inorder.size()-1);
}

// blind initial solution, 12ms / 25mb
TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
  vector<TreeNode*> nodes(preorder.size());
  vector<bool> visited(inorder.size(), false);
  unordered_map<int, int> hm; 

  for (int i = 0; i < preorder.size(); ++i) {
    nodes[i] = new TreeNode(preorder[i]);
    hm[inorder[i]] = i;
  }

  for (int i = 0; i < preorder.size(); ++i) {
    int io = hm[preorder[i]];
    bool hasRightItem = io < inorder.size()-1 && !visited[io+1];

    if (io > 0 && !visited[io-1]) {
      nodes[i]->left = nodes[i+1];

      if (hasRightItem) {
        int j = io-2;

        while (j > -1 && !visited[j]) j--;

        nodes[i]->right = nodes[i+(io-(j+1))+1];
      }
    } else if (hasRightItem){
      nodes[i]->right = nodes[i+1];
    }

    visited[io] = true;
  }

  return nodes[0];
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