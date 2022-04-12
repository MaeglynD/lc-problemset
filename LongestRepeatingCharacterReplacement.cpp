#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int characterReplacement(string s, int k) {
  int l = 0, r = 0, maxFreq = 0, ans = 0;
  int alphabet[26] = {0};

  while (r < s.size()) {
    alphabet[s[r]-'A']++;
    maxFreq = max(maxFreq, alphabet[s[r]-'A']);

    if ((r-l)+1-maxFreq > k) {
      alphabet[s[l]-'A']--;
      l++;
    }

    ans = max(ans, (r-l)+1);
    r++;
  }

  return ans;
}

int main () {
  vector<pair<string, int>> testCases = {
    { "ABAB", 2 },
    { "AABABBA", 1 }
  };

  for (auto& [s, k] : testCases) {
    cout << characterReplacement(s, k) << endl;
  }

  return 0;
}
