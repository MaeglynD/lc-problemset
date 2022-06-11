#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2){
  int l = 0, r = 0;
  int memS1[26] = {0}, memS2[26] = {0};

  for (char& c : s1){
    memS1[c-'a']++;
    memS2[c-'a']++;
  }
  
  while (r != s2.size()){
    if (memS1[s2[r]-'a']) {
      if (memS2[s2[r]-'a']){
        if ((r-l)+1 == s1.size())
          return true;

        memS2[s2[r]-'a']--; 
      } else {
        while (s2[l] != s2[r]){
          memS2[s2[l]-'a']++;
          l++;
        }
        l++;
      }

      r++;
    } else {
      copy(begin(memS1), end(memS1), begin(memS2));

      l = r+1; 
      r = l;
    }
  }
  
  return false;
}

int main(){
  vector<pair<string, string>> testCases = {
    {"ab", "eidbaooo"},
    {"ab", "eidboaoo"},
    {"adc", "dcda"},
    {"ky", "ainwkckifykxlribaypk"}
  };

  for (auto& [s1, s2] : testCases)
    cout << checkInclusion(s1, s2) << endl;
  
  return 0;
}
