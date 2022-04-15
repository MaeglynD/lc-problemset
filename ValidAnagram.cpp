#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// unicode
bool isAnagramUnicode(string s, string t) {
  unordered_map<char, int> mem;

  for (auto& c : s) {
    mem[c]++; 
  }

  for (auto& c : t) {
    if (!mem[c]) {
      return false;
    }

    mem[c]--;
  }

  return true;
}

// lowercase english characters
bool isAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  int ms[26] = {};

  for (char& c : t) {
    ms[c - 'a']++;
  }

  for (char& c : s) {
    if (!ms[c-'a']) {
      return false;
    }

    ms[c-'a']--;
  }

  return true;
}

int main () {
  vector<pair<string, string>> testCases = {
    {"anagram", "nagaram"},
    {"rat", "car"},
  };

  for (auto& [s, t] : testCases){
    cout << isAnagram(s, t) << endl;
  }

  return 0;
}