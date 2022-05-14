#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& nums, vector<vector<int>>& mem, int& mx, int i, int acc){
  if (mem[i][acc] != -1) 
    return mem[i][acc];

  mem[i][acc] = i == nums.size() 
    ? 0 
    : dfs(nums, mem, mx, i+1, acc+nums[i]) + dfs(nums, mem, mx, i+1, acc-nums[i]);

  return mem[i][acc];
}

int findTargetSumWays(vector<int>& nums, int target){
  int mx = accumulate(nums.begin(), nums.end(), 0, [](int& a, int& b){ 
    return abs(a) + abs(b);
  });

  if (target > mx || -target > mx) 
    return 0;

  vector<vector<int>> mem(nums.size()+1, vector<int>((mx*2)+1, -1));

  mem.back()[mx+target] = 1;
  
  return dfs(nums, mem, mx, 0, mx);
}

class hash_pair {
  public:
    hash<int>hasher;

    size_t operator()(const pair<int, int>& data) const {
      return hasher(data.first) ^ hasher(data.second);
    }
};

int dfsAlt(vector<int>& nums, unordered_map<pair<int, int>, int, hash_pair>& hm, int& target, pair<int, int> data){
  if (hm.count(data))
    return hm[data];

  hm[data] = data.first == nums.size() 
    ? 0
    : dfsAlt(nums, hm, target, {data.first+1, data.second+nums[data.first]}) + dfsAlt(nums, hm, target, {data.first+1, data.second-nums[data.first]});

  return hm[data];
}

// initial solution, maintain state with hashmap of pairs
int findTargetSumWaysAlt(vector<int>& nums, int target){
  unordered_map<pair<int, int>, int, hash_pair> hm = {
    {{nums.size(), target}, 1}
  };

  return dfsAlt(nums, hm, target, {0,0});
}


int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{1,1,1,1,1}, 3},
  };

  for (auto& [nums, target] : testCases){
    cout << findTargetSumWays(nums, target) << endl;
  }

  return 0;
}
