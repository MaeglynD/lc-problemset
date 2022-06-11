#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
  if (!s.size()) 
    return 0;

  int l = 0, r = 1, ans = 1;
  bool mem[256] = {false};
  
  mem[s[0]] = true;

  while (r != s.size()){
    if (mem[s[r]]){
      ans = max(ans, r-l);

      while (s[l] != s[r]){
        mem[s[l]] = false;
        l++;
      }

      l++;
    }

    mem[s[r]] = true;
    r++;
  }
  
  return max(ans, r-l); 
}

int main(){
  vector<string> testCases = {
    "abcabcbb",
    "bbbbb",
    "pwwkew",
    "au",
    " ",
    "dvdf"
  };

  for (auto& test : testCases)
    cout << lengthOfLongestSubstring(test) << endl;

  return 0;
}
