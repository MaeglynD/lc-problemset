#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k){
  if (!s.size())
    return 0;

  int mem[26] = {0};
  int l = 0, r = 0, maxFreq = 1, ans = 1;
  
  mem[s[0]-'A']++;

  while (r != s.size()){
    int ws = (r-l)+1;

    if (ws-k <= maxFreq){
      ans = max(ans, ws); 
      r++;

      if (r != s.size()) {
        mem[s[r]-'A']++;
        maxFreq = max(maxFreq, mem[s[r]-'A']);
      }
    } else {
      mem[s[l]-'A']--;
      l++;
    }
  }

  return ans;
}

int main(){
  vector<pair<string, int>> testCases = {
    {"ABAB", 2},
    {"AABABBA", 1}
  };

  for (auto& [s, k] : testCases)
    cout << characterReplacement(s, k) << endl;
  
  return 0;
}
