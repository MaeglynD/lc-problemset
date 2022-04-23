#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Trie {
  public:
    struct TrieNode {
      bool isLeaf = false;
      TrieNode* children[26] = {NULL};
    };
    TrieNode* root;

    Trie() {
      root = new TrieNode();
    }

    void insert(string word) {
      TrieNode* tmp = root;

      for (char c : word) {
        c-='a';

        if (!tmp->children[c]) {
          tmp->children[c] = new TrieNode();
        }

        tmp = tmp->children[c];
      }

      tmp->isLeaf = true;
    }

    bool startsWith(string prefix) {
      return search(prefix, true);
    }

    bool search(string word, bool isPrefix = false) {
      TrieNode* tmp = root;

      for (char c : word) {
        c-='a';

        if (!tmp->children[c]) {
          return false;
        }
        
        tmp = tmp->children[c];
      }

      return isPrefix || tmp->isLeaf;
    }
};

int main () {
  vector<pair<vector<string>, vector<string>>> testCases = {
    {
      {"insert", "search", "search", "startsWith", "insert", "search"},
      {"apple", "apple", "app", "app", "app", "app"}
    }
  };

  for (auto& [commands, words] : testCases) {
    Trie test;

    for (int i = 0; i < commands.size(); ++i) {
      cout << commands[i] << " ~ " << words[i] << ": ";

      if (commands[i] == "insert") {
        test.insert(words[i]);
      } else if (commands[i] == "search") {
        cout << test.search(words[i]);
      } else {
        cout << test.startsWith(words[i]);
      }

      cout << endl;
    }

    cout << "----" << endl;
  }


  return 0;
}