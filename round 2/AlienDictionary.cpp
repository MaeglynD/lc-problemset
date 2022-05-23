#include <bits/stdc++.h>
using namespace std;

bool dfs(stack<int>& st, bool (&graph)[26][26], bool* visited, bool* path, int i){
  if (path[i])
    return false; 

  if (visited[i])
    return true;

  path[i] = true;
  visited[i] = true;

  for (int j = 25; j >= 0; --j)
    if (i != j && graph[i][j])
      if (!dfs(st, graph, visited, path, j))
        return false;

  if (graph[i][i])
    st.push(i);
  
  path[i] = false;

  return true;
}

string alienOrder(vector<string>& words){
  string ans = "";
  stack<int> st;
  bool graph[26][26] = {{false}}, visited[26] = {false}, path[26] = {false};

  for (string& w : words){
    for (char& c : w){
      graph[c-'a'][c-'a'] = true;
    }
  }

  for (int i = 1; i < words.size(); ++i){
    string& a = words[i-1], &b = words[i];
    int j = 0, lim = min(a.size(), b.size());

    while(j < lim && a[j] == b[j])
      j++;
    
    if (j == lim){
      if (a.size() >= b.size())
        return "";

      continue;
    }

    graph[a[j]-'a'][b[j]-'a'] = true;
  }

  for (int i = 25; i >= 0; --i){
    if (!graph[i][i] || visited[i])
      continue;
    
    if (!dfs(st, graph, visited, path, i))
      return "";
  }

  while(!st.empty()){
    ans.push_back(st.top()+'a');
    st.pop();
  }

  return ans;
}

int main(){
  vector<vector<string>> testCases = {
    {"wrt","wrf","er","ett","rftt"},
    {"z", "x"},
    {"zy", "zx"},
    {"ab", "adc"},
    {"abc","bcd","qwert","ab"},
    {"ab", "abc"}
  };

  for (auto& test : testCases)
    cout << alienOrder(test) << endl;

  return 0;
}
