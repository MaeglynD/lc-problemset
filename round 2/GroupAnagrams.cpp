#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
  vector<vector<string>> ans;
  vector<string> sorted = strs;
  unordered_map<string, int> hm;

  for (string& s : sorted)
    sort(s.begin(), s.end());

  for (int i = 0; i < sorted.size(); ++i){
    if (hm.count(sorted[i])) {
      ans[hm[sorted[i]]].push_back(strs[i]);
    } else {
      ans.push_back({ strs[i] });
      hm[sorted[i]] = ans.size()-1;
    }
  }
  
  return ans;
}

int main(){
  vector<vector<string>> testCases = {
    {"eat","tea","tan","ate","nat","bat"}
  };

  for (auto& test : testCases){
    auto res = groupAnagrams(test);

    cout << "[";

    for (auto& vec : res){
      cout << "[";
      
      for (auto& x : vec)
        cout << x << ", ";

      cout << "], ";
    }

    cout << "]" << endl;
  }

  return 0;
}
