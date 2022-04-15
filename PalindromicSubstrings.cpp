#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countSubstrings(string s) {
  int n = s.size(), total = n;

  for (int i = 0; i < n; ++i) {
    int l = i-1, r = i+1;

    while (l >= 0 && r < n && s[l] == s[r]) {
      total++;
      l--;
      r++;
    }

    l = i-1, r = i;

    while (l >= 0 && r < n && s[l] == s[r]) {
      total++;
      l--;
      r++;
    }
  }

  return total;
}

int main () {
  vector<string> testCases = {
    "abc",
    "aaa",
    "aa"
  };

  for (auto& test : testCases) {
    cout << countSubstrings(test) << endl;
  }

  return 0;
}