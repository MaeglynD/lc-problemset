#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points = {
  {0, 1}, {1, 0}, {-1, 0}, {0, -1}
};

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& mem, int prev, int i, int j){
  if (i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0 || prev >= matrix[i][j]) 
    return 0; 

  if (mem[i][j])
    return mem[i][j];
  
  for (auto& [py, px] : points)
    mem[i][j] = max(mem[i][j], 1+dfs(matrix, mem, matrix[i][j], i+py, j+px));

  return mem[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix){
  int y = matrix.size(), x = matrix[0].size(), ans = 0;
  vector<vector<int>> mem(y, vector<int>(x, 0));
  
  for (int i = 0; i < y; ++i)
    for (int j = 0; j < x; ++j)
      ans = max(ans, dfs(matrix, mem, -1, i, j));

  return ans;
}

int main(){
  vector<vector<vector<int>>> testCases = {
    {{9,9,4},{6,6,8},{2,1,1}},
    {{3,4,5},{3,2,6},{2,2,1}},
    {{1}}
  };

  for (auto& test : testCases){
    cout << longestIncreasingPath(test) << endl;
  }

  return 0;
}
