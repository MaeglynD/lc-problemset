#include <bits/stdc++.h>
using namespace std;

const string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wyxz"};

void dfs(vector<string>& ans, string& digits, string& curr, int i){
  if (i == digits.size()){
    ans.push_back(curr);
    return;
  }

  for (const char& c : mapping[digits[i]-'0']){
    curr.push_back(c);
    dfs(ans, digits, curr, i+1);
    curr.pop_back();
  }
}

vector<string> letterCombinations(string digits){
  if (!digits.size())
    return {};

  vector<string> ans;
  string curr = "";

  dfs(ans, digits, curr, 0);

  return ans;
}

int main(){
  vector<string> testCases = {
    "23",
    "",
    "2",
  };

  for (auto& test : testCases){
    auto res = letterCombinations(test);

    cout << "for " << test << endl;

    for (auto& x : res)
      cout << x << ", ";

    cout << endl;
  }

  return 0;
}