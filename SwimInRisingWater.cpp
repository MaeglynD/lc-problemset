#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int swimInWater(vector<vector<int>>& grid){
  int ans = grid.back().back();
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

  pq.push({grid[0][0], {0,0}});

  while(!pq.empty()){
    auto [w, yx] = pq.top();
    auto& [y, x] = yx;

    pq.pop();

    if (grid[y][x] == -1)
      continue;

    grid[y][x] = -1;

    if (y == grid.size()-1 && x == grid.size()-1){
      ans = max(ans, w);
      break;
    }

    for (auto [py, px] : points){
      py+=y; 
      px+=x; 

      if (py >= 0 && py < grid.size() && px >= 0 && px < grid[0].size() && grid[py][px] != -1)
        pq.push({max(w, grid[py][px]), {py, px}});
    }
  }

  return ans;
}

int main(){
  vector<vector<vector<int>>> testCases = {
    {{0,2},{1,3}},
    {{3,2},{0,1}},
    {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}}
  };

  for (auto& test : testCases)
    cout << swimInWater(test) << endl;

  return 0; 
}
