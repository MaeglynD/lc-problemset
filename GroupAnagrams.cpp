#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> ans;
  unordered_map<string, int> mem;

  for (string& str : strs) {
    string s = str;

    sort(s.begin(), s.end());

    if (mem.count(s)) {
      ans[mem[s]].push_back(str);
    } else {
      ans.push_back({ str });
      mem[s] = ans.size()-1;
    }
  }

  return ans;
}

int main () {
  vector<vector<string>> testCases = {
    {"eat","tea","tan","ate","nat","bat"},
    {""},
    {"a"}
  };

  for (auto& test : testCases) {
    auto res = groupAnagrams(test);

    cout << "[";

    for (auto& v : res) {
      cout << "[";

      for (auto& s : v) {
        cout << s << ", ";
      }

      cout << "], ";
    }

    cout << "]" << endl;
  }

  return 0;
}