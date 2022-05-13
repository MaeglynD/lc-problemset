#include <bits/stdc++.h>
using namespace std;

int change(int a, vector<int>& nums){
  int mem[a+1];
  
  fill(mem+1, mem+a+1, 0);
  mem[0] = 1;

  for (int i = 0; i < nums.size(); ++i)
    for (int j = 1; j < a+1; ++j)
      if (j-nums[i] >= 0)
        mem[j]+=mem[j-nums[i]];

  return mem[a];
}

int main(){
  vector<pair<int, vector<int>>> testCases = {
    {5,{1,2,5}},
    {3,{2}}
  };

  for (auto& [a, nums] : testCases){
    cout << change(a, nums) << endl;
  }

  return 0;
}
