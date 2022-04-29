#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lastStoneWeight(vector<int>& stones) {
  priority_queue<int> pq(stones.begin(), stones.end());

  while (pq.size() > 1) {
    int y = pq.top();
    pq.pop();

    int x = pq.top();
    pq.pop();

    if (x < y) {
      pq.push(y-x);
    }
  }

  return pq.empty() ? 0 : pq.top();
}

int main () {
  vector<vector<int>> testCases = {
    {2,7,4,1,8,1},
    {1}
  };

  for (auto& test : testCases) {
    cout << lastStoneWeight(test) << endl;
  }

  return 0;
}