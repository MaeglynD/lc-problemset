#include <bits/stdc++.h>
using namespace std;

bool dfs(string& s, string& p, int si, int pi, bool mem[][30]){
  if (pi == -1 && si == -1)
    return true;

  if (pi < 0) 
    return false;

  if (si < 0){
    while(pi >= 0 && p[pi] == '*')
      pi-=2;

    return pi == -1;
  }

  if (mem[si][pi])
    return false;

  mem[si][pi] = true;

  if (p[pi] == '*'){
    int tmp = si;

    while(tmp >= 0 && (p[pi-1] == '.' || s[tmp] == p[pi-1]) && mem[si][pi]){
      mem[si][pi] = !dfs(s, p, tmp, pi-1, mem);
      tmp--;
    }
    
    if (mem[si][pi]) 
      mem[si][pi] = !dfs(s, p, si, pi-2, mem);
  } else if (p[pi] == '.' || p[pi] == s[si]){
    mem[si][pi] = !dfs(s, p, si-1, pi-1, mem);
  }

  return !mem[si][pi];
}
 
bool isMatch(string s, string p){
  bool mem[30][30] = {{false}};

  return dfs(s, p, s.size()-1, p.size()-1, mem);
}

int main(){
  vector<pair<string, string>> testCases = {
    {"aaabc", "a*aa.*bc"},
    {"aab","c*a*b"}, 
    {"aa", "a"}, 
    {"aa", "a*"},
    {"ab", ".*"},
    {"aaa", "ab*a"}, 
    {"aaa","ab*ac*a"}
  };

  for(auto& [s, p] : testCases){
    cout << isMatch(s, p) << endl;
  }

  return 0;
}
