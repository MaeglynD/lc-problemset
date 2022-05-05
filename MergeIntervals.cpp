#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> merge(vector<vector<int>>& vals) {
  vector<vector<int>> ans;

  sort(vals.begin(), vals.end(), [](auto& a, auto& b){ 
    return a[0] < b[0];
  });

  ans.push_back(vals[0]);

  for (int i = 1; i < vals.size(); ++i) {
    auto& lastVal = ans.back();

    if (lastVal[1] >= vals[i][0]) {
      lastVal[1] = max(lastVal[1], vals[i][1]);
    } else {
      ans.push_back(vals[i]);
    }
  }
  
  return ans;
}

int main () {
  vector<vector<vector<int>>> testCases = {
    {{2,6},{1,3},{8,10},{15,18}},
    {{1,4},{4,5}},
    {{1,4},{2,3}}
  };

  for (auto& test : testCases) {
    auto res = merge(test);

    cout << "[";

    for (auto& x : res)
      cout << "[" << x[0] << ", " << x[1] << "], ";
    
    cout << "]" << endl;
  }

  return 0;
}