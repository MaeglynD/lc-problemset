#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countSubstrings(string s) {
  int count = s.size();

  for (int i = 0; i < s.size(); ++i) {
    int l = i-1, r = i+1;

    while(l >= 0 && r < s.size() && s[l] == s[r]) {
      count++;
      l--;
      r++;
    }
    
    l = i;
    r = i+1;

    while(l >= 0 && r < s.size() && s[l] == s[r]) {
      count++;
      l--;
      r++;
    }
  }

  return count;
}

int main () {
  vector<string> testCases = {
    "abc",
    "aaa",
    "babad",
    "cbbd"
  };

  for (auto& test : testCases) {
    cout << countSubstrings(test) << endl;
  }

  return 0;
}