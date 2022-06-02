#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& nums){
  int l = 0, r = nums.size()-1, ans = 0;

  while (l < r){
    int a = nums[l], b = nums[r];

    ans = max(ans, (r-l)*min(a, b));

    if (a < b){
      l++;
    } else {
      r--;
    }
  }

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {1,8,6,2,5,4,8,3,7},
  };

  for (auto& test : testCases)
    cout << maxArea(test) << endl;

  return 0;
}
