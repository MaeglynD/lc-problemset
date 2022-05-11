#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums){
  int target = accumulate(nums.begin(), nums.end(), 0);

  if (target % 2)
    return false;
  
  target/=2;

  unordered_set<int> mem = {0};

  for (int& n : nums){
    if (n == target)
      return true;
    
    vector<int> tmp;

    for (const int& mn : mem) {
      if (mn+n == target)
        return true;

      tmp.push_back(mn+n);
    }

    mem.insert(tmp.begin(), tmp.end());
  }

  return false;
}

int main(){
  vector<vector<int>> testCases = {
    {1,5,11,5},
    {1,2,3,5},
    {2,2,1,1},
    {2,2,3,5}
  };

  for (auto& test : testCases){
    cout << canPartition(test) << endl;
  }
  
  return 0;
}
