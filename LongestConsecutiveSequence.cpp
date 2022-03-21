#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int longestConsecutive(vector<int>& nums) {
  int ans = 0;
  unordered_set<int> s(nums.begin(), nums.end());

  for (auto& n : s) {
    if (!s.count(n-1)) {
      int tmp = 1;

      while(s.count(n+tmp)) {
        tmp++;
      }

      ans = max(ans, tmp);
    }
  }
  
  return ans;
}

int main () {
  vector<vector<int>> testCases = {
    {100,4,200,1,3,2},
    {0,3,7,2,5,8,4,6,0,1}
  };

  for (auto& x : testCases) {
    cout << longestConsecutive(x) << endl;
  }

  return 0;
}
