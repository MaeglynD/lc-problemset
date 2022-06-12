#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
  int l = 0, r = 0;
  int mxw = INT_MAX, curr = 0, ansl, ansr;
  int sMem[58] = {0}, tMem[58]= {0};
  
  for (char& c : t)
    tMem[c-'A']++;
  
  while (r != s.size()){
    while (r != s.size() && curr != t.size()){
      sMem[s[r]-'A']++;
      
      if (sMem[s[r]-'A'] <= tMem[s[r]-'A'])
        curr++;

      if (curr != t.size())
        r++;
    }

    if (r == s.size())
      break;

    while (sMem[s[l]-'A'] > tMem[s[l]-'A']){
      sMem[s[l]-'A']--;
      l++;
    }

    if (r-l < mxw){
      ansl = l;
      ansr = r;
      mxw = r-l;
      
      if (mxw+1 == t.size())
        break;
    }

    sMem[s[l]-'A']--;
    curr--;
    l++;
    r++;
  }

  return mxw == INT_MAX ? "" : s.substr(ansl, mxw+1);
}

int main(){
  vector<pair<string, string>> testCases = {
    {"ADOBECODEBANC", "ABC"},
    {"a", "a"},
    {"a", "aa"},
    {"ab", "a"},
    {"bba", "ab"}
  };

  for (auto& [s, t] : testCases)
    cout << minWindow(s, t) << endl;

  return 0;
}
