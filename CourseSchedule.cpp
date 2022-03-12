#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(int v, vector<int> *adj, bool *visited, bool *path) {
  visited[v] = true;
  path[v] = true;

  for (int& n : adj[v]) {
    if (path[n] || (!visited[n] && dfs(n, adj, visited, path))){
      return true;
    }
  }

  path[v] = false;

  return false;
}

bool canFinish(int n, vector<vector<int>> prerequisites) {
  vector<int> adj[n];
  bool visited[n];
  bool path[n];

  fill(visited, visited + n, false);
  fill(path, path+n, false);

  for (auto& p : prerequisites) {
    adj[p[1]].push_back(p[0]);
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i] && dfs(i, adj, visited, path)) {
      return false;
    }
  }

  return true;
}

int main () {
  // 
  return 0;
}
