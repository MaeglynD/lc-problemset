#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
  unordered_map<int, int> hm;

  for (int i = 0; i < nums.size(); ++i){
    if (hm.count(target-nums[i])) 
      return {i, hm[target-nums[i]]};

    hm[nums[i]] = i;
  }
    
  return {};
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{2,7,11,15}, 9},
    {{3,2,4}, 6},
    {{3,3}, 6}
  };

  for (auto& [nums, t] : testCases){ 
    auto res = twoSum(nums, t);

    cout << res[0] << " " << res[1] << endl;
  }

  return 0;
}
