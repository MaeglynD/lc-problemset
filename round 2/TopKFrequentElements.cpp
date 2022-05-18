#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k){
  vector<int> ans(k);
  unordered_map<int, int> hm;
  priority_queue<pair<int, int>> pq;

  for (int& n : nums)
    hm[n]++;

  for (auto& [k, v] : hm)
    pq.push({ v, k });

  for (int i = 0; i < k; ++i){
    ans[i] = pq.top().second;
    pq.pop();
  }
  
  return ans;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{1,1,1,2,2,3}, 2},
    {{1}, 1}
  };

  for(auto& [nums, k] : testCases){
    auto res = topKFrequent(nums, k);
    
    for (auto& x : res)
      cout << x << ", ";

    cout << endl;
  }
  
  return 0;
}
