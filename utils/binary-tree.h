#include <vector>
#include <queue>
using namespace std; 

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

TreeNode* constructTree(vector<int> nums) {
  TreeNode* root = new TreeNode(nums[0]);
  queue<TreeNode*> q; 
  int i = 1;

  q.push(root);

  while (!q.empty() && i < nums.size()) {
    TreeNode* tmp = q.front();

    if (tmp) {
      tmp->left = nums[i] == -1 ? nullptr : new TreeNode(nums[i]);
      q.push(tmp->left);
      i++;

      if (i < nums.size()) {
        tmp->right = nums[i] == -1 ? nullptr : new TreeNode(nums[i]);
        q.push(tmp->right);
        i++;
      }
    }

    q.pop();
  }

  return root;
}

void logTree(TreeNode* root) {
  queue<TreeNode*> q;

  q.push(root);

  cout << "Tree: " << root->val << ", ";

  while (!q.empty()) {
    TreeNode* tmp = q.front();
    
    if (tmp) {
      cout << (tmp->left ? tmp->left->val : -1) << ", ";
      cout << (tmp->right ? tmp->right->val : -1) << ", ";

      q.push(tmp->left);
      q.push(tmp->right);
    }

    q.pop();
  }

  cout << endl;
}