#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
  deque<int> dq;
  vector<int> ans; 

  for (int i = 0; i < nums.size(); ++i){
    while (!dq.empty() && nums[dq.front()] <= nums[i])
      dq.pop_front();

    if (!dq.empty() && dq.back() < (i-k)+1)
      dq.pop_back();

    dq.push_front(i);

    if (i >= k-1)
      ans.push_back(nums[dq.back()]);
  }

  return ans;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{1,3,-1,-3,5,3,6,7}, 3},
    {{1}, 1},
    {{1, -1}, 1}
  };

  for (auto& [nums, k] : testCases){
    auto res = maxSlidingWindow(nums, k);

    for (int& n : res)
      cout << n << ", ";

    cout << endl;
  }

  return 0;
}
