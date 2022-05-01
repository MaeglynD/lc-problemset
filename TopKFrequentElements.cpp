#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Hashmap + priority queue
vector<int> topKFrequentAlt(vector<int>& nums, int k) {
  priority_queue<pair<int, int>> pq;
  unordered_map<int, int> hm;
  vector<int> ans;

  for (int& n : nums) 
    hm[n]++;

  for (auto& [num, freq] : hm)
    pq.push({ freq, num });

  for (int i = 0; i < k; ++i) {
    ans.push_back(pq.top().second);
    pq.pop();
  }

  return ans;
}

// Bucket sort
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> hm;
  vector<vector<int>> bucket(nums.size(), vector<int>());
  vector<int> ans;

  for (int& n : nums)
    hm[n]++;
  
  for(const auto& [num, freq] : hm)
    bucket[freq-1].push_back(num);

  for (int i = bucket.size()-1; i >= 0; --i) {
    for (const int& n : bucket[i]) {
      ans.push_back(n);
      k--;

      if (k == 0) {
        return ans;
      }
    }
  }

  return ans;
}

int main () {
  vector<pair<vector<int>, int>> testCases = {
    {{1,1,1,2,2,3}, 2},
    {{1}, 1}
  };

  for (auto& [nums, k] : testCases) {
    auto res = topKFrequent(nums, k);

    for (auto& x : res)
      cout << x << ", ";

    cout << endl;
  }
  
  return 0;
}