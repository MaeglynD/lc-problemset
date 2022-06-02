#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& nums, vector<vector<int>>& ans, int i){
  int l = i+1, r = nums.size()-1, target = -nums[i];

  while(l < r){
    int b = nums[l], c = nums[r];

    if (b+c == target){
      ans.push_back({ nums[i], b, c });

      r--;
      l++;

      while (l < r && nums[r] == nums[r+1])
        r--;
      while(l < r && nums[l] == nums[l-1])
        l++;
      
    } else if (b+c > target) {
      r--; 
    } else {
      l++;
    }
  }
}

vector<vector<int>> threeSum(vector<int>& nums){
  if (nums.size() < 3)
    return {};

  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  
  for (int i = 0; i < nums.size(); ++i){
    if (nums[i] > 0)
      break;

    if (i != 0 && nums[i] == nums[i-1])
      continue;

    twoSum(nums, ans, i);
  }

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {0,0,0},
    {-1,0,1,2,-1,-4},
    {},
    {0} 
  };

  for (auto& test : testCases){
    auto res = threeSum(test);

    for (auto& vec : res){
      for (auto& x : vec)
        cout << x << ", ";

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
