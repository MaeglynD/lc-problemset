#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b){
 int matrix[a.size()+1][b.size()+1];

 for (int i = a.size(); i >= 0; --i)
  for (int j = b.size(); j >= 0; --j)
    matrix[i][j] = i == a.size() || j == b.size()
      ? 0 : a[i] == b[j]
      ? matrix[i+1][j+1]+1 : max(matrix[i+1][j], matrix[i][j+1]);

  return matrix[0][0];
}

int main(){
  vector<pair<string, string>> testCases = {
    {"abcde", "ace"},
    {"abc", "abc"},
    {"abc", "def"}
  };

  for (auto& [a, b] : testCases){
    cout << longestCommonSubsequence(a, b) << endl;
  }
  
  return 0;
}
