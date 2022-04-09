#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1st solution
void rotateImage(vector<vector<int>>& matrix) {
  int n = matrix.size(), layer = n;	

  while(layer > 1) {
    int p = (n - layer)/2;
    vector<pair<int, int>> c = {{p,p}, {p,n-1-p}, {n-1-p, n-1-p}, {n-1-p,p}};
    vector<pair<int, int>> t = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    for (int i = 0; i < layer-1; ++i) {
      int tmp = matrix[c[3].first][c[3].second];

      for (int j = 3; j > 0; --j) {
        auto& [y1, x1] = c[j];
        auto& [y2, x2] = c[j-1];

        matrix[y1][x1] = matrix[y2][x2];
      }

      matrix[c[0].first][c[0].second] = tmp;

      for (int j = 0; j < t.size(); ++j) {
        auto& [ty, tx] = t[j];

        c[j].first+=ty;
        c[j].second+=tx;
      }
    }

    layer-=2;
  }
}

// 2nd solution
void rotateImage2(vector<vector<int>>& matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main () {
  vector<vector<int>> matrix = {
    {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
  };

  for (auto& row : matrix) {
    for (auto& item : row) {
      cout << item << ", ";
    }
    cout << endl;
  }

  rotateImage2(matrix);
  cout << endl;

  for (auto& row : matrix) {
    for (auto& item : row) {
      cout << item << ", ";
    }
    cout << endl;
  }

  return 0;
}
