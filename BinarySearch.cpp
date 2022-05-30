#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int t){
  int l = 0, r = nums.size()-1;

  while (l < r){
    int i = l+((r-l)/2), mid = nums[i];

    if (mid == t){
      return i;
    } else if (mid > t) {
      r = i-1;
    } else {
      l = i+1;
    }
  }

  return nums[l] == t ? l : -1;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{-1,0,3,5,9,12}, 9},
    {{-1,0,3,5,9,12}, 2},
  };

  for (auto& [nums, t] : testCases){
    cout << search(nums, t) << endl;
  }

  return 0;
}