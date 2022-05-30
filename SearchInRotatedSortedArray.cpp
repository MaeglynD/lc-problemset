#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target){
  int l = 0, r = nums.size()-1;

  while (l <= r){
    int mid = l+(r-l)/2;

    if (nums[mid] == target)
      return mid;

    if (nums[mid] >= nums[l]){
      if (nums[mid] < target || target < nums[l]){
        l = mid+1;
      } else {
        r = mid-1;
      }
    } else {
      if (target < nums[mid] || target > nums[r]){
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
  }

  return -1;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{4,5,6,7,0,1,2},0},
    {{4,5,6,7,0,1,2},3},
  };

  for (auto& [nums, target] : testCases){
    cout << search(nums, target) << endl;
  }

  return 0;
}