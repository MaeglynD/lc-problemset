#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& nums){
  int l = 0, r = nums.size()-1;
  int ans = 0, ml = 0, mr = 0;

  while (l < r){
    if (nums[l] < nums[r]){
      ml = max(ml, nums[l]);
      l++;
      ans += max(0, ml-nums[l]);
    } else {
      mr = max(mr, nums[r]); 
      r--;
      ans += max(0, mr-nums[r]);
    }
  }
  
  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {0,1,0,2,1,0,1,3,2,1,2,1}
  };

  for (auto& test : testCases)
    cout << trap(test) << endl;

  return 0;
}
