#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minCostClimbingStairs(vector<int>& costs) {
  for (int i = 2; i < costs.size(); ++i) {
    int tmp = costs[1];

    costs[1] = costs[i] + min(costs[0], costs[1]);
    costs[0] = tmp;
  }

  return min(costs[0], costs[1]);
}

int main () {
  vector<vector<int>> testCases = {
    {10,15,20},
    {1,100,1,1,1,100,1,1,100,1}
  };

  for (auto& test : testCases) {
    cout << minCostClimbingStairs(test) << endl;
  }

  return 0;
}