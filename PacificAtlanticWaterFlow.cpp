#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using matrix = vector<vector<int>>;

// 95.98%
void dfs(int y, int x, int& prev, bool isAtlantic, matrix& visited, matrix& heights, matrix& cells) {
  if (
    y >= 0 && y < heights.size() &&
    x >= 0 && x < heights[0].size() &&
    visited[y][x] < (isAtlantic ? 2 : 1) &&
    prev <= heights[y][x]
  ) {
    if (isAtlantic) {
      if (visited[y][x] == 1) {
        cells.push_back({ y, x });
      }

      visited[y][x] = 2;
    } else {
      visited[y][x] = 1;
    }


    dfs(y-1, x, heights[y][x], isAtlantic, visited, heights, cells);
    dfs(y+1, x, heights[y][x], isAtlantic, visited, heights, cells);
    dfs(y, x-1, heights[y][x], isAtlantic, visited, heights, cells);
    dfs(y, x+1, heights[y][x], isAtlantic, visited, heights, cells);
  }
}


matrix pacificAtlantic(matrix heights) {
  int x = heights[0].size();
  int y = heights.size();

  matrix cells;
  matrix visited(y, vector<int>(x, 0));
  
  // Pacific
  for (int i = 0; i < x; ++i) 
    dfs(0, i, heights[0][i], false, visited, heights, cells);

  for (int i = 0; i < y; ++i)
    dfs(i, 0, heights[i][0], false, visited, heights, cells);

  // Atlantic
  for (int i = 0; i < x; ++i) 
    dfs(y-1, i, heights[y-1][i], true, visited, heights, cells);
  for (int i = 0; i < y; ++i)
    dfs(i, x-1, heights[i][x-1], true, visited, heights, cells);

  return cells;
}


int main () {
  vector<matrix> testCases = {
    {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}},
    {{2,1},{1,2}}
  };

  for (matrix x : testCases) {
    matrix ans = pacificAtlantic(x);

    cout << "[";

    for (auto& x : ans) {
      cout << "{ " << x[0] << ", " << x[1] << " }";
    }

    cout << "]" << endl;
  }

  return 0;
}
