#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void setZeroes(vector<vector<int>>& matrix) {
	int y = matrix.size(), x = matrix[0].size(), tmp = 1;

	for (int r = 0; r < y; ++r) {
		for (int c = 0; c < x; ++c) {
			if (!matrix[r][c]) {
				if (c) {
					matrix[0][c] = 0;
				} else {
					tmp = 0;
				}

				matrix[r][0] = 0;
			}
		}
	}

  for (int i = 1; i < y; ++i) {
    for (int j = 1; j < x; ++j) {
      if (!matrix[i][0] || !matrix[0][j]) {
        matrix[i][j] = 0;
      }
    }
  }

  if (!matrix[0][0]) {
    fill(matrix[0].begin(), matrix[0].end(), 0);
  }

  if (!tmp) {
    for (int i = 0; i < y; ++i) {
      matrix[i][0] = 0;
    }
  }
}

int main () {
  vector<vector<int>> matrix = {
    {{1,1,1},{1,0,1},{1,1,1}}
  };

  setZeroes(matrix);

  for (auto& row : matrix) {
    for (auto& item : row) {
      cout << item << ", ";
    }
    cout << endl;
  }

  return 0;
}
