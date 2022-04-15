#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalindrome(string s) {
  int l = 0, r = s.size()-1;

  while (l < r) {
    while (l < s.size() && !isalnum(s[l])) {
      l++;
    }

    while (r > 0 && !isalnum(s[r])) {
      r--;
    }

    if (l >= r) {
      return true;
    }

    if (tolower(s[r]) != tolower(s[l])) {
      return false;
    }

    l++;
    r--;
  }

  return true;
}

int main () {
  vector<string> testCases = {
    "A man, a plan, a canal: Panama",
    "race a car",
    " ",
    ".,"
  };

  for (auto& test : testCases) {
    cout << isPalindrome(test) << endl;
  }

  return 0;
}