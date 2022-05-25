#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& recStack, vector<int>& nums, int& target, int i, int acc){
  acc+=nums[i];
  recStack.push_back(nums[i]);

  if (target == acc){
    ans.push_back(recStack);
  } else {
    for (int j = i; j < nums.size(); ++j){
      if (nums[j]+acc > target)
        break;

      dfs(ans, recStack, nums, target, j, acc);
    }
  }

  recStack.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& nums, int target){
  vector<vector<int>> ans;
  vector<int> recStack;
  int acc = 0;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); ++i)
    dfs(ans, recStack, nums, target, i, acc);
  
  return ans;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{2,3,6,7}, 7},
    {{2,3,5}, 8},
    {{2}, 1},
  };

  for (auto& [nums, target] : testCases){
    auto res = combinationSum(nums, target);

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