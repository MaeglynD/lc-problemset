#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
  public:
    struct Node {
      Node* children[26] = {NULL};
      bool eow = false;
    };
    string cur;
    vector<string> ans;

    void dfs(vector<vector<char>>& board, Node* node, int y, int x) {
      if (
        x == board[0].size() || x < 0 || 
        y == board.size() || y < 0 ||
        board[y][x] == '*' ||
        !node->children[board[y][x]-'a']
      ) {
        return;
      }

      node = node->children[board[y][x]-'a'];
      cur.push_back(board[y][x]);
      board[y][x] = '*';

      if (node->eow) {
        ans.push_back(cur);
        node->eow = false;
      }

      dfs(board, node, y+1, x);
      dfs(board, node, y-1, x);
      dfs(board, node, y, x+1);
      dfs(board, node, y, x-1);

      board[y][x] = cur.back();
      cur.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      Node* root = new Node();

      for (string& w : words) {
        Node* tmp = root;

        for (char c : w) {
          c-='a';

          if (!tmp->children[c]) {
            tmp->children[c] = new Node();
          }

          tmp = tmp->children[c];
        }

        tmp->eow = true;
      }

      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
          dfs(board, root, i, j);
        }
      }

      return ans;
    }
};

int main () {
  Solution test;
  vector<pair<vector<vector<char>>, vector<string>>> testCases = {
    {
      {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}},
      {"oath","pea","eat","rain"}
    }
  };

  for (auto& [matrix, words] : testCases) {
    auto found = test.findWords(matrix, words);

    for (auto& w : found) {
      cout << w << ", ";
    }

    cout << endl;
  }
  return 0;
}