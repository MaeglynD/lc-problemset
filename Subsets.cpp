#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset, int& i){
  if (i == nums.size()){
    ans.push_back(subset);
    return;
  }

  subset.push_back(nums[i]);
  i++;
  dfs(ans, nums, subset, i);

  subset.pop_back();
  dfs(ans, nums, subset, i);
  i--;
}

vector<vector<int>> subsets(vector<int>& nums){
  vector<vector<int>> ans;
  vector<int> subset;
  int i = 0;

  dfs(ans, nums, subset, i);

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {1,2,3},
  };

  for (auto& test : testCases){
    auto res = subsets(test);

    for (auto& vec : res){
      for (auto& x : vec)
        cout << x << ", ";

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}