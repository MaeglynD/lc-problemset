#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
  int total = 1, zc = 0;

  for (int i = 0; i < nums.size(); ++i)
    if (nums[i] == 0)
      zc++; 
    else
      total*=nums[i];
  
  for (int i = 0; i < nums.size(); ++i)
    if (zc > 1)
      nums[i] = 0;
    else if (zc == 1)
      nums[i] = !nums[i] ? total : 0;
    else
      nums[i] = total/nums[i];

  return nums;  
}

int main(){
  vector<vector<int>> testCases = {
    {1,2,3,4},
    {-1,1,0,-3,3}
  };

  for (auto& test : testCases){
    auto res = productExceptSelf(test);
    
    for (auto& x : res)
      cout << x << ", ";

    cout << endl;
  }

  return 0;
}

