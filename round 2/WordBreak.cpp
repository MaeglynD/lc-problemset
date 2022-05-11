#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

bool wordBreak(string s, vector<string>& dict){
  bool mem[s.size()+1];
  
  mem[s.size()] = true;

  for (int i = s.size()-1; i >= 0; --i) {
    mem[i] = false;

    for (string& word : dict) {
      if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
        mem[i] = mem[i+word.size()];

        if (mem[i])
          break;
      }
    }
  }

  return mem[0];
}

// failed trie attempt
class TrieNode {
  public:
    TrieNode* children[26] = {NULL};
    bool eow = false;
};

bool helper(string& s, TrieNode* root, int i) {
  TrieNode* tmp = root;	

  for (; i < s.size(); ++i) {
    if (tmp->eow && helper(s, root, i))
      return true;

    if (!tmp->children[s[i]-'a'])
      return false;
    
    tmp = tmp->children[s[i]-'a'];
  }

  return tmp->eow;
}

bool wordBreakAlt(string s, vector<string>& dict){
  TrieNode* root = new TrieNode();	

  for (string& word : dict) {
    TrieNode* tmp = root;

    for (char& c : word) {
      if (!tmp->children[c-'a'])
        tmp->children[c-'a'] = new TrieNode();

      tmp = tmp->children[c-'a'];
    }

    tmp->eow = true;
  }

  return helper(s, root, 0);
}

int main(){
  vector<pair<vector<string>, string>> testCases = {
    {{"leet", "code"}, "leetcode"},
    {{"apple", "pen"}, "applepenapple"}
  };

  for (auto& [dict, s] : testCases) {
    cout << wordBreak(s, dict) << endl;
  }

  return 0;
}