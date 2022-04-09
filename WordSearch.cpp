#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(vector<vector<char>>& board, string& word, int depth, int y, int x) {
	if (depth == word.size()) {
		return true;
	}

  if (
    y < 0 || y >= board.size() || 
    x < 0 || x >= board[0].size() ||
    word[depth] != board[y][x] || 
    board[y][x] == '*'
  ) {
    return false;
  }

	board[y][x] = '*';

  bool ans = dfs(board, word, depth+1, y+1, x) ||
    dfs(board, word, depth+1, y-1, x) ||
    dfs(board, word, depth+1, y, x-1) ||
    dfs(board, word, depth+1, y, x+1);

	board[y][x] = word[depth];

	return ans; 
}

bool exist(vector<vector<char>>& board, string word) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (dfs(board, word, 0, i, j)) {
				return true;
			}
		}
	}

	return false;
}


int main () {
  vector<vector<char>> matrix = {
    {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}
  };

  for (auto& row : matrix) {
    for (auto& item : row) {
      cout << item << ", ";
    }
    cout << endl;
  }

  cout << exist(matrix, "ABCCED");

  return 0;
}
