#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> point;

class ComparePoints {
  public:
    bool operator () (const point& a, const point& b) {
      return a.second > b.second;
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  priority_queue<point, vector<point>, ComparePoints> pq;
  vector<vector<int>> ans;

  for (int i = 0; i < points.size(); ++i) {
    pq.push({ i, pow(points[i][0], 2)+pow(points[i][1], 2) });
  }

  while(k--) {
    ans.push_back(points[pq.top().first]);
    pq.pop();
  }

  return ans;
}

int main () {
  vector<pair<vector<vector<int>>, int>> testCases = {
    {{{1,3},{-2,2}}, 1},
    {{{1,3},{-2,2},{2,-2}}, 2},
    {{{3,3},{5,-1},{-2,4}}, 2}
  };

  for (auto& [points, k] : testCases) {
    auto res = kClosest(points, k);

    cout << "[";

    for (auto& p : res) {
      cout << "[" << p[0] << ", " << p[1] << "], ";
    }

    cout << "]" << endl;
  }

  return 0;
}