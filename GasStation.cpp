#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  if (accumulate(cost.begin(), cost.end(), 0) > accumulate(gas.begin(), gas.end(), 0))
    return -1;

  int ans = 0, total = 0;

  for (int i = 0; i < gas.size(); ++i){
    total+=gas[i]-cost[i]; 
    
    if (total < 0){
      ans = i+1;
      total = 0;
    }
  }

  return ans; 
}

int main(){
  vector<pair<vector<int>, vector<int>>> testCases = {
    {{1,2,3,4,5},{3,4,5,1,2}},
    {{2,3,4},{3,4,3}},
    {{3,3,4},{3,4,4}}
  };

  for (auto& [gas, cost] : testCases){
    cout << canCompleteCircuit(gas, cost) << endl;
  }

  return 0;
}
