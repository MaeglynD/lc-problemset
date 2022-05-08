#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int helper(vector<int>& nums, bool alt) {
  int a = 0, b = 0;

  for (int i = alt; i < nums.size()-!alt; ++i) {
    int tmp = max(nums[i]+a, b);

    a = b;
    b = tmp;
  }

  return b;
}

int rob(vector<int>& nums) {
  if (nums.size() == 1) return nums[0];
  if (nums.size() == 2) return max(nums[0], nums[1]);

  return max(helper(nums, false), helper(nums, true));
}

int main () {
  vector<vector<int>> testCases = {
    {2,3,2},
    {1,2,3,1}
  };

  for (auto& test : testCases) {
    cout << rob(test) << endl;
  }

  return 0;
}