#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
  int l = 0, r = nums.size()-1;

  while (l < r){
    int n = nums[l]+nums[r];

    if (n == target)
      return { l+1, r+1 };
    
    if (n > target){
      r--; 
    } else {
      l++;
    }
  }

  return {};
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{2,7,11,15},9},
    {{2,3,4},6},
    {{-1,0},-1}
  };

  for (auto& [nums, target] : testCases){
    auto res = twoSum(nums, target);

    cout << res[0] << " " << res[1] << endl;
  }

  return 0;
}
