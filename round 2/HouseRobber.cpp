#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rob(vector<int>& nums) {
  if (nums.size() == 1)
    return nums[0];

  if (nums.size() > 2)
    nums[2] = max(nums[0]+nums[2], nums[1]);

  for (int i = 3; i < nums.size(); ++i)
    nums[i] = nums[i] + max(nums[i-2], nums[i-3]);

  return max(nums[nums.size()-1], nums[nums.size()-2]);
}

int main () {
  vector<vector<int>> testCases = {
    {1,2,3,1},
    {2,7,9,3,1}
  };

  for (auto& test : testCases) {
    cout << rob(test) << endl;
  }

  return 0;
}