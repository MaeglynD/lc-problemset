#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxProduct(vector<int>& nums) {
  int mn = 1, mx = 1, ans = nums[0];

  for (int& n : nums) {
    if (n == 0) {
      mn = 1;
      mx = 1;
      ans = max(ans, 0);
    } else {
      int a = mx*n, b = mn*n;
      
      if (a < b) swap (a, b);

      mx = max(n, a);
      mn = min(n, b);
      ans = max(ans, mx);
    }
  }

  return ans;
}


int main () {
  vector<vector<int>> testCases = {
    {2,3,-2,4},
    {-2,0,-1}
  };

  for (auto& test : testCases) {
    cout << maxProduct(test) << endl;
  }

  return 0;
}