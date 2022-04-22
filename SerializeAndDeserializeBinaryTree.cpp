#include <bits/stdc++.h>
#include "utils/binary-tree.h"
using namespace std;
typedef long long ll;

// 2nd solution
class Codec2 {
  public:
    string serialize(TreeNode* root) {
      if (!root) return "x";
      return to_string(root->val) + ' ' +  serialize(root->left) + ' ' + serialize(root->right);
    }

    TreeNode* getNextNode(string& data, int& i) {
      if (data[i] == 'x') {
        i+=2;
        return NULL;
      }

      int len = data.find_first_of(' ', i) - i;
      TreeNode* node = new TreeNode(stoi(data.substr(i, len)));

      i += len+1;

      node->left = getNextNode(data, i);
      node->right = getNextNode(data, i);

      return node;
    }

    TreeNode* deserialize(string data) {
      if (!data.size()) return NULL;

      int i = 0;

      return getNextNode(data, i);
    }
};

// Initial solution
class Codec {
  public:
    const char nullFlag = 'x';
    const char delimFlag = ' ';

    string serialize(TreeNode* root) {
      string ans = "";

      if (!root) {
        return ans;
      }

      queue<TreeNode*> q;

      q.push(root);

      while (!q.empty()) {
        TreeNode* node = q.front();

        if (node) {
          ans+=to_string(node->val);
          q.push(node->left);
          q.push(node->right);
        } else {
           ans+=nullFlag;
        }

        ans+=delimFlag;
        q.pop();
      }

      return ans;
    }

    TreeNode* getNextNode(string& data, int& i) {
      if (data[i] == nullFlag) {
        i+=2;
        return nullptr;
      }

      int len = data.find(delimFlag, i)-i;
      TreeNode* node = new TreeNode(stoi(data.substr(i, len)));

      i+=len+1;

      return node;
    }

    TreeNode* deserialize(string data) {
      if (!data.size()) return nullptr;

      int i = 0;
      queue<TreeNode*> q;
      TreeNode* root = getNextNode(data, i);

      q.push(root);

      while(i < data.size() && !q.empty()) {
        TreeNode* node = q.front();

        node->left = getNextNode(data, i);
        node->right = getNextNode(data, i);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

        q.pop();
      }

      return root;
    }
};

int main () {
  Codec codec;
  vector<vector<int>> testCases = {
    {1,2,3,-1,-1,4,5}
  };

  for (auto& test : testCases) {
    string serialized = codec.serialize(constructTree(test));
    auto deserialized = codec.deserialize(serialized);

    cout << serialized << endl;
    logTree(deserialized);
  }

  return 0;
}