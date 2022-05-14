#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<bool>>& mem, string& a, string& b, string& s, int si, int ai, int bi){
  if (si == s.size())
    return true;

  if (mem[ai][bi])
    return false;

  mem[ai][bi] = true;

  if (ai <= a.size() && a[ai] == s[si])
    mem[ai][bi] = !dfs(mem, a, b, s, si+1, ai+1, bi);

  if (mem[ai][bi] && bi <= b.size() && b[bi] == s[si])
    mem[ai][bi] = !dfs(mem, a, b, s, si+1, ai, bi+1);

  return !mem[ai][bi];
}

bool isInterleave(string a, string b, string s){
  if (a.size()+b.size() != s.size())
    return false;

  vector<vector<bool>> mem(a.size()+1, vector<bool>(b.size()+1, false));

  return dfs(mem, a, b, s, 0, 0, 0);
}

int main(){
  vector<vector<string>> testCases = {
    {"aabcc", "dbbca", "aadbbcbcac"},
    {"aabcc", "dbbca", "aadbbbaccc"},
    {"", "", ""},
    {"aa", "ab","aaba"},
    {"aabc", "abad", "aabadabc"}
  };

  for (auto& test : testCases){
    cout << isInterleave(test[0], test[1], test[2]) << endl;
  }

  return 0;
}
