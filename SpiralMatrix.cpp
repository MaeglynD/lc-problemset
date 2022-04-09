#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> spiralMatrix(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size(), mn = m*n;
	int pos = 0, r = 0, c = 0;

	vector<int> ans(mn);
	vector<pair<int, int>> positions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

	for (int i = 0; i < mn; ++i) {
		if (matrix[r][c] != INT_MAX) {
			auto& [y, x] = positions[pos];

			ans[i] = matrix[r][c];
			matrix[r][c] = INT_MAX;

      r+=y;
      c+=x;

      if (
          r < 0 || r >= m || 
          c < 0 || c >= n || 
          matrix[r][c] == INT_MAX
      ) {
        r-=y;
        c-=x;

        pos = (pos == 3 ? 0 : pos+1);

        r+= positions[pos].first;
        c+= positions[pos].second;
      }
    }
	}

	return ans;
}

int main () {
  vector<vector<int>> matrix = {
    {{1,2,3},{4,5,6},{7,8,9}}
  };

  for (auto& row : matrix) {
    for (auto& item : row) {
      cout << item << ", ";
    }
    cout << endl;
  }

  vector<int> ans = spiralMatrix(matrix);

  for (auto& n : ans) {
    cout << n << ", ";
  }

  return 0;
}
