#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& nums){
  int b = -nums[0], s = 0, c = 0;
  
  for (int i = 1; i < nums.size(); ++i){
    int tb = max(b, c-nums[i]);
    int ts = max(s, nums[i]+b);
    int tc = max(c, s);
    
    b = tb;
    s = ts; 
    c = tc;
  }

  return s;
}

// first attempt 
int maxProfitAlt(vector<int>& nums){
  if (nums.size() == 1) 
    return 0;

  int ans = 0, n = nums.size();
  vector<vector<int>> matrix(n+2, vector<int>(n+3, 0));

  for (int i = n-2; i >= 0; --i)
    for (int j = n-1; j > i; --j)
      matrix[i][j] = max(matrix[j+2][j+3] + max(nums[j]-nums[i], 0), max(matrix[i][j+1], matrix[i+1][j]));

  return matrix[0][1];
}

int main(){
  vector<vector<int>> testCases = {
    {1,2,3,0,2},
    {1},
    {2,1,2,0,1},
    {2,1,2,1,0,1,2},
    {1,2,4,2,5,7,2,4,9,0},
    {6,1,6,4,3,0,2}
  };

  for (auto& test : testCases){
    cout << maxProfit(test) << endl;
  }

  return 0;
}
