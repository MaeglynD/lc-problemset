#include <bits/stdc++.h>
using namespace std;

void dfs(string& s, vector<vector<string>>& palindromes, vector<vector<string>>& ans, vector<string>& recStack, int i){
  if (i == s.size()){
    ans.push_back(recStack);
    return;
  }

  for (int j = 0; j < palindromes[i].size(); ++j){
    recStack.push_back(palindromes[i][j]);
    dfs(s, palindromes, ans, recStack, i+palindromes[i][j].size());
    recStack.pop_back();
  }
}

vector<vector<string>> partition(string s){
  vector<vector<string>> palindromes(s.size());
  vector<vector<string>> ans;
  vector<string> recStack;

  for (int i = 0; i < s.size(); ++i){
    int l = i, r = i;    

    while (l > -1 && r < s.size() && s[l] == s[r]){
      palindromes[l].push_back(s.substr(l, (r-l)+1));

      l--;
      r++;
    }

    l = i-1, r = i;

    while(l > -1 && r < s.size() && s[l] == s[r]){
      palindromes[l].push_back(s.substr(l, (r-l)+1));

      l--;
      r++;
    }
  }

  dfs(s, palindromes, ans, recStack, 0);

  return ans;
}

int main(){
  vector<string> testCases = {
    "aabaa",
    "aab",
    "a"
  }; 

  for (auto& test : testCases){
    auto partitions = partition(test);

    cout << "partitions for " << test << ": " << endl;

    for (auto& p : partitions){
      for (auto& s : p)
        cout << s << ", ";

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}