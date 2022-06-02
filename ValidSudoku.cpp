#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board){
  bool cols[9][9] = {{false}}, rows[9][9] = {{false}}, subBoard[9][9] = {{false}};

  for (int i = 0; i < 9; ++i){
    for (int j = 0; j < 9; ++j){
      if (board[i][j] != '.'){
        int n = board[i][j]-'1';

        if (rows[i][n] || cols[j][n] || subBoard[((i/3)*3)+j/3][n])
          return false;

        rows[i][n] = true;
        cols[j][n] = true;
        subBoard[((i/3)*3)+j/3][n] = true;
      }
    }
  } 

  return true;
}

int main(){
  vector<vector<vector<char>>> testCases = {
    {
      {'5','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','.','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'}
    }
  };

  for (auto& test : testCases)
    cout << isValidSudoku(test) << endl; 

  return 0;
}
