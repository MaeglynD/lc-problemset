#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool overlaps(vector<int>& a, vector<int>& b) {
  return (a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]);
}

vector<vector<int>> insert(vector<vector<int>>& vals, vector<int>& v) {
  vector<vector<int>> ans;
  int i = 0;

  while (i < vals.size() && vals[i][0] < v[0] && vals[i][1] < v[0]) {
    ans.push_back(vals[i]);
    i++;
  }

  ans.push_back(v);

  while (i < vals.size()) {
    vector<int>& prev = ans.back();
    vector<int>& curr = vals[i];

    if (!overlaps(prev, curr) && !overlaps(curr, prev))
      break;

    prev[0] = min(prev[0], curr[0]);
    prev[1] = max(prev[1], curr[1]);

    i++;
  }

  while (i < vals.size()) {
    ans.push_back(vals[i]);
    i++;
  }

  return ans;
}

int main () {
  vector<pair<vector<vector<int>>, vector<int>>> testCases = {
    {{{1, 3},{6, 9}}, {2, 5}},
    {{{1, 2},{3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}},
    {{{1, 5}}, {0, 6}}
  };

  for (auto& [vals, val] : testCases) {
    auto res = insert(vals, val);

    cout << "[";

    for (auto& x : res)
      cout << "[" << x[0] << ", " << x[1] << "], ";
    
    cout << "]" << endl;
  }

  return 0;
}