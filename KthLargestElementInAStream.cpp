#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class KthLargest {
  public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int kv, vector<int>& nums) : k(kv) {
      for (int& n : nums) {
        add(n);
      }
    }

    int add(int val) {
      if (pq.size() != k || pq.top() < val) {
        pq.push(val);

        if (pq.size() > k) {
          pq.pop();
        }
      }

      return pq.top();
    }
};

int main () {
  vector<pair<pair<int, vector<int>>, vector<int>>> testCases = {
    {{3, {4,5,8,2}}, {3, 5, 10, 9, 4}},
    {{2, {0}}, {-1, 1, -2, -4, 3}}
  };

  for (auto& [initData, additions] : testCases) {
    KthLargest test(initData.first, initData.second);

    for (auto& n : additions) {
      cout << test.add(n) << endl;
    }

    cout << endl;
  }

  return 0;
}