#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
  vector<vector<int>> matrix(m, vector<int>(n, 1));

  for (int i = 1; i < m; ++i)
    for (int j = 1; j < n; ++j)
      matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];

  return matrix[m-1][n-1];
}

int main(){
  vector<pair<int, int>> testCases = {
    {1, 1},
    {3, 7},
    {3, 2},
    {23, 12}
  };

  for (auto& [y, x] : testCases) {
    cout << uniquePaths(y, x) << endl;
  }

  return 0;
}
