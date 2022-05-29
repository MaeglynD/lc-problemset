#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<string>>& ans, vector<string>& board, int& n, bool* cols, bool* posDiag, bool* negDiag, int i, int qc){
  if (qc == 0){
    ans.push_back(board);
    return;
  }

  if (i == n)
    return;

  for (int j = 0; j < n; ++j){
    if (cols[j] || posDiag[i+j] || negDiag[n+(i-j)])
      continue;

    cols[j] = true;
    posDiag[i+j] = true;
    negDiag[n+(i-j)] = true;

    board[i][j] = 'Q';
    dfs(ans, board, n, cols, posDiag, negDiag, i+1, qc-1);
    board[i][j] = '.';

    cols[j] = false;
    posDiag[i+j] = false;
    negDiag[n+(i-j)] = false;
  } 
}

vector<vector<string>> solveNQueens(int n){
  bool cols[9] = {false}, posDiag[18] = {false}, negDiag[18] = {false};
  vector<string> board(n, string(n, '.')); 
  vector<vector<string>> ans;

  dfs(ans, board, n, cols, posDiag, negDiag, 0, n);

  return ans;
}

int main(){
  vector<int> testCases = {
    9, 
    1
  };

  for (auto& test : testCases){
    auto res = solveNQueens(test);
    
    for (auto& vec : res){
      for (auto& s : vec)
        cout << s << endl;

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}