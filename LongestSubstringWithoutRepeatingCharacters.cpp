#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lengthOfLongestSubstring(string s) {
  int lptr = 0, ans = 0;	
  unordered_map<char, int> mem;

  for (int i = 0; i < s.size(); ++i) {
    if (mem.count(s[i]) && mem[s[i]] >= lptr) {
      lptr = mem[s[i]]+1;
    } else {
      ans = max(ans, (i-lptr)+1);
    }

    mem[s[i]] = i;
  }

  return ans;
}

int main () {
  vector<string> testCases = {
    "abba",
    "tmmzuxt",
    "abcabcbb",
    "bbbbb",
    "pwwkew",
    "au"
  };

  for (auto& test : testCases) {
    cout << lengthOfLongestSubstring(test) << endl;
  }

  return 0;
}
