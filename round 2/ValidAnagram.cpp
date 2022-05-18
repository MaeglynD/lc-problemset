#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
  if (s.size() != t.size())
    return false;

  int sm[26] = {0}, tm[26] = {0};
  
  for (int i = 0; i < s.size(); ++i){
    sm[s[i]-'a']++;
    tm[t[i]-'a']++;
  }

  for (int i = 0; i < 26; ++i)
    if (sm[i] != tm[i])
      return false;
   
  return true;
}

int main(){
  vector<pair<string, string>> testCases = {
    {"anagram", "nagaram"},
    {"rat", "car"}
  };

  for (auto& [s, t] : testCases){
    cout << isAnagram(s, t) << endl;
  }

  return 0;
}
