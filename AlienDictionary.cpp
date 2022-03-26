#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using adjMap = unordered_map<char, pair<bool, unordered_set<char>>>;

bool dfs(const char& letter, unordered_map<char, bool>& path, adjMap& graph, string& ans) {
  auto& [visited, adjNodes] = graph[letter];

  visited = true;
  path[letter] = true;

  for (auto& n : adjNodes) {
    if (path[n] || (!graph[n].first && !dfs(n, path, graph, ans))) {
      return false;
    }
  }
  
  path[letter] = false;
  ans += letter;

  return true;
}

string alienOrder(vector<string>& words) {
  string ans;
  adjMap graph;
  unordered_map<char, bool> path;

  for (int i = 0; i < words.size(); ++i) {
    for (auto& ch : words[i]) {
      if (!graph.count(ch)) {
        graph.insert({ ch, { false, {} }});
      }
    }
  }

  for (int i = 1; i < words.size(); ++i) {
    for (int j = 0; j < min(words[i].size(), words[i-1].size()); ++j) {
      if (words[i][j] != words[i-1][j]) {
        graph[words[i][j]].second.insert(words[i-1][j]);
        break;
      }
    } 
  }

  for (auto& [letter, data] : graph) {
    if (!data.first && !dfs(letter, path, graph, ans)) {
      return "";
    }
  }

  return ans;
}

int main () {
  vector<vector<string>> testCases = {
    {"baa","abcd","abca","cab","cad"},
    {"wrt", "wrf", "er", "ett", "rftt"},
    {"caa","aaa","aab"}
  };

  for (auto& test : testCases) {
    cout << alienOrder(test) << endl;
  }

	return 0;
}
