#include <bits/stdc++.h>
using namespace std;

// O(n) but awful runtime
int longestConsecutive(vector<int>& nums){
  int ans = 0;
  unordered_set<int> st(nums.begin(), nums.end());

  for (int& n : nums){
    if (!st.count(n-1)){
      int curr = 1;
      n++;

      while(st.count(n++))
        curr++;

      ans = max(ans, curr);
    }
  }

  return ans;
}

// o(nlogn + n)
int longestConsecutiveAlt(vector<int>& nums){
  if (!nums.size())
    return 0;

  int ans = 1, curr = 1;

  sort(nums.begin(), nums.end());
 
  for (int i = 1; i < nums.size(); ++i){
    if (nums[i-1] == nums[i])
      continue;

    if (nums[i-1] == nums[i]-1){
      curr++; 
      ans = max(ans, curr);
    } else {
      curr = 1;
    }
  }

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {100,4,200,1,3,2},
    {0,3,7,2,5,8,4,6,0,1}
  };

  for (auto& test : testCases)
    cout << longestConsecutive(test) << endl;

  return 0;
}
