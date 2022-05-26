#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& recStack, int& target, int i, int acc){
  acc+=nums[i];
  recStack.push_back(nums[i]);

  if (acc == target){
    ans.push_back(recStack);
  } else {
    for (int j = i+1; j < nums.size(); ++j){
      if (nums[j]+acc > target) 
        break;

      if (j != i+1 && nums[j] == nums[j-1])
        continue;

      dfs(ans, nums, recStack, target, j, acc);
    }
  }

  recStack.pop_back();
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target){
  vector<vector<int>> ans;
  vector<int> recStack;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); ++i){
    if (nums[i] > target)
      break;
    
    if (i != 0 && nums[i] == nums[i-1])
      continue;

    dfs(ans, nums, recStack, target, i, 0);
  }

  return ans;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{10,1,2,7,6,1,5}, 8},
    {{2,5,2,1,2}, 5}
  };
  
  for (auto& [nums, target] : testCases){
    auto res = combinationSum2(nums, target);

    cout << "found: " << res.size() << endl;

    for (auto& vec : res){
      for (auto& x : vec)
        cout << x << ", ";

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}