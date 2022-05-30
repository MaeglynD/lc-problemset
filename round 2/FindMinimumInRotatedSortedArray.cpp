#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums){
  int l = 0, r = nums.size()-1;

  while (l < r){
    if (nums[l] < nums[r])
      return nums[l];

    int mid = l+(r-l)/2;

    if (mid && nums[mid-1] > nums[mid])
      return nums[mid];

    if (nums[mid] >= nums[l]){
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  
  return nums[l];
}

int main(){
  vector<vector<int>> testCases = {
    {3,4,5,1,2},
    {4,5,6,7,0,1,2},
    {11,13,15,17},
    {2,1}
  };

  for (auto& test : testCases){
    cout << findMin(test) << endl;
  }

  return 0;
}