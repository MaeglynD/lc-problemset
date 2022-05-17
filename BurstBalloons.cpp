#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& nums, vector<vector<int>>& mem, int l, int r){
  if (l > r)  
    return 0;
  if (mem[l][r] != -1)
    return mem[l][r];

  mem[l][r] = 0;

  for (int i = l; i < r+1; ++i){
    mem[l][r] = max(mem[l][r], (nums[i]*nums[l-1]*nums[r+1]) + dfs(nums, mem, l, i-1) + dfs(nums, mem, i+1, r));
  }

  return mem[l][r];
}

int maxCoins(vector<int>& nums){
  nums.insert(nums.begin(), 1);
  nums.push_back(1);

  vector<vector<int>> mem(nums.size()+2, vector<int>(nums.size()+2, -1));
  
  return dfs(nums, mem, 1, nums.size()-2);
}

int main(){
  vector<vector<int>> testCases = {
    {3, 1, 5, 8},
    {1, 5}
  }; 

  for (auto& test : testCases){
    cout << maxCoins(test) << endl;
  }

  return 0;
}



