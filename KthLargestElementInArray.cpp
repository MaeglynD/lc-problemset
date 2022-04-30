#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Sort
int findKthLargest(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  return nums[nums.size()-k];
}

// Priority queue
int findKthLargestAlt(vector<int>& nums, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int& n : nums) {
    pq.push(n);

    if (pq.size() > k) {
      pq.pop();
    }
  }

  return pq.top();
}

int partition(vector<int>& nums, int l, int h) {
  for (int i = l; i < h; ++i) {
    if (nums[i] < nums[h]) {
      swap(nums[i], nums[l]);
      l++;
    }
  }

  swap(nums[l], nums[h]);

  return l;
}

// Quick select
void quickselect(vector<int>& nums, int& index, int l, int h) {
  int pi = partition(nums, l, h);

  if (pi != index) {
    if (pi > index) {
      quickselect(nums, index, l, pi-1);
    } else {
      quickselect(nums, index, pi+1, h);
    }
  }
}

int findKthLargestAlt2(vector<int>& nums, int k) {
  int index = nums.size()-k;

  quickselect(nums, index, 0, nums.size()-1);

  return nums[index];
}

int main () {
  vector<pair<vector<int>, int>> testCases = {
    {{3,2,1,5,6,4}, 2},
  };

  for (auto& [nums, k] : testCases) {
    cout << findKthLargestAlt2(nums, k) << endl;
  }

  return 0;
}