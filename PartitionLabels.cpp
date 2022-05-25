#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
  int l = 0, r = 0;
  unordered_map<int, pair<int, int>> hm; 
  vector<int> order, ans;

  for (int i = 0; i < s.size(); ++i){
    if (hm.count(s[i]-'a')){
      hm[s[i]-'a'].second = i;
    } else {
      order.push_back(s[i]-'a');
      hm[s[i]-'a'] = {i, i};
    }
  }

  for (int& i : order){
    auto& [lb, rb] = hm[i];

    if (lb > r){
      ans.push_back((r-l)+1);

      l = lb;
      r = rb;
    } else {
      r = max(r, rb);
    }
  }
  
  ans.push_back((r-l)+1);
  
  return ans;
}

int main(){
  vector<string> testCases = {
    "ababcbacadefegdehijhklij"
  };

  for (auto& test : testCases){
    auto res = partitionLabels(test);

    for (auto& x : res)
      cout << x << ", ";
    
    cout << endl;
  }

  return 0;
}