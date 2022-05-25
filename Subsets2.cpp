#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset, int i){
  if (i == nums.size()){
    ans.push_back(subset);
    return;
  }

  subset.push_back(nums[i]);
  dfs(ans, nums, subset, i+1);

  while (i < nums.size() && nums[i] == subset.back())
    i++;

  subset.pop_back();
  dfs(ans, nums, subset, i);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
  vector<vector<int>> ans;
  vector<int> subset;

  sort(nums.begin(), nums.end());
  dfs(ans, nums, subset, 0);

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {1,2,2},
    {0},
  };

  for (auto& test : testCases){
    auto res = subsetsWithDup(test);

    cout << "found: " << res.size() << endl;
    
    for(auto& vec : res){
      for (auto& x : vec)
        cout << x << ", ";
      
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}