#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int eraseOverlapIntervals(vector<vector<int>>& vals) {
  int total = 0, prev = 0;

  sort(vals.begin(), vals.end());

  for (int i = 1; i < vals.size(); ++i) {
    if (vals[i][0] < vals[prev][1]) {
      total++;
      
      if (vals[prev][1] > vals[i][1]) {
        prev = i;
      }
    } else {
      prev = i;
    }
  }

  return total;
}

int main () {
  vector<vector<vector<int>>> testCases = {
    {{1,2},{2,3},{3,4},{1,3}},
    {{1,2},{1,2},{1,2}},
    {{0,2},{1,3},{2,4},{3,5},{4,6}},
  };

  for (auto& test : testCases) {
    cout << eraseOverlapIntervals(test) << endl;
  }

  return 0;
}