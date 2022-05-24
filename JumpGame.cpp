#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums){
  if (nums.size() == 1)
    return true;

  if (!nums[0])
    return false;

  int cur = 1;

  for (int i = nums.size()-2; i >= 0; --i)
    cur = nums[i] >= cur ? 1 : cur+1;

  return nums[0] >= cur;
}

int main(){
  vector<vector<int>> testCases = {
    {2,3,1,1,4},
    {3,2,1,0,4},
    {0,1}
  };

  for (auto& test : testCases){
    cout << canJump(test) << endl;
  }

  return 0;
}
