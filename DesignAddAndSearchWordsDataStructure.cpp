#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class WordDictionary {
  public:
    struct Node {
      Node* children[26] = {NULL};
      bool isLeaf = false;
    };
    Node* root;

    WordDictionary() {
      root = new Node();
    }

    void addWord(string word) {
      Node* node = root;

      for (auto c : word) {
        c-='a';

        if (!node->children[c]) {
          node->children[c] = new Node();
        }

        node = node->children[c];
      }

      node->isLeaf = true;
    }

    bool helper(string& word, Node* node, int i = 0) {
      for (; i < word.size(); ++i) {
        
        if (word[i] == '.') {
          for (int j = 0; j < 26; ++j) {
            if (node->children[j] && helper(word, node->children[j], i+1)) {
              return true;
            }
          }

          return false;
        } else {
          int c = word[i]-'a';

          if (!node->children[c]) {
            return false;
          }

          node = node->children[c];
        }
      }

      return node->isLeaf;
    }

    bool search(string word) {
      return helper(word, root);
    }
};

int main () {
  vector<pair<vector<string>, vector<string>>> testCases = {
    {
      {"addWord","addWord","addWord","search","search","search","search"},
      {"bad","dad","mad","pad","bad",".ad","b.."}
    }
  };

  for (auto& [commands, words] : testCases) {
    WordDictionary dict; 

    for (int i = 0; i < commands.size(); ++i) {
      cout << commands[i] << " ~ " << words[i] << ": ";

      if (commands[i] == "addWord") {
        dict.addWord(words[i]);
      } else if (commands[i] == "search") {
        cout << dict.search(words[i]) << endl;
      }

      cout << endl;
    }

    cout << "----" << endl;
  }

  return 0;
}