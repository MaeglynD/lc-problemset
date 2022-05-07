#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Interval {
  public:
    int start, end;
    Interval(int start, int end) {
      this->start = start;
      this->end = end;
    }
};

// Min heap
int minMeetingRoomsAlt(vector<Interval>& vals) {
  priority_queue<int, vector<int>, greater<int>> pq;
  int total = 1;

  sort(vals.begin(), vals.end(), [](Interval& a, Interval& b){ 
    return a.start < b.start; 
  });

  pq.push(vals[0].end);

  for (int i = 1; i < vals.size(); ++i) {
    if (pq.top() > vals[i].start) {
      total++;
    } else {
      pq.pop();
    }

    pq.push(vals[i].end);
  }

  return total;
}

// 2 vectors way 
int minMeetingRooms(vector<Interval>& vals) {
  vector<int> starts, ends;
  int sptr = 0, eptr = 0, ans = 0, count = 0;
  
  for (Interval& v : vals) {
    starts.push_back(v.start);
    ends.push_back(v.end);
  }
  
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  while (sptr < starts.size()) {
    if (starts[sptr] < ends[eptr]) {
      sptr++;
      count++;
      ans = max(ans, count);
    } else {
      eptr++;
      count--;
    }
  }
  
  return ans;
}

int main () {
  vector<vector<pair<int, int>>> testCases = {
    {{2,3},{2,5},{2,4}},
    {{0,30},{5,10},{15,20}},
    {{2,7}},
    {{65,424},{351,507},{314,807},{387,722},{19,797},{259,722},{165,221},{136,897}},
  };
  
  for (auto& test : testCases) {
    vector<Interval> intervals;

    for (auto& [a, b] : test) 
      intervals.push_back(*new Interval(a, b));

    cout << minMeetingRooms(intervals) << endl;
  }

  return 0;
}