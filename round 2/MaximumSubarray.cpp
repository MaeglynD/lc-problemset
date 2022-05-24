#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums){
  int ans = INT_MIN, pre = 0;

  for (int& n : nums){
    if (pre < 0)
      pre = 0;

    pre+=n;
    ans = max(ans, pre);
  }
  
  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {-2,1,-3,4,-1,2,1,-5,4},
    {5,4,-1,7,8}
  };

  for (auto& test : testCases){
    cout << maxSubArray(test) << endl;
  }

  return 0;
}
