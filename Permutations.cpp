#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& permutation, int i){
  permutation.push_back(nums[i]);

  int ps = nums.size()-permutation.size(), tmp = nums[i];
  nums[i] = -11;

  if (ps){
    for (int j = 0; j < nums.size(); ++j)
      if (nums[j] != -11)
        dfs(ans, nums, permutation, j);
  } else {
    ans.push_back(permutation);
  }

  nums[i] = tmp;
  permutation.pop_back();
}

vector<vector<int>> permute(vector<int>& nums){
  vector<vector<int>> ans;
  vector<int> permutation; 

  for (int i = 0; i < nums.size(); ++i)
    dfs(ans, nums, permutation, i);

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {1,2,3},
    {0,1},
    {1}
  };

  for (auto& test : testCases){
    auto res = permute(test);

    cout << "amount found: " << res.size() << endl;

    for (auto& vec : res){
      for (auto& x : vec)
        cout << x << ", ";

      cout << endl;
    }

    cout << endl;
  }
    
  return 0;
}
