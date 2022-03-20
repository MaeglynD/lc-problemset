#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(int& row, int& col, int& y, int& x, vector<vector<char>>& grid) {
  queue<pair<int, int>> q;

  grid[row][col] = 'x';
  q.push({ row, col });

  while (!q.empty()) {
    const auto& [r, c] = q.front();

    pair<int, int> coords[4] = {
      {r-1, c}, {r+1, c}, {r, c-1}, {r, c+1}
    };

    q.pop();

    for (auto& [cy, cx] : coords) {
      if (
        cy > -1 && cy < y &&
        cx > -1 && cx < x && 
        grid[cy][cx] == '1'
      ) {
        grid[cy][cx] = 'x';
        q.push({ cy, cx });
      }
    }
  }
}

int numIslands(vector<vector<char>>& grid) {
  int total = 0;
  int x = grid[0].size();
  int y = grid.size();

  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) {
      if (grid[i][j] == '1') {
        total++;

        bfs(i, j, y, x, grid);
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
  
  return 0;
}
