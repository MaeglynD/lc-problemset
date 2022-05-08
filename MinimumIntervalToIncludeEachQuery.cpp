#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> minInterval(vector<vector<int>>& vals, vector<int>& queries) {
  auto comp = [](pair<int, int>& a, pair<int, int>& b){ 
    return a.first == b.first ? a.second > b.second : a.first > b.first; 
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
  vector<pair<int, int>> qs;
  int i = 0;

  for (int j = 0; j < queries.size(); ++j) 
    qs.push_back({queries[j], j});

  sort(qs.begin(), qs.end());
  sort(vals.begin(), vals.end(), [](vector<int>& a, vector<int>& b){
    return a[0] < b[0];
  });

  for (auto& [n, index] : qs) {
    while (i < vals.size() && vals[i][0] <= n) {
      pq.push({(vals[i][1]-vals[i][0])+1, vals[i][1]});
      i++;
    }

    while (!pq.empty() && pq.top().second < n)
      pq.pop();

    queries[index] = pq.empty() ? -1 : pq.top().first;
  }

  return queries;
}

int main () {
  vector<pair<vector<vector<int>>, vector<int>>> testCases = {
    {{{1,4},{2,4},{3,6},{4,4}}, {2,3,4,5}},
    {{{2,3},{2,5},{1,8},{20,25}}, {2,19,5,22}},
    {{{9,9},{6,7},{5,6},{2,5},{3,3}}, {6,1,1,1,9}} 
  };

  for (auto& [intervals, queries] : testCases) {
    auto res = minInterval(intervals, queries);

    cout << "[";

    for (auto& n : res) {
      cout << n << ", ";
    }

    cout << "]" << endl;
  } 

  return 0;
}