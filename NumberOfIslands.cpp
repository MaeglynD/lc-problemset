#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int row, int col, int& y, int& x, vector<vector<char>>& grid) {
  if (
    (row > -1 && row < y) &&
    (col > -1 && col < x) && 
    grid[row][col] == '1'
  ) {
    grid[row][col] = 'x';
    
    dfs(row+1, col, y, x, grid);
    dfs(row-1, col, y, x, grid);
    dfs(row, col+1, y, x, grid);
    dfs(row, col-1, y, x, grid);
  }
}

int numIslands(vector<vector<char>>& grid) {
  int total = 0;
  int y = grid.size();
  int x = grid[0].size();

  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) {
      if (grid[i][j] == '1') {
        total++;

        dfs(i, j, y, x, grid);
      }
    }
  }

  return total;
}

int main () {
  vector<vector<vector<char>>> testCases = {
    {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}},
    {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}}
  };

  for (auto& x : testCases) {
    cout << numIslands(x) << endl;
  }
  // 
  return 0;
}
