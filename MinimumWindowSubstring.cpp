#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string minWindow(string s, string t) {
  int m = s.size(), n = t.size();

  if (n > m || t == "") {
    return "";
  }

  int lptr = 0, rptr = 0, ansr = m, ansl = 0, charCount = n;
  unordered_map<char, int> mt, ms;

  for (auto& c : t) {
    mt[c]++;
    ms[c] = 0;
  }

  while (rptr < m) {
    if (ms.count(s[rptr])) {
      if (ms[s[rptr]] < mt[s[rptr]]) {
        charCount--;
      }

      ms[s[rptr]]++;
    }
    
    if (!charCount) {
      while (!charCount) {
        if (ms.count(s[lptr])) {
          if (ms[s[lptr]] <= mt[s[lptr]]) {
            charCount++;
          }

          ms[s[lptr]]--;
        }

        lptr++; 
      }

      if (ansr - ansl > rptr - (lptr-1)) {
        ansr = rptr;
        ansl = lptr-1;
      }
    }

    rptr++;
  }

  return ansr == m ? "" : s.substr(ansl, (ansr - ansl)+1);
}

int main () {
  vector<pair<string, string>> testCases = {
    {"ADOBECODEBANC", "ABC"},
    {"a", "a"},
    {"a", "aa"},
    {"ab", "a"},
    {"abc", "ab"},
    {"cabwefgewcwaefgcf", "cae"}
  };

  for (auto& [s, t] : testCases) {
    cout << minWindow(s, t) << endl;
  }

  return 0;
}