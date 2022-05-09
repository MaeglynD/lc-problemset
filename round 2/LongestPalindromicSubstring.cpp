#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string longestPalindrome(string s) {
  int l = 0, r = 0, mid = s.size()/2;

  for (int i = 0; i < s.size(); ++i) {
    if((s.size()-abs(mid - i)) <= r-l) {
      break;
    }

    int lptr = i-1, rptr = i+1;

    while(lptr >= 0 && rptr < s.size() && s[lptr] == s[rptr]){
      if (r-l < rptr-lptr) {
        r = rptr;
        l = lptr;
      }

      lptr--;
      rptr++;
    }

    lptr = i;
    rptr = i+1;

    while(lptr >= 0 && rptr < s.size() && s[lptr] == s[rptr]) {
      if (r-l < rptr-lptr) {
        r = rptr;
        l = lptr;
      }

      lptr--;
      rptr++;
    }
  }

  return s.substr(l, r-l+1);
}

int main () {
  vector<string> testCases = {
    "babad",
    "cbbd"
  };

  for (auto& test : testCases) {
    cout << longestPalindrome(test) << endl;
  }

  return 0;
}