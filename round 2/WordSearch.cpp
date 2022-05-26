#include <bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<char>>& board, string& word, int pos, int i, int j){
  if (pos == word.size())
    return true;

  if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[pos])
    return false;
  
  board[i][j] = '*';
  pos++;

  bool ans = dfs(board, word, pos, i+1, j) ||
    dfs(board, word, pos, i-1, j) ||
    dfs(board, word, pos, i, j+1) ||
    dfs(board, word, pos, i, j-1);
  
  board[i][j] = word[pos]; 

  return ans;
}

bool exist(vector<vector<char>>& board, string word){
  for (int i = 0; i < board.size(); ++i)
    for (int j = 0; j < board[0].size(); ++j)
      if(dfs(board, word, 0, i, j))
        return true;
  
  return false;
}

int main(){
  vector<pair<vector<vector<char>>, string>> testCases = {
    {{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED"},
    {{{'A','B','C','E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB"}
  };

  for (auto& [board, word] : testCases)
    cout << exist(board, word) << endl;

  return 0;
}