#include <bits/stdc++.h>
using namespace std;

int maxProfitAlt(vector<int>& prices){
  int mx = prices[prices.size()-1], ans = 0;
  
  for (int i = prices.size()-2; i >= 0; --i){
    ans = max(ans, mx-prices[i]);
    mx = max(mx, prices[i]);
  }

  return ans;
}

int maxProfit(vector<int>& prices){
  int l = 0, r = 0, ans = 0;

  while (r != prices.size()){
    if (prices[l] < prices[r]){
      ans = max(ans, prices[r]-prices[l]);
    } else {
      l = r;
    }

    r++;
  }

  return ans;
}

int main(){
  vector<vector<int>> testCases = {
    {7,1,5,3,6,4},
    {7,6,4,3,1}
  };

  for (auto& test : testCases)
    cout << maxProfit(test) << endl;

  return 0;
}
