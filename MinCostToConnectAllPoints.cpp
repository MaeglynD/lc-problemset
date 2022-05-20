#include <bits/stdc++.h>
using namespace std;
// amount to get from point a -> b, index of a, index of b
typedef pair<int, pair<int, int>> node;

int minCostConnectPoints(vector<vector<int>>& points){
  int ans = 0, n = points.size();
  vector<bool> visited(n);
  
  priority_queue<node, vector<node>, greater<node>> pq;
  
  pq.push({ 0, {0, 0}});

  while(!pq.empty() && n){
    auto [w, ft] = pq.top();
    auto& [from, to] = ft;

    pq.pop();

    if (visited[to])
      continue;
    
    visited[to] = true;
    ans+=w;
    n--;


    int bx = points[to][0], by = points[to][1];

    for (int i = 0; i < points.size(); ++i){
      if (visited[i])
        continue;

      int ax = points[i][0], ay = points[i][1];

      pq.push({abs(ax-bx)+abs(ay-by), {to, i}});
    }
  }

  return ans;
}

int main(){
  vector<vector<vector<int>>> testCases = {
    {{0,0},{2,2},{3,10},{5,2},{7,0}},
    {{3,12},{-2,5},{-4,1}}
  };

  for (auto& test : testCases){
    cout << minCostConnectPoints(test) << endl;
  }

  return 0;
}
