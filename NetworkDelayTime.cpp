#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k){
  int ans = -1;
  vector<int> nodes(n+1, INT_MAX);
  vector<bool> visited(n+1);
  unordered_map<int, vector<int>> hm;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for (int i = 0; i < times.size(); ++i)
    hm[times[i][0]].push_back(i);

  pq.push({0, k});

  while(!pq.empty()){
    auto [w, index] = pq.top();

    pq.pop();

    if (visited[index])
      continue;

    visited[index] = true;
    n--;

    if (!n){
      ans = w; 
      break;
    }
    
    if (hm.count(index)){
      for(int& i : hm[index]){
        if (!visited[times[i][1]]) {
          nodes[times[i][1]] = min(nodes[times[i][1]], w+times[i][2]);
          pq.push({nodes[times[i][1]], times[i][1]});
        }
      }
    }    
  }
  
  return ans; 
}

int main(){
  vector<pair<vector<vector<int>>, pair<int, int>>> testCases = {
    {{{2,1,1,},{2,3,1},{3,4,1}}, {4, 2}},
    {{{1,2,1,},{2,3,2},{1,3,2}}, {3, 1}},
    {{{1,2,1}},{2, 1}},
    {{{1,2,1}},{2, 2}},
  };

  for (auto& [times, nk] : testCases)
    cout << networkDelayTime(times, nk.first, nk.second) << endl;

  return 0;
}
