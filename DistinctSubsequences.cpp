#include <bits/stdc++.h>
using namespace std;

void logMatrix(vector<vector<int>>& mem, string& s, string& t){
  cout << " : [";

  for (auto& c : s)
    cout << c << ", ";

  cout << "]" << endl;

  for(int i = 0; i < mem.size(); ++i){
    cout << (t[i] ? t[i] : ' ') << ": [";

    for(auto x : mem[i])
      cout << x << ", ";

    cout << "]" << endl;
  }
}

int numDistinct(string s, string t){
  int y = t.size(), x = s.size();
  
  if (y > x) return 0;
  if (y == x) return t == s;

  vector<vector<unsigned int>> mem(y+1, vector<unsigned int>(x+1, 0));
  fill(mem[y].begin(), mem[y].end(), 1);

  for (int i = y-1; i >= 0; --i)
    for (int j = x-1; j >= 0; --j)
      mem[i][j] = t[i] == s[j]
        ? mem[i][j+1]+mem[i+1][j+1]
        : mem[i][j+1];

  return mem[0][0];
}

int main(){
  vector<pair<string, string>> testCases = {
    {"babgbag", "bag"},
    {"aaaaaaaaaa", "aaaaaaaaa"}
  };

  for (auto& [s, t] : testCases){
    cout << numDistinct(s, t) << endl;
  }

  return 0;
}
