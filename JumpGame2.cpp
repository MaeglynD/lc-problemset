#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums){
  if (nums.size() == 1)
    return 0;

  int l = 0, r = 0, lt = 1, rt = 1, ans = 0; 
  
  for (int i = 0; i < nums.size()-1; ++i){
    rt = max(rt, i+nums[i]);

    if (rt >= nums.size()-1)
      return ans+1;

    if (i == r){
      l = lt;
      r = rt;
      lt = rt+1;
      rt = lt;
      ans++;
    }
  }

  return ans+1;
}

int main(){
  vector<vector<int>> testCases = {
    {2,3,1,1,4},
    {2,3,0,1,4}
  };

  for (auto& test : testCases){
    cout << jump(test) << endl;
  }

  return 0;
}
