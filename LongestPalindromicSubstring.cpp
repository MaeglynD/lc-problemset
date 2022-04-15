#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string longestPalindrome(string s) {
  int ansr = 0, ansl = 0;

  for (int i = 0; i < s.size(); ++i) {
    int j = 1;

    while (i+j < s.size() && i-j >= 0 && s[i+j] == s[i-j]) {
      if (ansr-ansl <= (i+j)-(i-j)) {
        ansr = i+j;
        ansl = i-j;
      }

      j++;
    }

    j = 1;

    while (i+j-1 < s.size() && i-j >= 0 && s[i+j-1] == s[i-j]) {
      if (ansr-ansl <= (i+j-1)-(i-j)) {
        ansr = i+j-1;
        ansl = i-j;
      }

      j++;
    }
  }

  return s.substr(ansl, (ansr-ansl)+1);
}

int main () {
  vector<string> testCases = {
    "babad",
    "cbbd",
    "",
    "aaaa",
    "aacabdkacaa",
    "aaaabaaa"
  };

  for (auto& test : testCases) {
    cout << longestPalindrome(test) << endl;
  }

  return 0;
}