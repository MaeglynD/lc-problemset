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

bool canAttendMeetings(vector<Interval>& vals) {
  sort(vals.begin(), vals.end(), [](Interval& a, Interval& b){ 
    return a.start < b.start; 
  });

  for (int i = 1; i < vals.size(); ++i) {
    if (vals[i].start < vals[i-1].end)
      return false;
  }

  return true;
}

int main () {
  vector<vector<pair<int, int>>> testCases = {
    {{0,30},{5,10},{15,20}},
    {{5,8},{9,15}}
  };
  
  for (auto& test : testCases) {
    vector<Interval> intervals;

    for (auto& [a, b] : test) 
      intervals.push_back(*new Interval(a, b));

    cout << canAttendMeetings(intervals) << endl;
  }


  return 0;
}